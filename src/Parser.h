/*works with the engineer object
 *for parsing user input strings 
 *and returning a call to the approriate
 *auxilliary engineer function
 */
#ifndef PARSER_H
#define PARSER_H


#include <string>

class Parser
{
    protected:
        //***********************************************//
        //string to number
        bool syntax_check(const std::string& container)const;
        long double stold(const std::string& input)const;
        inline unsigned reset_value(const char& input)const;
        long double numeric_value(std::string& user_input, unsigned level=0);
        //**********************************************//

        //parsing check
        bool parsing_check(const std::string& check)const;

        //run parser function
				std::string Engineer_Run_Parser(std::string& user_input);	

				//integrate parser function		
		
				//basic caluculations parser
				std::string BC_Run_Parser(std::string& user_input);

        //data members
};


#endif //PARSER_H
