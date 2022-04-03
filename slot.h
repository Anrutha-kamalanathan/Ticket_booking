#include<fstream>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

// defining class "slot"
  class slot
{
    int v_seats;
     int seat_no[20];
    int price;
    char time[10];
    char seat_arr[9][9];
    char name[20];
public:
    void set_details();
    char* gettime();
    int get_price();
    void select( int n , char *slt);
    void disp_details();
    int get_v_seats();
    void display_seat();
    void book_seat( int r , int c );
    char check_seat(int r , int c );
    void bookTicket(int n );
    void display_seat_no(int n );
};

// function that returns time
char* slot :: gettime()
    {
        return time;
    }

// function that returns price
int slot :: get_price()
    {
        return price;
    }

// function that gets user details and wanted seat
void slot :: set_details()
    {

        cout<<"\tName               : ";
        cin>>name;
        cout<<"\tTime               : ";
        cin>>time;
        cout<<"\tPrice for 1 ticket : ";
        cin>>price;
        v_seats = 81;

        for( int i = 0 ; i<10 ; i++)
         for(int j = 0 ; j<10 ; j++)
          {
              seat_arr[i][j] = '_';
          }
    }

// function that displays the ticket details
 void slot::disp_details()
    {
        cout<<"\n\tTime               : "<<time;
        cout<<"\n\tPrice for 1 ticket : "<<price;
        cout<<"\n\tNo. seats availble : "<<v_seats<<endl;
    }

    //function that returns vacant seats
int slot :: get_v_seats()
    {
        return v_seats;
    }

    //function to display the seat number
 void slot :: display_seat_no(int n )
    {
        for( int i = 0 ; i<n ; i++)
            cout<<seat_no[i]<<" ";
        cout<<endl;
    }
    //function to book seats
void slot :: book_seat( int r , int c )
    {
        seat_arr[r][c] = 'X';
    }

    //function to check booked seat
char slot :: check_seat(int r , int c )
    {
        return seat_arr[r][c];
    }

    // function to book tickets
void slot :: bookTicket(int n )
    {
        int r,c;
        if( n > get_v_seats())

            cout<<"\t"<<get_v_seats()<<" are only there \n ";  //displaying the total seats available
        else  //entering preferred seats
            {
            cout<<endl;
            display_seat();
            int k = 0;
            for( int i=0 ; i<n ; i++)
            {

                step:
                cout<<"\tEnter seat number for Ticket"<<i+1<<" : ";
                cout<<"\n\tEnter row alphabet : ";
                cin>>r;
                cout<<"\tEnter column number : ";
                cin>>c;
                if(check_seat(r,c) == '_')  //checking if the seat is empty
                {
                    book_seat(r,c);
                    v_seats--;
                    seat_no[k] = 10*r+c;
                    k++;
                }
                else  //if seat is booked
                    {
                    cout<<"\n\tseat already booked\n";
                    goto step;
                }
            }
        }
        cout<<endl<<"\tbooked tickets"<<endl<<endl;
        display_seat();  //displaying the seats after seat booking
    }

    // function to display the seats
 void slot :: display_seat()
    {
        for(int i = 0 ; i<=9;i++)
        {
            if(i!=0)
            cout<<i<<"  ";
            else
            cout<<"   ";
        }
        cout<<endl;
        for(int i = 1 ; i<= 9 ; i++)
        {
            for(int j = 0 ; j<=9;j++)
            {
                if(j == 0)
                    cout<<i<<"  ";
                else
                    cout<<seat_arr[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<"\n\n\t X - BOOKED\n\t _ - VACANT\n\n";  //displaying the legend
    }

    //function to update the slot detail files
void slot :: select( int n , char *slt)
    {
       ofstream f1;
       ifstream f2;
       slot s;
       if( n == 1)
            f2.open("screen1_slot_details.txt",ios::in);
       else f2.open("screen2_slot_details.txt",ios::in);
       f1.open("newfile.txt",ios::out);
       while(f2.read((char *)&s,sizeof(s)))
       {
           if(strcmp(s.gettime(),slt) == 0 )
           {
             s.disp_details();
             int num;
             cout<<"\n\tEnter Number of tickets : ";
             cin>>num;
             s.bookTicket(num);
             f1.write((char *)&s,sizeof(s));
             cout<<"\n\tPress Enter to view BILL.....";
             getch();
             system("cls");
             cout<<"\n\n\t####\t\tFUN CINEMAS\t\t####\n";  //displaying the bill
             cout<<"\n\tScreen No      : "<<n;
             if(n == 1 )
             cout<<"\n\tMovie Name     : Karnan";
             else
             cout<<"\n\tMovie Name     : Doctor ";

             cout<<"\n\tTime           : "<<s.gettime();
             cout<<"\n\tTotal_Tickets  : "<<num;
             cout<<"\n\tSeat Numbers   : ";
             s.display_seat_no(num);
             cout<<"\n\tTotal          : Rs."<<num*s.get_price()<<" ( "<<num<<" * "<<s.get_price()<<" ) ";
             cout<<"\n\n\tPress Enter to continue .....";
             getch();
           }
           else
            f1.write((char *)&s,sizeof(s));
       }
       f1.close();
       f2.close();

       if( n==1)
       {
       remove("screen1_slot_details.txt");  //updating screen1 slot details to another file
       rename("newfile.txt","screen1_slot_details.txt");
       }

       else
       {
        remove("screen2_slot_details.txt");  //updating screen2 slot details to another file
        rename("newfile.txt","screen2_slot_details.txt");
        }
    }
