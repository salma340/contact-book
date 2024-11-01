#include "contactsbook.h"
#include<iomanip>
#include<fstream>
contactsbook::contactsbook()
{

}
void contactsbook::addcontact()
{
    cout<<"\t\t\t - - - Add a New contact - - -\t\t\t"<<endl;
    contact new_contact;
    new_contact.read();
    person.append(new_contact);
}
void contactsbook:: searchbylastname()
{
    if(person.get_size()==0)
        cout<<"No Contact Found"<<endl;

    else
    {
        string lname;
        cout<<"Enter The Last name in correct form: ";
        cin>>lname;

        cout<<"---- Contacts Informations ----"<<endl<<endl;
        cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
        cout<<setw(20)<<left<<"ID";
        cout<<setw(20)<<left<<"FName";
        cout<<setw(20)<<left<<"LName";
        cout<<setw(20)<<left<<"Classification";
        cout<<setw(20)<<left<<"Fav";
        cout<<setw(20)<<left<<"Address";
        cout<<setw(20)<<left<<"Phone num";
        cout<<setw(20)<<left<<"Email"<<endl;
        cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;
        for(size_t i=0; i<person.get_size(); i++)
        {
            if(person[i].get_lname() == lname)
            {
                person[i].display();
            }

        }
    }
}
void contactsbook::searchByClassification()
{
    string classification;
    cout<<"Enter The Classification: ";
    cin>>classification;
    cout<<"---- Contacts Informations ----"<<endl<<endl;
    cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    cout<<setw(20)<<left<<"ID";
    cout<<setw(20)<<left<<"FName";
    cout<<setw(20)<<left<<"LName";
    cout<<setw(20)<<left<<"Classification";
    cout<<setw(20)<<left<<"Fav";
    cout<<setw(20)<<left<<"Address";
    cout<<setw(20)<<left<<"Phone num";
    cout<<setw(20)<<left<<"Email"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;

    for (size_t i = 0; i < person.get_size(); i++)
    {
        if (person[i].get_Class() == classification)
        {
            person[i].display();
        }
    }
}
void contactsbook::deletecontact()
{
    if(person.get_size()==0)
        cout<<"No Contact Found"<<endl;
    else
    {
        size_t id;
        cout<<"Enter The ID: ";
        cin>>id;
        bool del=false;
        for(size_t i=0; i<person.get_size(); i++)
        {
            if(person[i].get_id() ==id )
            {
                person.Delete(i);
                del=true;
            }
        }
        if(del)
            cout<<"Contact Deleted"<<endl;
        else
            cout<<"No Contact Found"<<endl;
    }

}
void contactsbook::savetofile()
{
    ofstream file("data.txt");
    file<<"---- Contacts Informations ----";
    file<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    file<<setw(20)<<left<<"ID";
    file<<setw(20)<<left<<"FName";
    file<<setw(20)<<left<<"LName";
    file<<setw(20)<<left<<"Classification";
    file<<setw(20)<<left<<"Fav";
    file<<setw(20)<<left<<"Address";
    file<<setw(20)<<left<<"Phone num";
    file<<setw(20)<<left<<"Email"<<endl;
    file<<"______________________________________________________________________________________________________________________________________________________"<<endl;
    for(size_t i=0; i<person.get_size(); i++)
    {
        person[i].savefile();
    }

    file.close();
    cout<<"Data saved To file"<<endl;
}
void contactsbook::loadfromfile()
{
    ifstream in("data.txt");
    if (in.is_open())
    {
        string line;
        while (getline(in, line))
        {
            cout << line <<endl;
        }

    }
}

void contactsbook::updatecontact()
{
    int index;
    cout<<"The index of contact: ";
    cin>>index;
    contact new_contact;
    new_contact.read();
    person[index-1]=new_contact;
    cout<<endl;
    cout<<"---- Contacts Informations ----"<<endl<<endl;
    cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    cout<<setw(20)<<left<<"ID";
    cout<<setw(20)<<left<<"FName";
    cout<<setw(20)<<left<<"LName";
    cout<<setw(20)<<left<<"Classification";
    cout<<setw(20)<<left<<"Fav";
    cout<<setw(20)<<left<<"Address";
    cout<<setw(20)<<left<<"Phone num";
    cout<<setw(20)<<left<<"Email"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;
    person.display();


}

void contactsbook::Reversecontact()
{
    person.Reverse();
     cout<<"---- Contacts Informations ----"<<endl<<endl;
    cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    cout<<setw(20)<<left<<"ID";
    cout<<setw(20)<<left<<"FName";
    cout<<setw(20)<<left<<"LName";
    cout<<setw(20)<<left<<"Classification";
    cout<<setw(20)<<left<<"Fav";
    cout<<setw(20)<<left<<"Address";
    cout<<setw(20)<<left<<"Phone num";
    cout<<setw(20)<<left<<"Email"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;
    person.display();
}
void contactsbook:: print()const
{
    cout<<"---- Contacts Informations ----"<<endl<<endl;
    cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    cout<<setw(20)<<left<<"ID";
    cout<<setw(20)<<left<<"FName";
    cout<<setw(20)<<left<<"LName";
    cout<<setw(20)<<left<<"Classification";
    cout<<setw(20)<<left<<"Fav";
    cout<<setw(20)<<left<<"Address";
    cout<<setw(20)<<left<<"Phone num";
    cout<<setw(20)<<left<<"Email"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;
    person.display();


}
void contactsbook:: printfav()
{
    cout<<"---- Contacts Informations ----"<<endl<<endl;
    cout<<"\t\t\t=====================================================\t\t\t"<<endl<<endl;
    cout<<setw(20)<<left<<"ID";
    cout<<setw(20)<<left<<"FName";
    cout<<setw(20)<<left<<"LName";
    cout<<setw(20)<<left<<"Classification";
    cout<<setw(20)<<left<<"Fav";
    cout<<setw(20)<<left<<"Address";
    cout<<setw(20)<<left<<"Phone num";
    cout<<setw(20)<<left<<"Email"<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________"<<endl;
    for (size_t i = 0; i < person.get_size(); i++)
    {
        if (person[i].get_fav())
        {
            person[i].display();
        }
    }


}
contactsbook::~contactsbook()
{

}
