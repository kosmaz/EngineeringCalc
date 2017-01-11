#include "Parser.h"
#include "Math.h"
#include <math.h>
using namespace std;


string Parser::Engineer_Run_Parser(string& user_input)
{
    if(user_input.size()==0)
        return " ";

    bool error=parsing_check(user_input);
    if(error==false)
    {
        return "error";
    }

    string temp_str;
    string temp_u_input;

    for(unsigned int i=0; i<user_input.size(); i++)
    {
        if(isalpha(user_input[i]))
            if(isupper(user_input[i]))
                user_input[i]=tolower(user_input[i]);
    }

    for(unsigned int j=0; j<user_input.size(); j++)
    {
        if(user_input[j]=='(')
        {
            for(unsigned int k=j+1, m=0; k<user_input.size()-1; m++,k++)
                temp_u_input.insert(m, 1, user_input[k]);
            user_input=temp_u_input;
            return temp_str;
        }
        temp_str.insert(j, 1, user_input[j]);
    }
    return temp_str;
}

string Parser::BC_Run_Parser(string& user_input)
{
    string temp_str;
    string temp_u_input;

    for(unsigned int j=0; j<user_input.size(); j++)
    {
        if(user_input[j]=='(')
        {
            for(unsigned int k=j+1, m=0; k<user_input.size()-1; m++,k++)
                temp_u_input.insert(m, 1, user_input[k]);
            user_input=temp_u_input;
            return temp_str;
        }
        temp_str.insert(j, 1, user_input[j]);
    }
    return temp_str;
}

long double Parser::numeric_value(string& user_input, unsigned level)
{
    if(user_input.size()==0 && level==0)
        return 0.0;
    if(user_input.size()==0 && level==1)
        return 1.0;
    if(user_input.size()==1 && user_input[0]=='e')
    {
        cout<<"syntax error...parser_1c\n";
        pausescreen();
        return 0.0;
    }
    if(level==2)
    {
        for(unsigned n=0; n<user_input.size(); n++)
            if(user_input[n]=='.')
            {
                cout<<"syntax error...parser_1d\n";
                pausescreen();
                return 0.0;
            }
    }

    for(unsigned i=0; i<user_input.size(); i++)
    {
        if(!isdigit(user_input[i]) && user_input[i]!='π' && user_input[i]!='.' && user_input[i]!='-' && user_input[i]!='e')
        {
            cout<<"syntax error...parser_1a\n";
            pausescreen();
            return 0.0;
        }

        unsigned exp_count=0;
        if(user_input[i]=='e')exp_count++;
        if(exp_count>1)
        {
            cout<<"syntax error...parser_1b\n";
            pausescreen();
            return 0.0;
        }
    }

    for(unsigned k=0; k<user_input.size(); k++)
    {
        if(user_input[k]=='e')
        {
            string exponent;
            for(unsigned l=k+1,m=0; l<user_input.size(); m++,l++)
                exponent.insert(m, 1, user_input[l]);
            user_input.erase(k);
            long double main=numeric_value(user_input, 1);
            long double expo=numeric_value(exponent, 2);
            long double final_value=main*pow(10, expo);
            return final_value;
        }
    }

    long double number=0.0;
    unsigned count=0;
    for(unsigned j=0; j<user_input.size(); j++)
    {
        if(user_input[j]=='π')
        {
            if(user_input.size()==1)
                return pi;
            count++;
            for(unsigned k=j; k<user_input.size(); k++)
                user_input.insert(k,1,user_input[k+1]);
        }
        number=stold(user_input)*(pow(pi, count));
    }
    number=stold(user_input);

    return number;
}

long double Parser::stold(const string &input) const
{
    bool error=syntax_check(input);
    if(error==false)
        return 0.0;

    long double result=0.0;
    long double real=0.0;
    long double imaginary=0.0;
    
    if(input.size()==1 && input[0]==0)
        return 0.0;

    else
        if(input[0]=='-' && input[1]=='0' && input[2]=='.')
        {
            unsigned count=0;
            for(unsigned i=3; i<input.size(); i++)
            {
                imaginary*=10;
                imaginary+=reset_value(input[i]);
                count++;
            }
            double power=pow(10,count);
            imaginary/=power;
            imaginary*=-1;
            result=imaginary;
        }

        else
            if(input[0]=='0' && input[1]=='.')
            {
                unsigned count=0;
                for(unsigned i=2; i<input.size(); i++)
                {
                    imaginary*=10;
                    imaginary+=reset_value(input[i]);
                    count++;
                }
                double power=pow(10,count);
                imaginary/=power;
                result=imaginary;
            }

            else
                if(input[0]=='-' && input[1]!='0' && input[1]!='.')
                {
                    for(unsigned j=1; j<input.size(); j++)
                    {
                        if(input[j]=='.')
                        {
                            unsigned count=0;
                            for(unsigned k=j+1; k<input.size(); k++)
                            {
                                imaginary*=10;
                                imaginary+=reset_value(input[k]);
                                count++;
                            }
                            double power=pow(10,count);
                            imaginary/=power;
                            result=real+imaginary;
                            return result*=-1;
                        }
                        real*=10;
                        real+=(long double)reset_value(input[j]);
                    }
                    real*=-1;
                    result=real;
                }

                else
                    if(input[0]!='-' && input[0]!=0 && input[0]!='.')
                    {
                        for(unsigned j=0; j<input.size(); j++)
                        {
                            if(input[j]=='.')
                            {
                                unsigned count=0;
                                for(unsigned k=j+1; k<input.size(); k++)
                                {
                                    imaginary*=10;
                                    imaginary+=reset_value(input[k]);
                                    count++;
                                }
                                double power=pow(10,count);
                                imaginary/=power;
                                result=real+imaginary;
                                return result;
                            }
                            real*=10;
                            real+=(long double)reset_value(input[j]);
                        }
                        result=real;
                    }

                    else
                    {
                        cout<<"syntax error...parser_3\n";
                        pausescreen();
                        return 0.0;
                    }
    return result;
}

bool Parser::syntax_check(const string& container)const
{
    unsigned stop_count=0;
    unsigned dash_count=0;

    for(unsigned i=0; i<container.size(); i++)
    {
        if(container[i]=='-')
            dash_count++;
        if(container[i]=='.')
            stop_count++;
        if(container[i]=='-' && i!=0)
        {
            cout<<"syntax error...parser_2\n";
            pausescreen();
            return false;
        }
    }

    if(stop_count>1 || dash_count>1)
    {
        cout<<"syntax error...parser_2\n";
        pausescreen();
        return false;
    }
    return true;
}

inline unsigned Parser::reset_value(const char& input) const
{
    if(input=='0')return 0;
    else if(input=='1')return 1;
    else if(input=='2')return 2;
    else if(input=='3')return 3;
    else if(input=='4')return 4;
    else if(input=='5')return 5;
    else if(input=='6')return 6;
    else if(input=='7')return 7;
    else if(input=='8')return 8;
    else if(input=='9')return 9;
    else
    {
        cout<<"syntax error...parser_4\n";
        pausescreen();
        return 99999;
    }
}

bool Parser::parsing_check(const string &check) const
{
    unsigned open=0;
    unsigned close=0;
    for(unsigned i=0; i<check.size(); i++)
    {
        if(check[i]=='(')open++;
        if(check[i]==')')close++;
    }
    if(open!=close)
    {
        cout<<"parsing error...1\n";
        pausescreen();
        return false;
    }
    return true;
}
