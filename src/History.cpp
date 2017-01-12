#include "History.h"
using namespace std;

int kLARGE;
int kINCL;

#define kLARGE 10000
#define kINCL 5000 

//O(1)
History::History(int size, int inc)
{
   assert((size > 1) && (size < kLARGE));
	 assert((inc > 1) && (inc < kINCL));
	 fNum = 0;
	 fCSize = fSize = size;
	 fInc = inc;
	 fItems = new void* [size];
}

//O(1)
History::~History()
{
     delete []fItems;
}

//O(1)
void *History::Nth(int n) const
{
 	 if((n < 1) || (n > fNum))
	 return NULL;
	 --n;
	 return fItems[n];
}

//O(1)
void History::Append(void *item)
{
 	 if(fNum == fCSize)
	 Grow(fInc);
	 fItems[fNum] = item;
	 ++fNum;
}

//O(N)
void History::Grow(int delta)
{
 	 int newsize = fCSize + delta;
	 void **temp = new void* [newsize];
	 fCSize = newsize;
	 for(int i=0;i < fNum; ++i)
	   temp[i] = fItems[i];
	 delete [] fItems;
	 fItems = temp;
}

//O(N)
void *History::Remove(int itempos)
{
 	 if((itempos < 1) || (itempos > fNum))
	 return NULL;
	 --itempos;
	 void *tmp = fItems[itempos];
	 for(int i = itempos + 1; i < fNum; ++i)
	 fItems[i-1] = fItems[i];
	 --fNum;
	 if((fNum > fSize) && (fNum < (fCSize / 2)))
	 Grow(-fInc);
     return tmp;
}


//O(N^6)
string* History::Run(string& user_input)
{
 if(user_input=="history"){Help(); return 0;}
 
 if(user_input=="display"){display(); return 0;}
 
  for(unsigned j=0; j<user_input.size(); ++j)
  	if(!isdigit(user_input[j]))
 	  {
 		 cout<<"syntax error...history\n\a";
     pausescreen();
     return 0;
   	}
 	return ((string*)Nth(((int)numeric_value(user_input))));
}

//O(N)
void History::clear()
{
 int i=fNum;
 while(i!=0)
 {
    string* rem=(string*)Remove(i);
    delete rem;
    --i;
 }
}

//O(N^2)
void History::display()
{
 clearscreen();
 cout<<"History log:\n";
 for(int i=1; i<fNum+1; ++i)
 {
 	  string str;
 		for(unsigned k=0; k< ((string*)Nth(i))->size(); ++k)
 			str.insert(k,1,((string*)Nth(i))->at(k));
    cout<<i<<".\t"<<str<<endl;
 }
    pausescreen();
    return;
}

//O(1)
void History::Help()
{
	clearscreen();
	cout<<"\t\tList of supported commands using the history function\n";
	cout<<"-history(display)/HISTORY(DISPLAY): displays the history log of all users input\n";
	cout<<"-clear: clears the history log\n";
	cout<<"-history(x): re-runs the operation for a user input of log number x; where x is an integer\n value for an operation number on the history log\n";
	pausescreen();
	return;
}