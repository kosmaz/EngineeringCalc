#ifndef DIFFERENCIATION_H
#define DIFFERENCIATION_H

#include "Math.h"

class Differenciation : public Parser
{
	friend class Engineer;
	private:
		Differenciation();
		void Run(std::string& user_input);	//interface
		void Help();
};

#endif	//DIFFERENCIATION_H
