/*all math/engineeringintegration 
 *operations are defined here
 */
#ifndef INTEGRATION_H
#define INTEGRATION_H
 
#include "Math.h"
#include "Parser.h"

class Integration : public Parser
{
	friend class Engineer;
	private:
		Integration();
		~Integration();

		void Run(std::string& user_input); //interface

        //************************************************************//
		template<typename value>
        inline void Display(const value& answer, const std::string& unit) const;
        //***********************************************************//
		
        //data members
};

#endif //INTEGRATION_H
