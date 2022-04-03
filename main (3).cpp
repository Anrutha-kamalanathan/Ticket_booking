#include<fstream>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"theatre.h"
using namespace std;


// function to get started
void get_started()
{

    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t ###        WELCOME        ###";
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue....";
    getch();
    system("cls");
}

//driver function
int main()
{
    char opt ;
    get_started();
    step:
    theatre t1;
    t1.display();  //displaying the screen details
    t1.select_screen();  // function to enter the preferred screen
    system("cls");

    //checking if the user wants to continue
    cout<<"\n\tDo You Want To Continue ? ";
    cin>>opt;
    system("cls");

    if( opt == 'Y' || opt == 'y')
        goto step;
    else
    {
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t###\tThank You\t###\n\n\n\n\n\n\n\n";
    }
    return 0;
}

