#include "Engineer.h"
using namespace std;

Engineer::Engineer()
{
    fIntegration=new Integration;
    fBasic_Calculations=new Basic_Calculations;
}

Engineer::~Engineer()
{
    delete fIntegration;
    delete fBasic_Calculations;
}

void Engineer::Run()
{
    cout<<"Creeate an event? Y/N\n";
    char ch;
pt0:
    cout<< "$:>";
    cin>>ch;
    if(ch=='n')
        Exit();
    else
        if(ch=='y')
        {
            clearscreen();
            cin.ignore();
            cout<<"       Welcome to -k0$m@3'3- Engineer's Calculator\n";
            cout<<"To get help about how to use the program enter the HELP command\n";
            for(;;)
            {
                string user_input;
pt1:
                cout<< "$:>";
                cin.ignore('\0');
                getline(cin, user_input);
                string operate=Engineer_Run_Parser(user_input);

                if(operate==" ")goto pt1;
                else if(operate=="exit")Exit();
                else if(operate=="error"){cout<<"opening and closing bracelet mismatch\n"; pausescreen();}
                else if(operate=="help")Help();
                else if(operate=="about")About();
                else if(operate=="calc")fBasic_Calculations->Run(user_input);
                else if(operate=="integrate")fIntegration->Run(user_input);
                else
                {
                    cout<<"Invalid Command.\nEnter the HELP command to get a list of all the valid";
                    cout<<" commands supported by the program\n";
                    goto pt1;
                }
                clearscreen();
            }
        }
        else
            goto pt0;
    return;
}		

void Engineer::Exit()
{
    clearscreen();
    cout<<"Contact Us:\n";
    cout<<"Phone no: 08139278033\n";
    cout<<"Email: kosmaz2009@yahoo.com\n";
    pausescreen();
    exit(1);
    return;
}

void Engineer::About()
{
    clearscreen();
    cout<<"\t\t-------------------------------------\n";
    cout<<"\t\t|ENGINEERING MATHEMATICAL EMULATIONS|\n";
    cout<<"\t\t|    CALCULATOR FOR ENGINEERS       |\n";
    cout<<"\t\t|         VERSION 1.0.0.1           |\n";
    cout<<"\t\t|    Developed at -k0$m@3- Labs     |\n";
    cout<<"\t\t|Courtesy of:                       |\n";
    cout<<"\t\t|         -k0$m@3- inc.             |\n";
    cout<<"\t\t-------------------------------------\n";
    pausescreen();
    clearscreen();
    return;
}

void Engineer::Help()
{
    clearscreen();
    cout<<"Here is a list of supported commands\n";
    cout<<"-help/HELP: A list of valid comands supported by the program\n";
    cout<<"-about/ABOUT: About program/software\n";
    cout<<"-exit/EXIT: To exit the program\n";
    cout<<"-integrate/INTEGRATE: To integrate a given math equation\n";
    cout<<"-calc/CALC; To do basic engineering/math operations\n";
    pausescreen();
    clearscreen();
    return;
}
