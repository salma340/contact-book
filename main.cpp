#include <iostream>
#include <cstdlib>
#include "Array.h"
#include "contactsbook.h"
#include "contacts.h"
using namespace std;

int main()
{
    int c=-1;
    contactsbook x;
    while(c!=0)
    {

        cout<<"\t\t\t=======================================================================\t\t\t"<<endl;
        cout<<"\t\t\tContacts Book Menu:\t\t\t"<<endl;
        cout<<"\t\t\t________________________\t\t\t"<<endl;
        cout<<"\t\t\t1.Add New Contact\t\t\t"<<endl;
        cout<<"\t\t\t2.Search by Last Name (Enter Last Name correctly)\t\t\t"<<endl;
        cout<<"\t\t\t3.Search by Classificatin (friend,work,family,other)?\t\t\t"<<endl;
        cout<<"\t\t\t4.Print all Contacts\t\t\t"<<endl;
        cout<<"\t\t\t5.Print Fav Contacts\t\t\t"<<endl;
        cout<<"\t\t\t6.Save to file\t\t\t"<<endl;
        cout<<"\t\t\t7.Load from file\t\t\t"<<endl;
        cout<<"\t\t\t8.Delete contact\t\t\t"<<endl;
        cout<<"\t\t\t9.Update Contact Information\t\t\t"<<endl;
        cout<<"\t\t\t10.Reverse Contact Book\t\t\t"<<endl;
        cout<<"\t\t\t11.Exit\t\t\t"<<endl;
        cout<<"\t\t\t========================================================================\t\t\t"<<endl;
        cout<<"Enter your choice:";
        cin>>c;

        switch(c)
        {
        case 1:
            system("cls");//clear screen;
            x.addcontact();
            break;
        case 2:
            system("cls");
            x.searchbylastname();
            break;
        case 3:
            system("cls");
            x.searchByClassification();
            break;
        case 4:
            system("cls");
            x.print();
            break;
        case 5:
            system("cls");
            x.printfav();
            break;
        case 6:
            system("cls");
            x.savetofile();
            break;
        case 7:
            x.loadfromfile();
            break;
        case 8:
            x.deletecontact();
            break;
        case 9:
            system("cls");
            x.updatecontact();
            break;
        case 10:
            x.Reversecontact();
            break;
        case 11:
            cout<<"Thanks for using the system :)"<<endl;
            c=0;
            break;
        default:
            cout<<"Enter correct number"<<endl;
        }

    }
    return 0;
}
