#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include <cstddef>
#include <stdexcept>
using std::size_t;

class Vector {
    enum {CHUNK = 10};
    int* data_ptr;      // Pointer to the heap array
    size_t capacity;    // Size of the current array allocation (total number of ints, in use or not)
    size_t n_elems;     // Number of int spaces currently in use, starting from position 0
    void grow();
    
public:
    // Object Mgt.
    Vector();
    Vector(const Vector& v);
    Vector& operator=(const Vector& v);
    ~Vector();

    // Accessors
    int front() const;
    int back() const;
    int at(size_t pos) const;
    size_t size() const;
    bool empty() const;

    // Mutators
    int& operator[](size_t pos);
    void push_back(int item);
    void pop_back();
    void erase(size_t pos);
    void insert(size_t pos, int item);
    void clear();
    
    // Iterators
    int* begin();
    int* end();

    // Comparators
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;
};
#endif