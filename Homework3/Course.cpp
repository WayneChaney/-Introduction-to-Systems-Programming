// Copyright CVanWayne 2022
/*
Purpose: course.h
Date: 4/19/22
by Wayne Chaney
*/

// Write the implementation of each function in the course.h

// #include"course.h"

// using namespace std;


#include <sstream>

#include <algorithm>

#include <initializer_list>

#include <string>

#include <iostream>

#include "Course.h"

Course::Course(const std::string & courseName,
  const std::string & section, int capacity) {
  students = new std::string[capacity];
  this -> courseName = courseName;
  this -> section = section;
  this -> capacity = capacity;
  numberOfStudents = 0;
  std::cout << this -> getCourseName() << "-" <<
   this -> getSection() << " has been created!\n";
}
Course::~Course() {
  delete[] students;
  std::cout << this -> getCourseName() << "-" <<
  this -> getSection() << " has been deleted!\n";
}

//  overload copy constructor
//  Copy constructor
Course::Course(const Course & original) {
  //  course blamk = new course(orginal);
  capacity = original.getCourseCapacity();
  students = new std::string[capacity];

  for (int i = 0; i < capacity; i++) {
    students[i] = original.students[i];
  }
  //  this->students = original.students;
  //  aptr just students for that section
  this -> courseName = original.getCourseName();
  this -> section = original.getSection();
  this -> numberOfStudents = original.getNumberOfStudents();
  std::cout << "New " << this -> getCourseName() << "-" <<
  this -> getSection() << " has been created by the copy constructor!\n";
}
  //  overload copy assignment operator
Course & Course::operator = (const Course & right) {
  //  Cousec course = orignal
  //  std::cout << "Course copy assignment operator " << std::endl;

  capacity = right.getCourseCapacity();
  delete[] students;
  students = new std::string[capacity];

  for (int i = 0; i < capacity; i++) {
    students[i] = right.students[i];
  }
  //  this->students = original.students;
  //  aptr just students for that section

  this ->numberOfStudents = right.getNumberOfStudents();
  std::cout << "The content of  " << right.getCourseName() << "-" <<
   right.getSection() << " was copied to" << this -> getCourseName() <<
   "-" << this -> getSection() << " using operator=\n";
  this -> courseName = right.getCourseName();
  this -> section = right.getSection();
  return *this;
}
// oveload operator+= as a member function
Course & Course::operator += (const Course & right) {
  // Cousec course += orignal
  // std::cout << "Course copy assignment operator " << std::endl;
  int max = right.getCourseCapacity() + this -> getCourseCapacity();
  std::string * aptr = new std::string[max];

  for (int i = 0; i < max; i++) {
    if (i < numberOfStudents)
      aptr[i] = this -> students[i];  //  aptr just students for that section
    if (i >= numberOfStudents)
      aptr[i] = right.students[i - numberOfStudents];
  }

  delete[] students;
  students = aptr;
  // the loop is working
  //   for(int i = 0; i < max;i++){
  //   std::cout<<i<< "= "<<  students[i] <<"\n";
  //   }
  //      std::cout<<"=i   MADE It HERE\n" ;

  //  this->courseName +right.getCourseName();
  //  this->section +=right.getSection();
  this -> capacity = max;
  this -> numberOfStudents += right.getNumberOfStudents();
  std::cout << "The students of " << right.getCourseName() << "-" <<
   right.getSection() << " have been added to " << this -> getCourseName() <<
    "-" << this -> getSection() << " with the operator+=\n";

  return *this;
}
std::string Course::toString() const {
  std::ostringstream output;
  output << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  output << "Course Name: " << getCourseName() << "\n";
  output << "Section    : " << getSection() << "\n";
  output << "Capacity   : " << getCourseCapacity() << "\n";
  output << "#ofStudents: " << getNumberOfStudents() << "\n";
  output << "---------Student List------------\n";
  if (getNumberOfStudents() == 0) {
    output << "(no students to list)\n";
  } else {
    for (int i = 0; i < getNumberOfStudents(); i++) {
      output << i + 1 << ". " << students[i] << "\n";
    }
  }
  return output.str();
}
std::ostream & operator << (std::ostream & out,
  const Course & a) {
  out << a.toString();
  return out;
}

void Course::setCourseName(std::string name) {
  std::cout << "Course name " << this -> courseName << "-" << section <<
  "has been changed to " << name << "-" << section << "\n";
  courseName = name;
}
std::string Course::getCourseName() const {
  return courseName;
}
void Course::setSection(std::string section) {
  std::cout << "Course section " << courseName << "-" <<
  this -> section << "has been changed to " << section << "\n";
  this -> section = section;
}
std::string Course::getSection() const {
  return section;
}
void Course::addStudent(const std::string & name) {
  if (capacity == numberOfStudents) {  //  check if at capacity
    std::cout << "The course " << this -> getCourseName() << "-" <<
     this -> getSection() <<
    " has reached maximum capacity! You need to increase the capacity!!\n";
    return;
  }
  students[numberOfStudents] = name;
  numberOfStudents++;
  std::cout << name << " was added to " << this -> getCourseName() <<
   "-" << this -> getSection() << " successfully\n";
}
void Course::dropStudent(const std::string & name) {
// int max = right.getCourseCapacity() + this -> getCourseCapacity();
//   std::string * aptr = new std::string[max];

//   for (int i = 0; i < max; i++) {
//     if (i < numberOfStudents)
//       aptr[i] = this -> students[i];  //  aptr just students for that section
//     if (i >= numberOfStudents)
//       aptr[i] = right.students[i - numberOfStudents];
//   }

  int found = -1;  //  find variable
  if (0 == numberOfStudents) {
    std::cout << "cant remove\n";
    return;
  }
  //  make a new array to alter values and check if thery are there
  std::string * newRay = new std::string[numberOfStudents];  //  new array
  for (int i = 0; i < numberOfStudents; i++) {  //  loop through array
    if (name == students[i])
      found = i;
    newRay[i] = students[i];
  }
  // if its not found then end this
  if (found == -1) {  //  not found
    std::cout << "Student: " << name << " was not found!\n";
    return;
  }
  // flip the specific value to the end
  std::string temp = newRay[found];
  newRay[found] = newRay[numberOfStudents - 1];
  newRay[numberOfStudents - 1] = temp;

  // put values in to students array
  // for (int i = 0; i < numberOfStudents; i++) {
  //   //  loop through array //replace array
  //   if (i == numberOfStudents - 1)  //  check if end
  //     i = numberOfStudents;
  //   else
  //     students[i] = newRay[i];
  // }
students = newRay;
  //  for(int i =0; i< numberOfStudents;i++){
  //           if(found >= i)
  //           students[i] = students[i+1];
  //           if (found <i)
  //                 students[i] = students[i];
  //       }
  //  for(int i =0; i< numberOfStudents;i++){
  //     std::cout<< students[i] << "\n";
  //  }
  numberOfStudents = numberOfStudents - 1;

  // flip

  //    std::cout<<"[0]"<<students[0]<<std::endl;
  //  std::cout<<"[1]"<<students[1]<<std::endl;

  std::cout << "Student: " << name << " dropped the course " <<
   courseName << "-" << section << "\n";
}
int Course::getNumberOfStudents() const {
  return numberOfStudents;
}
int Course::getCourseCapacity() const {
  return capacity;
}
void Course::shrinkCapacity() {
  if (capacity > numberOfStudents) {
    capacity = numberOfStudents;

    std::cout << "The Capacity of " << courseName << "-" <<
    section << " is now equal to the number of students\n" <<
      std::endl;
  } else {
  std::cout << "No need to shrink !! Capacity is equal to the number ";
  std::cout <<"of students for " << courseName << "-" << section << std::endl;
}
}

void Course::increaseCapacity(unsigned inc) {
  // int max = right.getCourseCapacity() + this -> getCourseCapacity();
//   std::string * aptr = new std::string[max];

//   for (int i = 0; i < max; i++) {
//     if (i < numberOfStudents)
//       aptr[i] = this -> students[i];  //  aptr just students for that section
//     if (i >= numberOfStudents)
//       aptr[i] = right.students[i - numberOfStudents];
//   }
  capacity = capacity + inc;  //  increased the capacity

std::string * newRay = new std::string[capacity];  //  new array
  for (int i = 0; i < capacity; i++) {  //  loop through array
    if (i < numberOfStudents)
      newRay[i] = students[i];
  }
  delete[] students;

  // for (int i = 0; i < capacity; i++) {  //  loop through array
  //   if (i < numberOfStudents)
  //     students[i] = newRay[i];
  // }
  students = newRay;

  std::cout << "The Capacity of " << this -> getCourseName() << "-" <<
  this -> getSection() << " has been increased by " << inc << std::endl;
}

std::string Course::getStudents(int index) {
  return students[index];
}
