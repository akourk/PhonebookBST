// Author       :   Alex Kourkoumelis
// Date         :   11/27/2017
// Title        :   Phonebook BST Application
// Description  :   reads phonebook.txt, stores each line
//                  (of format string_fname string_lname int_pnum)
//                  into a BinarySearchTree of Contact objects
//                  then prompts for a short list of actions to be performed on the phonebook
//                      -add, load, search, print, filter, quit
//                      -adds users, loads the phonebook.txt file, search for individual name,
//                      -prints entire phonebook, filters every contact until given name, and quit
//                  commented out a few lines that record and output search time.

#ifndef PART_I_ATTEMPT_1_CONTACT_H
#define PART_I_ATTEMPT_1_CONTACT_H

#include <iostream>
using namespace std;

class Contact {
private:
    string fname;
    string lname;
    string pnum;

public:
    Contact(){};
    Contact(string, string);
    Contact(string, string, string);
    string getName();
    string getInfo();

    friend ostream& operator<<(ostream& os, Contact& c){
        os << c.getInfo() << endl;
        return os;
    }

    friend bool operator==(Contact& p1, Contact& p2){
        if(p1.getName()==p2.getName()){
            return true;
        } else {
            return false;
        }
    }

    friend bool operator!=(Contact& p1, Contact& p2){
        if(p1.getName() != p2.getName()){
            return true;
        } else {
            return false;
        }
    }

    friend bool operator<(Contact& p1, Contact& p2){
        if(p1.getName() < p2.getName()){
            return true;
        } else {
            return false;
        }
    }

    friend bool operator <=(Contact& p1, Contact& p2){
        if(p1.getName() <= p2.getName()){
            return true;
        } else {
            return false;
        }
    }

    friend bool operator>(Contact& p1, Contact& p2){
        if(p1.getName() > p2.getName()){
            return true;
        } else {
            return false;
        }
    }
};


#endif //PART_I_ATTEMPT_1_CONTACT_H
