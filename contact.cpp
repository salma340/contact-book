#include "contact.h"
#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
contact::contact()
{
    fname=" ";
    lname=" ";
    classfication=" ";
    id=0;
    add=new address();
    emails=nullptr;
   phone_nums=nullptr;
}
contact::contact(string f,string l,string c,size_t i,size_t p,size_t e)
{
    fname=f;
    lname=l;
    id=i;
    classfication=c;
    pnum=p;
    emailnum=e;
    phone_nums=new string[pnum];
    emails=new string [e];
}
contact::contact(const contact& other) {
    id = other.id;
    fname = other.fname;
    lname = other.lname;
    classfication = other.classfication;
    fav = other.fav;

    pnum = other.pnum;
    emailnum = other.emailnum;

    phone_nums = new string[pnum];
    emails = new string[emailnum];
    for (size_t i = 0; i < pnum; i++) {
        phone_nums[i] = other.phone_nums[i];
    }

    for (size_t i = 0; i < emailnum; i++) {
        emails[i] = other.emails[i];
    }

    add= other.add;
}


contact& contact::operator=(const contact& other) {
    if (this == &other) {
        return *this;
    }

    delete[] phone_nums;
    delete[] emails;
   id = other.id;
    fname = other.fname;
    lname = other.lname;
    classfication = other.classfication;
    fav = other.fav;

    pnum = other.pnum;
    emailnum = other.emailnum;

    phone_nums = new string[pnum];
    emails = new string[emailnum];


   for (size_t i = 0; i < pnum; i++) {
        phone_nums[i] = other.phone_nums[i];
    }

    for (size_t i = 0; i < emailnum; i++) {
        emails[i] = other.emails[i];
    }

    add= other.add;
    return *this;
}
void contact::set_lname(string l)
{
    lname=l;
}
void contact::set_fname(string f)
{
    fname=f;
}


void  contact:: set_Class(string c)
{
    classfication=c;
}
void  contact::set_id(size_t i)
{
    id=i;
}
string contact::get_fname()const
{
    return fname;
}
string contact::get_lname()const
{
    return lname;
}


string contact::get_Class()const
{
    return classfication;
}
bool contact::get_fav()const
{
    if(fav==1)
        return true;
    else
        return false;
}

size_t contact:: get_id() const
{
    return id;
}
bool contact::isValidphoneNumber(string phone)
{
    bool c=true;
    if(phone.substr(0,3) != "+20" || phone.size()!=13 )
        c=false;
    for(size_t i=3; i<phone.size(); i++)
    {
        if(!(isdigit(phone[i])))
        {
            c=false;
        }
    }
    return c;

}
bool contact::isValidEmail(string email) {
    bool isvalid=email.find('@') != -1 && email.find('.') != -1;
    return isvalid;
}
void contact::read()
{
    cout<<"Enter First Name: ";
    cin>>fname;
    cout<<"Enter Last Name: ";
    cin>>lname;
    cout<<"Enter Class(Friend,work,family,other): ";
    cin>>classfication;
    cout<<"Set as Fav: (press 1 (fav) or 0 (Not) )";
    cin>>fav;
    cout<<"How many numbers: ";
    cin>>pnum;
    phone_nums=pnum>0? new string[pnum]:nullptr;
    for(size_t i=0; i<pnum; i++)
    {
        cout<<"Phone #"<<i+1<<":";
        cin>>phone_nums[i];
        while(!isValidphoneNumber(phone_nums[i]))
        {
            cout<<"Phone number is not correct"<<endl;
            cout<<"Phone #"<<i+1<<":";
            cin>>phone_nums[i];
        }
    }
    cout<<"How many Emails: ";
    cin>>emailnum;
    emails=emailnum>0? new string[emailnum]:nullptr;
    for(size_t i=0; i<emailnum; i++)
    {
        cout<<"mail #"<<i+1<<":";
        cin>>emails[i];
    while(!isValidEmail(emails[i]))
        {
            cout<<"Email is not correct"<<endl;
            cout<<"mail #"<<i+1<<":";
            cin>>emails[i];
        }
    }
    cout<<"Enter ID: ";
    cin>>id;
    add->read();
}
void contact::savefile()
{
    ofstream out("data.txt",ios::app);
    out<<id;
    out<<setw(20)<<fname;
    out<<setw(20)<<lname;
    out<<setw(20)<<classfication;
    out<<setw(17)<<fav;
    out<<setw(20);
    out<<add->get_streetnum()<<" "<<add->get_street()<<" "<<add->get_city()<<" "<<add->get_country();
    out<<setw(20);
    for(size_t i=0; i<pnum; i++)
    {
        out<<phone_nums[i]<<" ";
    }
    out<<"\t";
    for(size_t i=0; i<emailnum; i++)
    {
        out<<emails[i];
    }
    out<<endl;
    out<<"______________________________________________________________________________________________________________________________________________________"<<endl;

    out.close();

}

void contact::display()const
{
    cout<<setw(20)<<id;
    cout<<setw(20)<<fname;
    cout<<setw(20)<<lname;
    cout<<setw(20)<<classfication;
    cout<<setw(20)<<fav;
    add->display();
    for(size_t i=0; i<pnum; i++)
    {
        cout<<phone_nums[i]<<" ";
    }
    cout<<"\t";
    for(size_t i=0; i<emailnum; i++)
    {
        cout<<emails[i]<<" ";
    }

    cout<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;



}
contact::~contact()
{
delete []phone_nums;
delete []emails;
}
