#include "Basic_Calculations.h"
using namespace std;

Basic_Calculations::Basic_Calculations()
{
}

Basic_Calculations::~Basic_Calculations()
{
}

void Basic_Calculations::Run(string &user_input)
{
    string operate=BC_Run_Parser(user_input);
    if(operate=="radtodeg")Display(RadianToDegree(numeric_value(user_input)), "°");  //0xB0
    else if(operate=="degtorad")Display(DegreeToRadian(numeric_value(user_input)), " rad(s)");
    else if(operate=="power")Display(power(user_input)," no unit");
    else
    {
        cout<<"Invalid Command.\nEnter the HELP command to get a list of all the valid";
        cout<<" commands supported by the program\n";
    }
    return;
}

template<typename value>
inline void Basic_Calculations::Display(const value& answer, const string& unit)const
{
    system("cls");
    cout<<"Ans:\n";
    cout<<'\t'<<answer<<unit<<endl;
    system("pause");
    return;
}

long double Basic_Calculations::RadianToDegree(long double variable)
{
    variable*=360;
    variable/=(2*pi);
    return variable;
}

long double Basic_Calculations::DegreeToRadian(long double variable)
{
    variable*=(2*pi);
    variable/=360;
    return variable;
}

long double Basic_Calculations::power(string& user_input)
{ 
    unsigned comma_count=0;
    for(unsigned i=0; i<user_input.size(); i++)
    {
        if(user_input[i]==',')comma_count++;
        if(!isdigit(user_input[i]) && user_input[i]!='π' && user_input[i]!='.' && user_input[i]!='-' && user_input[i]!=',')
        {
            cout<<"syntax error...bc_power_1\n";
            pausescreen();
            return 0.0;
        }
    }

    if(comma_count>1)
    {
        cout<<"syntax error...bc_power_2\n";
        pausescreen();
        return 0.0;
    }

    string power;
    for(unsigned k=0; k<user_input.size(); k++)
    {
        if(user_input[k]==',')
        {
            for(unsigned l=k+1,m=0; l<user_input.size(); m++,l++)
                power.insert(m, 1, user_input[l]);
            user_input.erase(k);
        }
    }

    if(user_input[0]=='-')
    {
        long double result=pow((numeric_value(user_input)*-1),numeric_value(power));
        return (result*-1);
    }

    return pow(numeric_value(user_input),numeric_value(power));
}
