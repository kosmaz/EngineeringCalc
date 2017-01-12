#include "Parser.h"
#include "Math.h"
using namespace std;

//O(1)
Parser::Parser()
{
	error=false;
}

//O(1)
Parser::~Parser()
{
}

//O(N^2)
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
		
	for(unsigned int i=0; i<user_input.size(); ++i)
		{
			if(isalpha(user_input[i]))
				if(isupper(user_input[i]))
					user_input[i]=tolower(user_input[i]);
		}

	for(unsigned int j=0; j<user_input.size(); ++j)
		{
			if(user_input[j]=='(')
				{
					if(user_input[j]=='(' && user_input[j+1]==')')
					{
						 cout<<"parsing error...2!\n\a";
        		 pausescreen();
        		 return "0";
					}
          for(unsigned int k=j+1, m=0; k<user_input.size()-1; ++m,++k)
							temp_u_input.insert(m, 1, user_input[k]);
					user_input=temp_u_input;	
					return temp_str;
				}	
			temp_str.insert(j, 1, user_input[j]);
		}
	return temp_str;	
}

//O(N^2)
string Parser::Basic_Parser(string& user_input)
{
	string temp_str;
	string temp_u_input;

	for(unsigned int j=0; j<user_input.size(); ++j)
		{
        if(user_input[j]=='(')
				{
					if(user_input[j]=='(' && user_input[j+1]==')')
					{
						 cout<<"parsing error...3!\n\a";
        		 pausescreen();
        		 return "0";
					}
					for(unsigned int k=j+1, m=0; k<user_input.size()-1; ++m,++k)
							temp_u_input.insert(m, 1, user_input[k]);
					user_input=temp_u_input;	
					return temp_str;
				}
			temp_str.insert(j, 1, user_input[j]);
		}
	return temp_str;
}

//O(N^6)
long double Parser::numeric_value(string& user_input, unsigned level)
{
		if(user_input.size()==0 && level==0)
					return 0.0;
		if(user_input.size()==0 && level==1)
					return 1.0;
					
	/*************************************************
	 *if(user_input.size()==1 && user_input[0]=='e')
	 *{
   * 	 		//cout<<"syntax error...parser_3(num)!\n\a";
   *      //pausescreen();
   *      error=true;
   *      return 0.0;
   *}
   */
    
    if(level==2)
    {
    	for(unsigned n=0; n<user_input.size(); ++n)
    			if(user_input[n]=='.')
    			{
    				//cout<<"syntax error...parser_4(num)!\n\a";
            //pausescreen();
            error=true;
            return 0.0;
    			}
    }
   	
 	  unsigned exp_count=0; 	
    for(unsigned i=0; i<user_input.size(); ++i)
    {
        if(!isdigit(user_input[i]) && user_input[i]!='p' && user_input[i]!='.' && user_input[i]!='-' && user_input[i]!='e')
            {
                //cout<<"syntax error...parser_2(num)!\n\a";
                //pausescreen();
                error=true;
                return 0.0;
            }
           
        	if(user_input[i]=='p')
        		if(i!=user_input.size()-1)
        		{
        			 //cout<<"syntax error...parser_5(num)!\n\a";
               //pausescreen();
                error=true;
                return 0.0;
        		}
            
        	if(user_input[i]=='e')++exp_count;  
       		  if(exp_count>1)
       			{
        	      //cout<<"syntax error...parser_1(num)!\n\a";
                //pausescreen();
                error=true;
                return 0.0;
        		}
    }
     
    for(unsigned k=0; k<user_input.size(); ++k)
    {
    	if(user_input[k]=='e')
    	{
    		string exponent;
    		for(unsigned l=k+1,m=0; l<user_input.size(); ++m,++l)
    				exponent.insert(m, 1, user_input[l]);
    		user_input.erase(k);
    		long double main=numeric_value(user_input, 1);
    		long double expo=numeric_value(exponent, 2);
    		long double final_value=main*pow(10, expo);
    		return final_value;
    	}
    }

    long double number=0.0;
    if(user_input[user_input.size()-1]=='p')
      {
      	if(user_input.size()==1)
      			return pi;
      	else
      	{
      		user_input.erase(user_input.size()-1);
      		return number=stold(user_input)*pi;      			
      	}
      }
    return number=stold(user_input);
}

//O(N^2)
long double Parser::stold(const string &input)
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
        for(unsigned i=3; i<input.size(); ++i)
        {
            imaginary*=10;
            imaginary+=(long double)(input[i]-48);
            ++count;
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
        for(unsigned i=2; i<input.size(); ++i)
        {
            imaginary*=10;
            imaginary+=(long double)(input[i]-48);
            ++count;
        }
        double power=pow(10,count);
        imaginary/=power;
        result=imaginary;
    }

    else
    if(input[0]=='-' && input[1]!='0' && input[1]!='.')
    {
        for(unsigned j=1; j<input.size(); ++j)
        {
            if(input[j]=='.')
            {
                unsigned count=0;
                for(unsigned k=j+1; k<input.size(); ++k)
                {
                    imaginary*=10;
                    imaginary+=(long double)(input[j]-48);
                    ++count;
                }
                double power=pow(10,count);
                imaginary/=power;
                result=real+imaginary;
                return result*=-1;
            }
            real*=10;
            real+=(long double)(input[j]-48);
        }
        real*=-1;
        result=real;
    }

    else
    if(input[0]!='-' && input[0]!=0 && input[0]!='.')
    {
        for(unsigned j=0; j<input.size(); ++j)
        {
            if(input[j]=='.')
            {
                unsigned count=0;
                for(unsigned k=j+1; k<input.size(); ++k)
                {
                    imaginary*=10;
                    imaginary+=(long double)(input[j]-48);
                    ++count;
                }
                double power=pow(10,count);
                imaginary/=power;
                result=real+imaginary;
                return result;
            }
            real*=10;
            real+=(long double)(input[j]-48);
        }
        result=real;
    }

    else
    {
        //cout<<"syntax error...parser_stold!\n\a";
        //pausescreen();
        error=true;
        return 0.0;
    }
    return result;
}

//O(N)
bool Parser::syntax_check(const string& container)
{
    unsigned stop_count=0;
    unsigned dash_count=0;

    for(unsigned i=0; i<container.size(); ++i)
    {
        if(container[i]=='-')
            ++dash_count;
        if(container[i]=='.')
            ++stop_count;
        if(container[i]=='-' && i!=0)
        {
            //cout<<"syntax error...parser_1(synchk)!\n\a";
            //pausescreen();
            error=true;
            return false;
        }
    }

    if(stop_count>1 || dash_count>1)
    {
        //cout<<"syntax error...parser_2(synchk)!\n\a";
        //pausescreen();
        error=true;
        return false;
    }
    return true;
}

//O(N)
bool Parser::parsing_check(const string &check)const
{
    unsigned open=0;
    unsigned close=0;
    for(unsigned i=0; i<check.size(); ++i)
    {
        if(check[i]=='(')++open;
        if(check[i]==')')++close;
    }
    if(open!=close)
    {
        cout<<"parsing error...1!\n\a";
        pausescreen();
        return false;
    }
    return true;
}

//O(N^2)
string Parser::one_comma(string& side_1)
{
	unsigned comma_count=0;
	for(unsigned i=0; i<side_1.size(); ++i)
	{
		if(side_1[i]==',')++comma_count;
		if(!isdigit(side_1[i]) && side_1[i]!='p' && side_1[i]!='.' && side_1[i]!='-' && side_1[i]!=',')
    {
     	//cout<<"syntax error...parser_onecomma_1!\n\a";
      //pausescreen();
      error=true;
      return "\0";
    }
	}

	if(comma_count>1)
	{
    //cout<<"syntax error...parser_onecomma_2!\n\a";
    //pausescreen();
    error=true;
    return "\0";
  }

  string side_2;
  for(unsigned k=0; k<side_1.size(); ++k)
  {
    if(side_1[k]==',')
    {
    	for(unsigned l=k+1,m=0; l<side_1.size(); ++m,++l)
    			side_2.insert(m, 1, side_1[l]);
    	side_1.erase(k);
    }
  }
  return side_2;
}

//0(N^2)
string Parser::two_comma(string& side_1, std::string& side_2)
{
	unsigned comma_count=0;
	for(unsigned i=0; i<side_1.size(); ++i)
	{
		if(side_1[i]==',')++comma_count;
		if(!isdigit(side_1[i]) && side_1[i]!='p' && side_1[i]!='.' && side_1[i]!='-' && side_1[i]!=',')
    {
     	//cout<<"syntax error...parser_twocomma_1!\n\a";
      //pausescreen();
      error=true;
      return "\0";
    }
	}

	if(comma_count>2)
	{
    //cout<<"syntax error...parser_twocomma_2!\n\a";
    //pausescreen();
    error=true;
    return "\0";
  }

  string side_3;
  for(unsigned k=0; k<side_1.size(); ++k)
  {
    if(side_1[k]==',')
    {
    	for(unsigned l=k+1,m=0; l<side_1.size(); ++m,++l)
    			side_2.insert(m, 1, side_1[l]);
    	side_1.erase(k);
    	break;
    }
  }
  
  for(unsigned j=0; j<side_2.size(); ++j)
  {
  	if(side_2[j]==',')
  	{
  		for(unsigned x=j+1,n=0; x<side_2.size(); ++n,++x)
    			side_3.insert(n, 1, side_2[x]);
    	side_2.erase(j);
    	break;
  	}
  }
  return side_3;
}

//O(N^2)
string Parser::three_comma(string& side_1, std::string& side_2, std::string& side_3)
{
	unsigned comma_count=0;
	for(unsigned i=0; i<side_1.size(); ++i)
	{
		if(side_1[i]==',')++comma_count;
		if(!isdigit(side_1[i]) && side_1[i]!='p' && side_1[i]!='.' && side_1[i]!='-' && side_1[i]!=',')
    {
     	//cout<<"syntax error...parser_threecomma_1!\n\a";
      //pausescreen();
      error=true;
      return "\0";
    }
	}

	if(comma_count>3)
	{
    //cout<<"syntax error...parser_threecomma_2!\n\a";
    //pausescreen();
    error=true;
    return "\0";
  }

  string side_4;
  for(unsigned k=0; k<side_1.size(); ++k)
  {
    if(side_1[k]==',')
    {
    	for(unsigned l=k+1,m=0; l<side_1.size(); ++m,++l)
    			side_2.insert(m, 1, side_1[l]);
    	side_1.erase(k);
    	break;
    }
  }
  
  for(unsigned j=0; j<side_2.size(); ++j)
  {
  	if(side_2[j]==',')
  	{
  		for(unsigned x=j+1,n=0; x<side_2.size(); ++n,++x)
    			side_3.insert(n, 1, side_2[x]);
    	side_2.erase(j);
    	break;
  	}
  }
  
  for(unsigned h=0; h<side_3.size(); ++h)
  {
  	if(side_3[h]==',')
  	{
  		for(unsigned y=h+1,o=0; y<side_3.size(); ++o,++y)
    			side_4.insert(o, 1, side_3[y]);
    	side_3.erase(h);
    	break;
  	}
  }
  return side_4;
}