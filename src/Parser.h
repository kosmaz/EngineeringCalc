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
    		Parser();
    		virtual ~Parser();
        //*******************************************************************//
        //string to number
        bool syntax_check(const std::string& container);
        long double stold(const std::string& input);
        long double numeric_value(std::string& user_input, unsigned level=0);
        //*******************************************************************//
			
				//*******************************************************************//
				//comma parsing
				std::string one_comma(std::string& side_1);
				std::string two_comma(std::string& side_1, std::string& side_2);
				std::string three_comma(std::string& side_1, std::string& side_2, std::string& side_3);
				//*******************************************************************//
				
        bool parsing_check(const std::string& check)const;  //parsing check
				std::string Engineer_Run_Parser(std::string& user_input);	 //run parser function
				std::string Basic_Parser(std::string& user_input);  //basic parser

        //data members
        bool error;
};


#endif //PARSER_H
