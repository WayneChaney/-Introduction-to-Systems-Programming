// MyArray Class decleration

#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

class MyArray {
    friend std::istream& operator>>(std::istream& in, MyArray& a);
  public:
    MyArray(size_t size);
    MyArray(std::initializer_list<int> list);
    ~MyArray(); // destructor

    size_t size() const noexcept;
    std::string toString() const;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // MyArray(const MyArray& original);  // copy constructor
    // MyArray& operator=(const MyArray& right);  // copy assignment operator
  private:
    size_t asize = 0;
    int * aptr;
};

std::ostream& operator<<(std::ostream& out, const MyArray& a);
