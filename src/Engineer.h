/*contains advanced mathematical operations
 *can be updated at anytime with newer 
 *advanced mathematical operations
 */
#ifndef ENGINEER_H
#define ENGINEER_H


#include "Math.h"
#include "History.h"
#include "Integration.h"
#include "Basic_Calculations.h"

class Engineer : public  Parser
{
	public:	
		Engineer();
		~Engineer();
        void Run();  //user interface
		
	private:
	 //basic functions
	 void About();
	 void Help();
	 void Exit();
	 
	 //data members
	 Integration* fIntegration;
	 Basic_Calculations* fBasic_Calculations;
	 History* fHistory;
};

#endif //ENGINEER_H
