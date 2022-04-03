#include<fstream>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"screen.h"
using namespace std;

//defining class "theater"
class theatre
{
    screen s;
public:
    void display();
    void select_screen();
};

//function to display the screen details
void theatre :: display()
    {
        ifstream f1;
        int i =1;
        f1.open("screen_details.txt",ios::in);//opening the screen_details file to display
        while(f1.read((char *)&s,sizeof(s)))
              {
                  cout<<"\n\n\tDisplaying details of screen "<<i<<endl;  //printing the details
                  s.display_screen();
                  i++;
              }
              f1.close();
    }

//function to enter the screen we wanted to
void theatre :: select_screen()
    {

        int n;
        stepa:
        cout<<"\n\tEnter your screen number : ";
        cin>>n;  //getting the screen number
        if( n!= 1 && n!= 2)  //checking the correctness of screen selection
        {
            cout<<"\n\tEnter correct screen number\n";
            goto stepa;
        }
        screen s;
        ifstream f1;
        f1.open("screen_details.txt",ios::in);
        while(f1.read((char *)&s,sizeof(s)))  // storing the detail into a file "screen_details"
                {
                  if( n == s.get_scr())
                      {
                        s.select_slot();
                        break;
                      }
              }
       f1.close();
    }
