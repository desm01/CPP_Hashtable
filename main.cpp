#include <iostream>

#include "Library.h"
#include "HashTable.h"

using namespace std;

int main() {

    size_t tablesize = 2048;

    HashTable<Library> HTable(tablesize);

    Library harryPotter("Harry Potter & Chamber Of Secrets", 10283);
    Library cppForBegineers("Bjarne Stroustrup, C++ For Begineers", 7539573);
    Library dune("Dune", 38403404);
    Library doAndroids("Do Androids Dream Of Electric Sheep?", 438943);
    Library genghisKan("The Life Of Genghis Khan", 2323);
    Library snowcrash("Snowcrash", 84639573);
    Library facebook("Facebook: The inside story", 43843);

    HTable.insert(harryPotter);
    HTable.insert(cppForBegineers);
    HTable.insert(dune);
    HTable.insert(doAndroids);
    HTable.insert(genghisKan);
    HTable.insert(snowcrash);
    HTable.insert(facebook);

    char yn = 'y';

    do {
        cout << "Which book would you like to checkout?\nEnter the ISBN" << endl;
        int isbn = 0; 
        cin >> isbn;

        Library enquiry("", isbn);

        size_t index = HTable.find(enquiry);

        if (enquiry.get_value() == "") {
            cout << "Error that book is not in our system\n" << endl;
        }
        
        else {
        
        cout << "Index: " << index << endl;
        cout << "Name : " << enquiry.get_value() << endl;
        cout << "ISBN: " << enquiry.get_key() << endl; 
        }

        cout << "Another? (y/n)" << endl;
        cin >> yn;
    }

    while(yn == 'y');



    return 0;
}