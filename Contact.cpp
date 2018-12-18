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

#include "Contact.h"
using namespace std;

Contact::Contact(string fname, string lname){
    this->fname = fname;
    this->lname = lname;
}

Contact::Contact(string fname, string lname, string pnum){
    this->fname = fname;
    this->lname = lname;
    this->pnum = pnum;
}

string Contact::getName() {
    return fname + " " + lname;
}

string Contact::getInfo() {
    return fname + " " + lname + " :" + pnum;
}