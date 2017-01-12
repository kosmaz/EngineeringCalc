#include "Integration.h"
using namespace std;

//O(1)
Integration::Integration()
{
}

//O(1)
Integration::~Integration()
{
}

//O(unknown)
void Integration::Run(string& user_input)
{
	cout<<"coming soon\n";
	return;
}

//O(1)
template<typename value>
inline void Integration::Display(const value& answer, const string& unit)
{
    clearscreen();
    if(error==true)
    {
    	cout<<"syntax error\n\a";
    	error=false;
    	pausescreen();
    }
    else
    {
    	cout<<"Ans:\n";
   	  cout<<'\t'<<answer<<unit<<endl;
    	pausescreen();
    }
	return;
}
