#ifndef CONTACTSBOOK_H
#define CONTACTSBOOK_H
#include "Array.h"
#include "contact.h"
class contactsbook
{
     public:
         contactsbook();
        void addcontact();
        void searchbylastname();
        void searchByClassification();
        void deletecontact();
        void updatecontact();
        void print()const;
        void printfav();
        void savetofile();
        void loadfromfile();
        void Reversecontact();
        ~contactsbook();

    private:

        Array <contact> person;
};

#endif // CONTACTSBOOK_H
