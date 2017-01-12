#include "Basic_Calculations.h"
using namespace std;

//O(1)
Basic_Calculations::Basic_Calculations()
{
}

//O(1)
Basic_Calculations::~Basic_Calculations()
{
}

//O(1)
void Basic_Calculations::Run(string &user_input)
{
    string operate=Basic_Parser(user_input);
    if(operate=="radtodeg")Display(RadianToDegree(user_input), "°");  //0xB0
    else if(operate=="degtorad")Display(DegreeToRadian(user_input), " rad(s)");
    else if(operate=="power")Display(Power(user_input),"");
    else if(operate=="add")Display(Add(user_input),"");
    else if(operate=="subtract")Display(Subtract(user_input),"");
    else if(operate=="multiply")Display(Multiply(user_input),"");
    else if(operate=="divide")Display(Divide(user_input),"");
    else if(operate=="factorial")Display(Factorial(user_input),"");
    else if(operate=="permutate")Display(Permutate(user_input),"");
    else if(operate=="combinate")Display(Combinate(user_input),"");
    else if(operate=="root")Display(Root(user_input),"");
    else if(operate=="calc")Help();
    else if(operate=="0")return;
    else
     {
    cout<<"Invalid Command!\a\nEnter the HELP command to get a list of all the valid";
    cout<<" commands supported by the program\n\a";
     }
	return;
}

//0(1)
void Basic_Calculations::Help()
{
	clearscreen();
	cout<<"\t\tList of functions supported by the calc command\n";
	cout<<"-calc(radtodeg(x))/CALC(RADTODEG(x)): converts the radian value x to degrees\n";
	cout<<"-calc(degtorad(x))/CALC(DEGTORAD)x)): converts the degree value x to radians\n";
	cout<<"-calc(power(x,y))/CALC(POWER(x,y)): raises the value x to the power of y\n";
	cout<<"-calc(factorial(x))/CALC(FACTORIAL(x)): gets the factorial value of x; x!\n";
	cout<<"-calc(add(x,y))/CALC(ADD(x,y)): adds the value y to x\n";
	cout<<"-calc(subtract(x,y))/CALC(SUBTRACT(x,y)): subtracts the value y from x\n";
	cout<<"-calc(divide(x,y))/CALC(DIVIDE(x,y)): divides the value x by y\n";
	cout<<"-calc(multiply(x,y))/CALC(MULTIPLY(x,y)): multiplies the value y to x\n"; 
	pausescreen();
	return;
}

//O(1)
template<typename value>
inline void Basic_Calculations::Display(const value& answer, const string& unit)
{
    clearscreen();
    if(error==true)
    {
    	cout<<"syntax error!\n\a";
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

//O(N^6)
long double Basic_Calculations::RadianToDegree(string& user_input)
{
		long double variable=numeric_value(user_input);
		variable*=360;
		variable/=(2*pi);
    return variable;
}

//O(N^6)
long double Basic_Calculations::DegreeToRadian(std::string& user_input)
{
		long double variable=numeric_value(user_input);
		variable*=(2*pi);
		variable/=360;
    return variable;
}

//O(N^6)
long double Basic_Calculations::Power(string& user_input)
{ 
	string power=one_comma(user_input);
  if(user_input[0]=='-')
  {
  	long double result=pow((numeric_value(user_input)*-1),numeric_value(power));
  	return (result*-1);
  }
  return pow(numeric_value(user_input),numeric_value(power));
}

//O(N^6)
long double Basic_Calculations::Add(string& user_input)
{
	string add=one_comma(user_input);
	long double result=numeric_value(user_input)+numeric_value(add);
	return result;
}

//O(N^6)
long double Basic_Calculations::Subtract(string& user_input)
{
	string subtract=one_comma(user_input);
	long double result=numeric_value(user_input)-numeric_value(subtract);
	return result;
}

//O(N^6)
long double Basic_Calculations::Multiply(string& user_input)
{
	string multiplier=one_comma(user_input);
	long double result=numeric_value(user_input)*numeric_value(multiplier);
	return result;
}

//O(N^6)
long double Basic_Calculations::Divide(string& user_input)
{
	string divider=one_comma(user_input);
	long double result=numeric_value(user_input)/numeric_value(divider);
	return result;
}

//O(N^6)
long double Basic_Calculations::Factorial(string& user_input)
{
	for(unsigned i=0; i<user_input.size(); ++i)
  {
   	if(!isdigit(user_input[i]))
    {
      //cout<<"syntax error...bc_factorial!\n\a";
      //pausescreen();
        error=true;
        return 0.0;
    }
  }
  long value=(long)numeric_value(user_input);
  long double number=Factorial(value);
  return number;
}

//O(N)
long double Basic_Calculations::Factorial(long factor)
{
	long double number=(long double)factor;
	int new_value=number-1;
  while(new_value!=0)
  {
  	number*=new_value;
  	new_value-=1;
  }
  return number;
}

//0(N^6)
long double Basic_Calculations::Permutate(string& user_input)
{
	string r=one_comma(user_input);
	if(numeric_value(user_input)<numeric_value(r))
	{
		cout<<"Math Error!\n\a";
		error=true;
		pausescreen();
		return 0.0;
	}
	long double numerator=Factorial((long)numeric_value(user_input));
	long double denominator=Factorial((long)(numeric_value(user_input)-numeric_value(r)));
	long double result=numerator/denominator;
	return result;
}

//O(N^6)
long double Basic_Calculations::Combinate(string& user_input)
{
	string temp_str=user_input;
	long double numerator=Permutate(user_input);
  string r=one_comma(temp_str);
	long double denominator=Factorial(r);
	long double result=numerator/denominator;
	return result;	
}

//O(N^6)
long double Basic_Calculations::Root(string& user_input)
{
	return (sqrt(numeric_value(user_input)));
}
