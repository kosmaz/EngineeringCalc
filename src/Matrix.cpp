#include "Matrix.h"
using namespace std;

Matrix::Matrix():fError(false){}

void Matrix::Run(string& user_input)
{
	if(user_input=="matrix")Help();
	else if(user_input=="add")add();
	else if(user_input=="subtract")subtract();
	else if(user_input=="multiply")multiply();
	else if(user_input=="determinant")determinant();
	else if(user_input=="scalar multiply")scalarMultiply();
	else if(user_input=="inverse")inverse();
	else if(user_input=="transpose")transpose();
	else
    {
    	  cout<<"Invalid Command!\a\nEnter the (matrix/MATRIX) command to get a list of all the valid commands supported by the matrix/MATRIX command\n\a";
    }
	return;
}

void Matrix::Help()
{
	clearscreen();
	cout<<"\t\tList of commands supported by the matrix command\n";
	cout<<"-matrix(add)/MATRIX(ADD): To add any number of matrices with the same dimension\n";
	cout<<"-matrix(subtract)/MATRIX(SUBTRACT): To subtract any number of matrices with the same dimension\n";
	cout<<"-matrix(multiply)/MATRIX(MULTIPLY): To multiply any number of matrices with compatible dimensions\n";
	cout<<"-matrix(scalar multiply)/MATRIX(SCALAR MULTIPLY): To perform a matrix scalar multiplication";
	cout<<"-matrix(determinant)/MATRIX(DETERMINANT): To find the determinant of a given matrix\n";
	cout<<"-matrix(inverse)/MATRIX(INVERSE): To find the inverse of a given matrix\n";
	cout<<"-matrix(transpose)/MATRIX(TRANSPOSE): To find the transpose of a given matrix\n";
	pausescreen();
	return;
}

void Matrix::add()
{
	getValues("add");
	if(compatible()==false)
	{
		cout<<"matrix dimensions incompatible\n";
		return;
	}
	for(unsigned i=1; i<fWork_On->size(); ++i)
		for(int j=0; j<fWork_On->at(i-1)->row; ++j)
			for(int k=0; k<fWork_On->at(i-1)->col; ++k)
				fWork_On->at(i)->matrix->at(j)->at(k)+=fWork_On->at(i-1)->matrix->at(j)->at(k);
	vector<vector<float>*>* temp=new vector<vector<float>*>(*fWork_On->at(fWork_On->size()-1)->matrix);
	fAns=new ans;
	fAns->row=fWork_On->at(fWork_On->size()-1)->row;
	fAns->col=fWork_On->at(fWork_On->size()-1)->col;
	fAns->matrix=temp;
	printAns();
	destroyValues();
	delete temp;
	return;
}

void Matrix::subtract()
{
	getValues("subtract");
	if(compatible()==false)
	{
		cout<<"matrix dimensions incompatible\n";
		return;
	}
	for(unsigned i=1; i<fWork_On->size(); ++i)
		for(int j=0; j<fWork_On->at(i-1)->row; ++j)
			for(int k=0; k<fWork_On->at(i-1)->col; ++k)
				fWork_On->at(i)->matrix->at(j)->at(k)=fWork_On->at(i-1)->matrix->at(j)->at(k)-fWork_On->at(i)->matrix->at(j)->at(k);
	vector<vector<float>*>* temp=new vector<vector<float>*>(*fWork_On->at(fWork_On->size()-1)->matrix);
	fAns=new ans;
	fAns->row=fWork_On->at(fWork_On->size()-1)->row;
	fAns->col=fWork_On->at(fWork_On->size()-1)->col;
	fAns->matrix=temp;
	printAns();
	destroyValues();
	delete temp;  
	return;
}

void Matrix::multiply()
{
	getValues("multiplication");
	if(compatible(1)==false)
	{
		cout<<"matrix dimensions incompatible\n";
		return;
	}
	for(unsigned i=1; i<fWork_On->size(); ++i)
	{
		info* temp=new info;
		temp->row=fWork_On->at(i)->row;
		temp->col=fWork_On->at(i)->col;
		temp->matrix=fWork_On->at(i)->matrix;
		
		fWork_On->at(i)->row=fWork_On->at(i-1)->row;
		fWork_On->at(i)->matrix=new vector<vector<float>*>;
		for(int s=0; s<fWork_On->at(i)->row; ++s)
		{
			vector<float>* temp_matrix=new vector<float>;
			for(int n=0; n<fWork_On->at(i)->col; ++n)
				temp_matrix->push_back(0.0);
			fWork_On->at(i)->matrix->push_back(temp_matrix);
		}	
		
		for(int j=0; j<fWork_On->at(i)->row; ++j)
			for(int k=0; k<fWork_On->at(i)->col; ++k)
			{
				for(int l=0; l<temp->row; ++l)
					fWork_On->at(i)->matrix->at(j)->at(k)+=fWork_On->at(i-1)->matrix->at(j)->at(l)*temp->matrix->at(l)->at(k);
			}
		
		for(int m=0; m<temp->row; ++m)
			delete temp->matrix->at(m);
		delete temp->matrix;
		delete temp;	
	}
	
	vector<vector<float>*>* temp=new vector<vector<float>*>(*fWork_On->at(fWork_On->size()-1)->matrix);
	fAns=new ans;
	fAns->row=fWork_On->at(fWork_On->size()-1)->row;
	fAns->col=fWork_On->at(fWork_On->size()-1)->col;
	fAns->matrix=temp;
	printAns();
	destroyValues();
	delete temp;  
	return;
}

void Matrix::scalarMultiply()
{
	clearscreen();
	string buffer;
	cout<<"\nscalar multiplier:>";
	cin.clear();
	getline(cin,buffer);
	float multiplier=(float)numeric_value(buffer);
	
	getValues("",1);
	
	for(int i=0; i<fWork_On->at(0)->row; ++i)
		for(int j=0; j<fWork_On->at(0)->col; ++j)
			fWork_On->at(0)->matrix->at(i)->at(j)*=multiplier;
			
	vector<vector<float>*>* temp=new vector<vector<float>*>(*fWork_On->at(0)->matrix);
	fAns=new ans;
	fAns->row=fWork_On->at(0)->row;
	fAns->col=fWork_On->at(0)->col;
	fAns->matrix=temp;
	printAns();
	destroyValues();
	delete temp;  	
	
	return;
}

void Matrix::determinant()
{
	return;
}

void Matrix::inverse()
{
	return;
}

void Matrix::transpose()
{
	getValues("",1);
	subTranspose();	
	vector<vector<float>*>* temp_2=new vector<vector<float>*>(*fWork_On->at(0)->matrix);
	fAns=new ans;
	fAns->row=fWork_On->at(0)->row;
	fAns->col=fWork_On->at(0)->col;
	fAns->matrix=temp_2;
	printAns();
	destroyValues();
	delete temp_2;
		
	return;
}

void Matrix::subTranspose()
{
	info* temp=new info;
	temp->row=fWork_On->at(0)->row;
	temp->col=fWork_On->at(0)->col;
	temp->matrix=new vector<vector<float>*>;
	
	for(int i=0; i<temp->row; ++i)
	{
		vector<float>* temp_matrix=new  vector<float>;
		for(int j=0; j<temp->col; ++j)
			temp_matrix->push_back(fWork_On->at(0)->matrix->at(i)->at(j));
		temp->matrix->push_back(temp_matrix);
	}
	
	if(temp->row==temp->col)
	{
		for(int k=0; k<temp->row; ++k)
			for(int l=0; l<temp->col; ++l)
				fWork_On->at(0)->matrix->at(k)->at(l)=temp->matrix->at(l)->at(temp->col-k-1);
	}
	else
	{
		if(temp->row<temp->col)
		{
			for(int i=0; i<fWork_On->at(0)->row; ++i)
				fWork_On->at(0)->matrix->at(i)->pop_back();
				
			vector<float>* new_row=new vector<float>;
			
			for(int j=0; j<fWork_On->at(0)->row; ++j)
				new_row->push_back(0.0);
				 
			fWork_On->at(0)->matrix->push_back(new_row);
			
			int swap=fWork_On->at(0)->row;
			fWork_On->at(0)->row=fWork_On->at(0)->col; 	
			fWork_On->at(0)->col=swap;
			
			for(int k=0; k<fWork_On->at(0)->row; ++k)
				for(int l=0; l<fWork_On->at(0)->col; ++l)
					fWork_On->at(0)->matrix->at(k)->at(l)=temp->matrix->at(l)->at(temp->col-k-1);
		}
		else
		{
			vector<float>* old_row=fWork_On->at(0)->matrix->at(fWork_On->at(0)->row-1);
			fWork_On->at(0)->matrix->pop_back();
			delete old_row;
			
			int swap=fWork_On->at(0)->row;
			fWork_On->at(0)->row=fWork_On->at(0)->col; 	
			fWork_On->at(0)->col=swap; 
			
			for(int i=0; i<fWork_On->at(0)->row; ++i)
				fWork_On->at(0)->matrix->at(i)->push_back(0.0);	
				
			 for(int j=0; j<fWork_On->at(0)->row; ++j)
				for(int k=0; k<fWork_On->at(0)->col; ++k)
					fWork_On->at(0)->matrix->at(j)->at(k)=temp->matrix->at(k)->at(temp->col-j-1); 							
		}
	}
		
	for(int m=0; m<temp->row; ++m)
		delete temp->matrix->at(m);
	delete temp->matrix;
	delete temp; 	
	
	return;
}

void Matrix::getValues(string op,unsigned nos)
{
	clearscreen();
	fWork_On=new vector<info*>;
	if(nos==0)
	{
		char n;
		cout<<"\nEnter the number of matrix to perform the "<<op<<" operation on:>";
		pt0:
		cin>>n;
		if(n=='0' || n=='1' || !isdigit(n))
		{
			cin.clear(); 
			cout<< ":>"; 
			goto pt0;
		}
		int no=(int)n-48;
		clearscreen();
		for(int i=0; i<no; ++i)
		{
			char r,c;
			info* data=new info;
			vector<vector<float>*>* array= new vector<vector<float>*>;
			
			cout<<"\n\t\tEnter the matrix dimension\n";
			cout<<"Enter the number of rows for matrix "<<(i+1)<< ":>"; 
			pt1: 
			cin>>r;
			if(!isdigit(r))
			{
				cin.clear(); 
				cout<< ":>"; 
				goto pt1;
			} 
			int row=(int)r-48;
			cout<<"Enter the number of columns for matrix "<<(i+1)<< ":>"; 
		   pt2:
		   cin>>c;
			if(!isdigit(c))
			{
				cin.clear(); 
				cout<< ":>"; 
				goto pt2;
			} 
			int col=(int)c-48;
			data->row=row; data->col=col;
			cin.ignore();
			for(int j=0; j<row; ++j)
			{
				vector<float>* _temp=new vector<float>;
				for(int k=0; k<col; ++k)
				{
					cout<<(char)('a'+k)<<(j+1)<< ":>";
					string temp; 
					getline(cin,temp);
				   _temp->push_back((float)numeric_value(temp));
				}
				array->push_back(_temp);
			}
			data->matrix=array;
			fWork_On->push_back(data);
		}
	}
	else
	{
		char r,c;
		info* data=new info;
		vector<vector<float>*>* array= new vector<vector<float>*>;
			
		cout<<"\n\t\tEnter the matrix dimension\n";
		cout<<"Enter the number of rows:>"; 
		pt3:
		cin>>r;
		if(!isdigit(r))
		{
			 cin.clear(); 
			 cout<< ":>"; 
			 goto pt3;
		}
		int row=(int)r-48;
		cout<<"Enter the number of columns:>"; 
		pt4:
		cin>>c;
		if(!isdigit(c))
		{
			 cin.clear(); 
			 cout<< ":>"; 
			 goto pt4;
		}
		int col=(int)c-48;
		data->row=row; data->col=col;
     cin.ignore();
		for(int j=0; j<row; ++j)
		{
			vector<float>* _temp=new vector<float>;
			for(int k=0; k<col; ++k)
			{
				cout<<(char)('a'+k)<<(j+1)<< ":>";
				string temp; 
				getline(cin,temp);
				_temp->push_back((float)numeric_value(temp));
			}
			array->push_back(_temp);
		}
		data->matrix=array;
		fWork_On->push_back(data);
	}
	return;
}

void Matrix::destroyValues()
{
	for(unsigned i=0; i<fWork_On->size(); ++i)
	{
		for(int j=0; j<fWork_On->at(i)->row; ++j)
			delete fWork_On->at(i)->matrix->at(j);
		delete fWork_On->at(i)->matrix;
		delete fWork_On->at(i);
	}
	delete fWork_On;
	return;
}

void Matrix::printAns()
{
	clearscreen();
	if(fError==true)
	{
		cout<<"math error\n"; 
		fError=false; 
	}
	else
	for(int i=0; i<fAns->row; ++i)
	{
		for(int j=0; j<fAns->col; ++j)
			cout<<fAns->matrix->at(i)->at(j)<<"   ";
		cout<<endl<<endl;
	}
	pausescreen();
	return;
}

void Matrix::destroyAns()
{
	for(int i=0; i<fAns->row; ++i)
		delete fAns->matrix->at(i);
	delete fAns->matrix;
	delete fAns;
}