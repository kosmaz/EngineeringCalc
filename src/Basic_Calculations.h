//basic math/engineering operations
#ifndef BASIC_CALCULATIONS_H
#define BASIC_CALCULATIONS_H

#include "Math.h"
#include "Parser.h"

class Basic_Calculations : public Parser
{
	friend class Engineer;
	private:
		Basic_Calculations();
		~Basic_Calculations();
		void Run(std:: string& user_input); //interface

        //*************************************************************************//
				template<typename value>
        inline void Display(const value& answer, const std::string& unit) const;  //display
        //************************************************************************//

        long double RadianToDegree(long double variable);  //radian to degree conversion
				long double DegreeToRadian(long double variable);  //degree to radian conversion
				long double power(std::string& user_input);   //power of variable
		
		//data member
};

#endif //BASIC_CALCULATIONS_H
