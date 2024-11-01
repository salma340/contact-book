#include "address.h"
#include<iostream>
#include<iomanip>
using namespace std;
address::address()
{
    street="No street available";
    city="No street available";
    country="No country available";
    streetnum=0;
}
address::address(int n,string s,string ci,string co)
{
    street=s;
    city=ci;
    country=co;
    streetnum-n;
}
void address::set_street(string s)
{
    street=s;
}
void address::set_city(string ci)
{
    city=ci;
}
void address::set_country(string co)
{
    country=co;
}
void address::set_streetnum(int n)
{
   streetnum=n;
}

string address::get_street()const
{
    return street;
}
string address::get_city()const
{
    return city;
}
string address::get_country()const
{
    return country;
}
int address::get_streetnum()const
{
    return streetnum;
}

void address::display()const
{

  cout<<streetnum<<" "<<left<<street<<" "<<city<<" "<<country<<"\t\t";
}

void address::read()
{
    cout<<"\t\t **Enter Address details: **"<<endl;
    cout<<"Enter Street num: ";
    cin>>streetnum;
    cout<<"Enter Street name: ";
    cin.ignore();
    getline(cin,street);
    cout<<"Enter City name: ";
    cin>>city;
    cout<<"Enter Country name: ";
    cin>>country;
}
address::~address()
{
    //dtor

}
