#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>
using namespace std;

void Vector::grow(){
  size_t new_cap = capacity * 1.6;
  capacity = new_cap;
  int* new_ptr = new int[new_cap];
  for (int i = 0; i < n_elems; ++i){
    new_ptr[i] = data_ptr[i];
  }
  delete [] data_ptr;
  data_ptr = new_ptr;
  cout << "grow" << std::endl;
}

//Object Management
Vector::Vector(){
  data_ptr = new int[CHUNK];
  n_elems = 0;
  capacity = CHUNK;
}

Vector::Vector(const Vector& v){
  n_elems = v.n_elems;
  capacity = v.capacity;
  data_ptr = new int[capacity];
  for (int i = 0; i < n_elems; ++i){
    data_ptr[i] = v.data_ptr[i];
  }
}

Vector& Vector::operator=(const Vector& v){
  if (this != &v){
    delete [] data_ptr;
    n_elems = v.n_elems;
    capacity = v.capacity;
    data_ptr = new int[capacity];
    for (int i = 0; i < n_elems; i++){
      data_ptr[i] = v.data_ptr[i];
    }
  }
  return *this;
}

Vector::~Vector(){
  delete [] data_ptr;
}

//Accessors
int Vector::front() const{
  if (n_elems == 0){
    throw std::range_error("Position out of range.");
  }
  return data_ptr[0];
}

int Vector::back() const{
  if (n_elems == 0){
    throw std::range_error("Position out of range.");
  }
  return data_ptr[n_elems-1];
}

int Vector::at(size_t pos) const{
  if (pos >= n_elems){
    throw std::range_error("Position out of range.");
  }
  return data_ptr[pos];
}

size_t Vector::size() const{
  return n_elems;
}

bool Vector::empty() const{
  return n_elems == 0;
}

//Mutators
int& Vector::operator[](size_t pos){
  return data_ptr[pos];
}

void Vector::push_back(int item){
  if (n_elems >= capacity){
    this->grow();
  }
  data_ptr[n_elems] = item;
  ++n_elems;
}

void Vector::pop_back(){
  if (n_elems == 0){
    throw std::range_error("Position out of range.");
  }
  --n_elems;
}

void Vector::erase(size_t pos){
  if (pos >= n_elems){
    throw std::range_error("Position out of range.");
  }
  for (int i = pos; i < n_elems; i++){
    data_ptr[i] = data_ptr[i+1];
  }
  --n_elems;
}

void Vector::insert(size_t pos, int item){
  if (n_elems >= capacity){
    this->grow();
  }
  ++n_elems;
  for (int i = n_elems-1; i > pos; i--){
    data_ptr[i] = data_ptr[i-1];
  }
  data_ptr[pos] = item;
}

void Vector::clear(){
  n_elems = 0;
}

//Iterators
int* Vector::begin(){
  if (n_elems == 0){
    throw std::range_error("Position out of range.");
    return nullptr;
  }
  else{
    return &data_ptr[0];
  }
}

int* Vector::end(){
  if (n_elems == 0){
    throw std::range_error("Position out of range.");
    return nullptr;
  }
  else{
    return &data_ptr[n_elems];
  }
}

//Comparators
bool Vector::operator==(const Vector& v) const{
  if (n_elems != v.n_elems){
    return false;
  }
  for (int i = 0; i < n_elems; ++i){
    if (data_ptr[i] != v.data_ptr[i]){
      return false;
    }
  }
  return true;
}

bool Vector::operator!=(const Vector& v) const{
  if (n_elems != v.n_elems){
    return true;
  }
  for (int i = 0; i < n_elems; ++i){
    if (data_ptr[i] != v.data_ptr[i]){
      return true;
    }
  }
  return false;
}
