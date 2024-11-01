#ifndef CONTACT_H
#define CONTACT_H
#include "address.h"

class contact
{
public:
    contact();
    contact(const contact&);
    contact& operator=(const contact&);
    contact(string,string,string,size_t,size_t,size_t);
    void set_fname(string);
    void set_lname(string);
    void set_Class(string);
    void set_id(size_t);
    string get_fname()const;
    string get_lname()const;
    string get_Class()const;
    bool get_fav()const;
    size_t get_id()const;
    void read();
    void display()const;
    bool isValidphoneNumber(string);
    bool isValidEmail(string);
    void savefile();
    void Reverse();
    virtual ~contact();

protected:

private:
    string fname,lname,classfication;
    size_t id,pnum,emailnum,fav;
    string*phone_nums;
    string *emails;
    address *add;

};




#endif // CONTACT_H
