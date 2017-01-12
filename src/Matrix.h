#ifndef MATRIX_H
#define MATRIX_H

#include "Math.h"
#include <vector>

class Matrix : public Parser
{
	friend class Engineer;
	private:
		Matrix();
	  void Run(std::string&);	//interface	
	  void Help();
	  void add();
	  void subtract();
	  void multiply();
	  void scalarMultiply();
	  void determinant();
	  void inverse();
	  void transpose();
	  void subTranspose();
	  
	  struct info{int row=0, col=0; std::vector<std::vector<float>*>* matrix;}; 	  
	  struct ans{int row=0, col=0; std::vector<std::vector<float>*>* matrix;};
	  
	  void getValues(std::string,unsigned nos=0);
	  void destroyValues();
	  void destroyAns();
	  void printAns();
	  inline bool compatible(int which=0);
	  
	  std::vector<info*>* fWork_On;
	  ans* fAns;
	  bool fError;
	  
};

inline bool Matrix::compatible(int which)
{
	bool ret=true;
	if(which==0)
	{
		for(unsigned i=0; i<fWork_On->size()-1; ++i)
		{
			if(fWork_On->at(i)->row!=fWork_On->at(i+1)->row)
			{
				ret=false;
				break;
			}
			if(fWork_On->at(i)->col!=fWork_On->at(i+1)->col)
			{
				ret=false;
				break;
			}
		}
	}
	else
	{
		for(unsigned i=0; i<fWork_On->size()-1; ++i)
		{
			if(fWork_On->at(i)->col!=fWork_On->at(i+1)->row)
			ret=false;
			break;			
		}		
	}
	return ret;
}

#endif	//MATRIX_H