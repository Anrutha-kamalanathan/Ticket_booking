#include<fstream>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"slot.h"
using namespace std;

//defining class "screen"
class screen
{
    int scr_no;
    char movie_name[20];
    slot s1;
public:
    int get_scr();
    void display_screen();
    void select_slot();
    void getdata();

};

//function that returns scree number
int screen :: get_scr()
    {
        return scr_no;
    }

// function that prints screen number and movie name
void screen ::  display_screen()
    {
        cout<<"\n\tScreen No  : "<<scr_no;
        cout<<"\n\tMovie Name : "<<movie_name<<endl<<endl;
    }

//function that gets screen number and movie name
void screen :: getdata()
    {
        cout<<"\tScreen No:";
        cin>>scr_no;
        cout<<"\tMovie name : ";
        cin>>movie_name;
    }

// function that gets the time slot
void screen :: select_slot(  )

    {
        char slt1[10],slt2[10],slt3[10],slt4[10];
        strcpy(slt1 , "11am");
        strcpy(slt2,"3pm");
        strcpy(slt3,"6pm");
        strcpy(slt4,"10pm");
        int ch;
        step:
        cout<<"\n\tSlots Available\n\t"<<"1. "<<slt1<<endl<<"\t2. "<<slt2<<endl<<"\t3. "<<slt3<<endl<<"\t4. "<<slt4<<endl;
        cout<<"\n\tEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1 :
                s1.select(get_scr(),slt1);
                 break;
        case 2 : s1.select(get_scr(),slt2);
                 break;
        case 3 : s1.select(get_scr(),slt3);
                 break;
        case 4 : s1.select(get_scr(),slt4);
                 break;
        default : cout<<"\n\tWrong choice\n";  //checking the correctness of slot
                  goto step;
        }
    }
