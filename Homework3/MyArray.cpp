// MyArray implementation

#include <iostream>
#include <sstream>
#include <algorithm>
#include <initializer_list>
#include <string>

#include "MyArray.h"

MyArray::MyArray(size_t size) {
    asize = size;
    aptr = new int[asize];
}
MyArray::MyArray(std::initializer_list<int> list) {
    asize = list.size();
     aptr = new int[asize];
    std::copy(std::begin(list), std::end(list), aptr);
}

MyArray::~MyArray() {
    std::cout << "MyArray destructor" << std::endl;
    delete[] aptr;

}
size_t MyArray::size() const noexcept {
    return asize;
}
std::string MyArray::toString() const {
    std::ostringstream output;
    output << "{";
    for (size_t i = 0; i < asize-1; i++) {
        output << aptr[i] << ", ";
    }
    output << aptr[asize-1] <<"}" << std::endl;
    return output.str();
}

int& MyArray::operator[](size_t index) {
    if (index >= asize)
        throw std::out_of_range("Index out of range");

    return aptr[index];
}
const int& MyArray::operator[](size_t index) const {
    if (index >= asize)
        throw std::out_of_range("Index out of range");

    return aptr[index];

}


std::ostream& operator<<(std::ostream& out, const MyArray& a) {
    out << a.toString();
    return out;
}

// // Copy constructor
// MyArray::MyArray (const MyArray& original) {
//     asize = original.size();
//     aptr = new int[asize];
//     std::copy(original.aptr, (original.aptr) + asize, this->aptr);

// } 
// // Copy assignment
// MyArray& MyArray::operator=(const MyArray& right) {
//     std::cout << "MyArray copy assignment operator " << std::endl;
//     asize = right.size();
//     aptr = new int[asize];
//     std::copy(right.aptr, (right.aptr) + asize, this->aptr);
//     return *this;
// } 