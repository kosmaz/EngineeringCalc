/*semi-virtual dynamic array with growing capabilities(c++ essentials) for storing
 *history records/log files of the operations performed by the program
 */
#ifndef HISTORY_H
#define HISTORY_H

#include "Math.h"

class History : public Parser
{
     public:
	 		History(int size = 10, int inc = 5);
 	    ~History();
			void *Nth(int n) const;
			void Append(void *item);
			void *Remove(int itempos);
	 	  void Grow(int amount);
			std::string* Run(std::string& user_input);
			void clear();
		 	void display();
		 	void Help();
			     					 
     private:
			 int fNum;
			 int fSize;
			 int fCSize;
			 int fInc;
			 void **fItems;
};

#endif	 //HISTORY_H			  
