#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
using std::vector;

template <class X>

//  Define variables and methods

class HashTable {
    public:
        HashTable(size_t table_size, double load_threshold = 0.75);
        ~HashTable();

        size_t find(X& a);

        bool insert(X& a);

    private:
        vector<X*> Table;
        size_t num_x;
        double LOAD_TH;
};

//  Constructor

template <class X>
HashTable<X>::HashTable(size_t table_size, double load_threshold) 
    : LOAD_TH(load_threshold) 
    {
        for (size_t i = 0; i < table_size; i++) {
            Table.push_back(NULL);
        }
        num_x = 0;
    }


//  Destructor

template <class X>
HashTable<X>::~HashTable() {
    for (size_t i = 0; i < Table.size(); i++) {
        if (Table[i]) {
            delete Table[i];
        }
    }
}

//  Search for entry in the table

template <class X>
size_t HashTable<X>:: find(X& a) {
    size_t index = a.hash_index() % Table.size();
    
    while (Table[index] != NULL && Table[index]->get_key() != a.get_key()) 
    {
        index = (index + 1) & Table.size();
    }

    if (Table[index] != NULL) {
        a.set_value(Table[index]->get_value());
    }

    return index;
}

//  Insert object into the table

template<class X>
bool HashTable<X>::insert(X& a) 
{
    double load_factor = (double) num_x / (double) Table.size();

    if (load_factor > LOAD_TH) {
        return 0;
    }

    size_t index = find(a);

    if (Table[index] == NULL) {
        Table[index] = new X(a);
        num_x++;
        return 1;
    }
    
    return 0;
}


#endif
