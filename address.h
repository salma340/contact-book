#ifndef ADDRESS_H
#define ADDRESS_H
#include "string"
#include<iostream>
#include<fstream>
using namespace std;
class address
{
    public:
        address();
        address(int,string,string,string);
        void set_street(string);
        void set_city(string);
        void set_country(string);
        void set_streetnum(int);
        string get_street()const;
        string get_city()const;
        string get_country()const;
        int get_streetnum()const;
        void display()const;
        void read();
       ~address();

    private:
        string street,city,country;
        int streetnum;
};

#endif // ADDRESS_H
