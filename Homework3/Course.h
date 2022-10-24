// Copyright CVanWayne 2022
/*
Purpose: course.h
Date: 4/19/22
by Wayne Chaney
*/

#ifndef C__USERS_SCHOOL_WAYNE_DESKTOP_JUNIOR_YEAR_CSE278_HW_HW3_COURSE_H_
#define C__USERS_SCHOOL_WAYNE_DESKTOP_JUNIOR_YEAR_CSE278_HW_HW3_COURSE_H_
#include <string>
#endif


class Course {
  // define operator<< as a friend function for Course

  friend std::ostream & operator << (std::ostream & out,
    const Course & a);

 public:
  Course(const std::string & courseName,
      const std::string & section, int capacity);
  ~Course();
  // overload copy constructor
  Course(const Course & original);  // copy constructor
  // overload copy assignment operator
  Course & operator = (const Course & right);
  void setCourseName(std::string name);
  std::string getCourseName() const;
  void setSection(std::string section);
  std::string getSection() const;
  void addStudent(const std::string & name);
  void dropStudent(const std::string & name);
  int getNumberOfStudents() const;
  int getCourseCapacity() const;
  void shrinkCapacity();
  void increaseCapacity(unsigned inc);
  std::string getStudents(int index);
  // copy assignment operator
  std::string toString() const;

  // oveload operator+= as a member function
  Course & operator += (const Course & right);

 private:
  std::string courseName;
  std::string section;
  std::string * students;
  int numberOfStudents;
  int capacity;
};
