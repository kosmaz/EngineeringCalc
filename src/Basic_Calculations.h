//basic math/engineering operations
#ifndef BASIC_CALCULATIONS_H
#define BASIC_CALCULATIONS_H

#include "Math.h"

class Basic_Calculations : public Parser
{
	friend class Engineer;
	private:
		Basic_Calculations();
		~Basic_Calculations();
		void Run(std:: string& user_input); //interface

        //*************************************************************************//
				template<typename value>
        inline void Display(const value& answer, const std::string& unit);  //display
        //************************************************************************//

        long double RadianToDegree(std::string& user_input);  //radian to degree conversion
				long double DegreeToRadian(std::string& user_input) ;  //degree to radian conversion
				long double Power(std::string& user_input);   //power of variable
				long double Add(std::string& user_input);  //addition
				long double Subtract(std::string& user_input);  //subtraction
				long double Multiply(std::string& user_input);  //multiplication
				long double Divide(std::string& user_input);  //division
				long double Factorial(std::string& user_input);  //factorial
				long double Factorial(long factor);  //factorial
				long double Permutate(std::string& user_input);  //permutation
				long double Combinate(std::string& user_input);  //combination
				long double Root(std::string& user_input);  //square root
				
				void Help(); 
		
		//data member
};

#endif //BASIC_CALCULATIONS_H
