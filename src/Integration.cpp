#include "Integration.h"
using namespace std;

Integration::Integration()
{
}

Integration::~Integration()
{
}

void Integration::Run(string& user_input)
{
    cout<<"coming soon\n";
    return;
}

template<typename value>
inline void Integration::Display(const value& answer, const string& unit) const
{
    system("cls");
    cout<<"Ans:\n";
    cout<<'\t'<<answer<<unit<<endl;
    system("pause");
    return;
}
