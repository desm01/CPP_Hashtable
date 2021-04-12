#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
using std::string;

//using namespace std;

class Library {
    public:
        Library(string book_name, int isbn):
            book_name(book_name), isbn(isbn) {};

        string get_value() const { return book_name; }
        int get_key() const { return isbn ;}

        

        void set_value(string name) { book_name = name; }

        size_t hash_index() {
            return isbn;
        }


    private:
        string book_name;
        int isbn;

};

#endif