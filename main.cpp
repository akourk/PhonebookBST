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


#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Contact.h"
//#include <ctime>

using namespace std;


int main() {

    string filename;
    ifstream file;
    string fname;
    string lname;
    string pnum;
    int i=0;
    char decider = 'x';

    //creates BST object called Phonebook
    BinarySearchTree<Contact> Phonebook;

    cout << "*****PHONEBOOK APPLICATION*****" << endl;
    cout << "Please choose an operation:" << endl;
    while(decider != 'Q' && decider != 'q') {
        string deciderTemp;
        cout << "A (Add) | L (Load) | S (Search) | P (Print) | F (Filter) | Q (Quit): ";
        cin >> deciderTemp;
        if(deciderTemp.length() > 1) {
            decider = 'x';
            cerr << "\nDidn't understand that operation. Please try again. " << endl;
        } else {
            decider = deciderTemp.at(0);
        }

        switch(decider) {

                //add operation
                //takes first name and last name and adds it into the BST
            case 'A':
            case 'a': {
                string input, t1, t2;

                //takes a line of form "string string" from user
                cout << "Enter firt name and last name: ";
                cin.ignore(INT_MAX, '\n');
                getline(cin, input);

                //checks to see if the input has exactly one space.
                int y = 0;
                for(int j = 0; j < input.length(); j++) {
                    if(input[j] == ' ') {
                        y++;
                    }
                }

                //reports error if name format isn't correct
                if(y != 1){
                    cerr << "\nSorry, The name you entered isn't recognized. Try entering a valid first and last name." << endl;
                } else {

                    //this converts the string to all caps
                    transform(input.begin(), input.end(), input.begin(), ::toupper);

                    //this next stuff just converts a single line into 2 strings
                    for (int j = 0; j < input.length(); j++) {
                        if (input[j] == ' ') {
                            t1.append(input.substr(0, j));
                            t2.append(input.substr(j + 1, input.length() - 1));
                            break;
                        }
                    }

                    cout << "Enter phone: ";
                    cin >> pnum;

                    //creates contact object out of strings
                    Contact newContact(t1, t2, pnum);

                    //inserts contact object into BST
                    Phonebook.insert(newContact);
                    i++;
                    cout << endl;
                }
                break;
            }

                //load operation
                //prompts for filename to read and add to Phonebook object
            case 'L':
            case 'l': {

                //prompts for filename
                cout << "What is the filename? ";
                cin >> filename;
                ifstream file;
                file.open(filename);

                //checks to see if the file was opened without errors
                if(file.is_open()){

                    //creates contact objects and inserts them into the Phonebook
                    while (!file.eof()) {
                        file >> fname >> lname >> pnum;
                        Contact newContact(fname, lname, pnum);
                        Phonebook.insert(newContact);
                        i++;
                    }
                    cout << i << " Contacts loaded.";

                    //reports error otherwise
                } else {
                    cerr << "Error opening file. Try a different name or location. ";
                }


                cout << endl;
                break;
            }

                //search operation
                //prompts for name and returns matching contact object
            case 'S':
            case 's': {
                string input, t1, t2;

                //takes a line of form "string string" from user
                cout << "Enter first name and last name: ";
                cin.ignore(INT_MAX, '\n');
                getline(cin, input);

                //checks to see if the input has exactly one space.
                int y = 0;
                for(int j = 0; j < input.length(); j++) {
                    if(input[j] == ' ') {
                        y++;
                    }
                }

                //reports error if name format isn't correct
                if(y != 1){
                    cerr << "\nSorry, The name you entered isn't recognized. Try entering a valid first and last name." << endl;
                } else {

                    //this converts the string to all caps
                    transform(input.begin(), input.end(), input.begin(), ::toupper);

                    //this next stuff just converts a single line into 2 strings
                    for (int j = 0; j < input.length(); j++) {
                        if (input[j] == ' ') {
                            t1.append(input.substr(0, j));
                            t2.append(input.substr(j + 1, input.length() - 1));
                            break;
                        }
                    }

                    Contact newContact(t1, t2);

                    //to record search time
//                clock_t begin = clock();

                    //search function
                    Phonebook.treeDataSearch(newContact);

                    //This is to time the operation time of the search function.
//                clock_t end = clock();
//                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//                cout << "This search operation took " << elapsed_secs;

                    cout << endl;
                }
                break;
            }

                //print operation
                //prints all Contacts in alphabetical order (inorder BST traversal)
            case 'P':
            case 'p': {
                Phonebook.inOrder();
                cout << i << " Contacts." << endl;
                break;
            }

                //filter function
                //prints every contact up to a given name
            case 'F':
            case 'f': {
                string input, t1, t2;

                //takes a line of form "string string" from user
                cout << "Enter first name and last name: ";
                cin.ignore(INT_MAX, '\n');
                getline(cin, input);

                //checks to see if the input has exactly one space.
                int y = 0;
                for(int j = 0; j < input.length(); j++) {
                    if(input[j] == ' ') {
                        y++;
                    }
                }

                //reports error if name format isn't correct
                if(y != 1){
                    cerr << "\nSorry, The name you entered isn't recognized. Try entering a valid first and last name." << endl;
                } else {

                    //this converts the string to all caps
                    transform(input.begin(), input.end(), input.begin(), ::toupper);

                    //this next stuff just converts a single line into 2 strings
                    for (int j = 0; j < input.length(); j++) {
                        if (input[j] == ' ') {
                            t1.append(input.substr(0, j));
                            t2.append(input.substr(j + 1, input.length() - 1));
                            break;
                        }
                    }

                    //creates contact object
                    Contact newContact(t1, t2);

                    //calls filter function with name to compare to
                    Phonebook.treeSearchFilter(newContact);
                }
                break;
            }

                //quit operation
                //exits the program
            case 'Q':
            case 'q': {
                cout << "Exiting Phonebook application.";
                break;
            }
        }
    }
    return 0;
}