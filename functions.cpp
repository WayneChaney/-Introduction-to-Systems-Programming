// Purpose: 
// VanWayne Chaney 3/4/2022 Copyright 

// include necessary libraries
#include<iostream>

#include<vector>

#include<fstream>

bool caps(std::string words, std::string word2s) {
  int size = word2s.length(); // intialzing the size 
  if (words.length() > word2s.length()) //check which is bigger the first word or second 
    size = word2s.length();
  if (words.length() < word2s.length()) //check which is bigger the first word or second 
    size = words.length();
  bool equal = true; //equal variable 
  for (int i = 0; i < size; i++) { //loop through word 

    words[i] = toupper(words[i]); //make word upper case
  }
  for (int i = 0; i < size; i++) {
    word2s[i] = toupper(word2s[i]); //make second word all upper case 

  }
  if (words != word2s) { //see if words are the same
    equal = false; //wual false if not same 
  }

  return equal; // return equal
}
//list the names of the vector 
void listNames(const std::vector < std::string > & v) {
  int count = 0; //not needed
  for (auto item: v) {
    count++; //not needed
    if ((item.empty() == false)) //check if it is empty then print it 
      std::cout << item << std::endl;

  }
}
//list the days that people work using the string given 
void listDays(const std::string name,
  const std::string v, std::string realname) {
  int count = 0; //need this just in case there is no days.
  // also give you how many days

  if (v[6] == '1') { //check for sunday
    std::cout << "Sunday\n";
    count++;
  }
  if (v[5] == '1') { // check for monday
    std::cout << "Monday\n";
    count++;
  }
  if (v[4] == '1') { //check for tuesday 
    std::cout << "Tuesday\n";
    count++;
  }
  if (v[3] == '1') { //check for wednesday
    std::cout << "Wednesday\n";
    count++;
  }
  if (v[2] == '1') { //check for thursday
    std::cout << "Thursday\n";
    count++;
  }
  if (v[1] == '1') { //check for friday
    std::cout << "Friday\n";
    count++;
  }
  if (v[0] == '1') { //saturady
    std::cout << "Saturday\n";
    count++;
  }

  if (count == 0) { //count is 0
    std::cout << realname << " does not have a shift this week\n";

  }
}
//the first method
void Method1(const std::vector < std::string > & name,
  const std::vector < std::string > & workDay) {
  std::cout << "\n";
  bool exit1 = false; //eixit the big loop
  while (exit1 != true) { //while loop
    std::string realname;
    bool found = false; //found variable 
    int indexName; //variable is used to figure what input corresponds to the index for the workday vector
    std::string givenNames; //the name that the user inputs
    int there = 0; //variable is used to figure what input corresponds to the index for the workday vector
    std::cout << ">> Enter a nurse name:";
    std::cin >> givenNames; //the users input 
    realname = givenNames;
    std::cout << "\n";

    for (auto item: name) { //loop through vector and see if the name is in it
      if (caps(item, givenNames) == true) { //send to caps and see if they are equal
        std::cout << "---- Shift Days ----" << "\n";
        indexName = there;
        listDays(name[indexName], workDay[indexName], realname); //list the days for the specic person 
        exit1 = true; //exit the program
        found = true;
      }
      if (caps(item, givenNames) != true) { //check if name are not qual 
        there++; //increase index 

      }
      if (there > 19 && found == false) { //the check size is too big
        std::cout << "!!! No record for " << givenNames << "\n";
        //   exit1=true;
      }
    }
  }
}
//second method 
void Method2(const std::vector < std::string > & name,
  const std::vector < std::string > & workDay) {
  std::string day; //the day
  std::string finish; //check if the day
  int index;
  bool realDay = false;
  while (realDay != true) {
    std::cout << ">> Enter a day of the week:\n";
    std::cin >> day;

    if (caps("Monday", day)) { //check if its monday caps
      index = 5;
      realDay = true;
    } else if (caps("Tuesday", day)) { //check if its tuesdays caps
      index = 4;
      realDay = true;
    } else if (caps("Wednesday", day)) { //check if its wednesday
      index = 3;
      realDay = true;
    } else if (caps("Thursday", day)) { //check if its thrusday
      index = 2;
      realDay = true;
    } else if (caps("Friday", day)) { //chekc if its friday
      index = 1;
      realDay = true;
    } else if (caps("Saturday", day)) { //check if its saturday
      index = 0;
      realDay = true;
    } else if (caps("Sunday", day)) { //check if its sunday
      index = 6;
      realDay = true;
    }

  }
  // std::cout<<index<< "\n";
  int count = 0; //variable count how many people work on thoses days 
  std::vector < std::string > people; //a vector of people 

  for (int i = 0; i < workDay.size() - 1; i++) { //loop through the work day vector 

    //  std::cout<<workDay.size()<< "\n";

    //std::cout<<"this\n";
    if (!workDay[i].empty()) { //if its not  empty 

      if (workDay[i].at(index) == '1') { //if its 1 then they work there
        people.push_back(name[i]); //add people to the vector
        count++; //increase the amount of people
      }

    }
  }

  std::cout << "---- Nurses ----\n"; //print statement
  for (int i = 0; i < people.size(); i++) { //loop thorugh the people vecotr
    std::cout << people[i] << "\n"; //print the names 
  }
  for (int i = 0; i < day.length(); i++) { //make the day capital
    day[i] = toupper(day[i]);
  }
  std::cout << count << " nurse(s) work(s) on " << day << "\n"; //print statement with day 

}
//third method 
void Method3(const std::vector < std::string > & name,
  const std::vector < std::string > & workDay) {
  //intialize each day from 0-6
  int monday = 5;
  int tuesday = 4;
  int wensday = 3;
  int thursday = 2;
  int friday = 1;
  int saturday = 0;
  int sunday = 6;
  

  //intalize with boolean mon throuhg -sun
  
  bool monB = true;
  bool tueB = true;
  bool webB = true;
  bool thurB = true;
  bool friB = true;
  bool satB = true;
  bool sunB = true;
  int size = 0; //size for how many days 

  for (int i = 0; i < name.size(); i++) {
    if (workDay[i].empty()) //break out of the loop 
      i = name.size();
    size++; //increase size

  }

  for (int i = 0; i < size - 1; i++) { //loop thorught
    if (workDay[i].at(sunday) != '1') { //check if any dont have sunday
      sunB = false;
    }
    if (workDay[i].at(monday) != '1') { //check if any dont have monday 

      monB = false;
    }
    if (workDay[i].at(tuesday) != '1') { //check if any dont have tuesday
      tueB = false;
    }
    if (workDay[i].at(wensday) != '1') { //check if any dont have wednesday 
      webB = false;
    }
    if (workDay[i].at(thursday) != '1') { //check if any dont have thursday 
      thurB = false;
    }
    if (workDay[i].at(friday) != '1') { //check if any dont have friday 
      friB = false;
    }
    if (workDay[i].at(saturday) != '1') { //check if any dont have saturday 
      satB = false;
    }

  }
  std::cout << " --- Days that all nurses work --- \n"; //print statement and print each ay if its true
  int allDay = 0;

  if (sunB) {
    std::cout << "Sunday\n";
    allDay++;
  }
  if (monB) {
    allDay++;
    std::cout << "Monday\n";
  }
  if (tueB) {
    std::cout << "Tuesday\n";
    allDay++;
  }
  if (webB) {
    std::cout << "Wednesday\n";
    allDay++;
  }
  if (thurB) {
    std::cout << "Thursday\n";
    allDay++;
  }
  if (friB) {
    allDay++;
    std::cout << "Friday\n";
  }
  if (satB) {
    allDay++;
    std::cout << "Saturday\n";
  }

  if (allDay == 0)
    std::cout << "There is no day that all nurses work! \n";

}

//method list the names of nurses 
void Method4(const std::vector < std::string > & name,
  const std::vector < std::string > & workDay) {
  //intialize each day from 0-6
  int monday = 5;
  int tuesday = 4;
  int wensday = 3;
  int thursday = 2;
  int friday = 1;
  int saturday = 0;
  int sunday = 6;


  //intalize with boolean mon throuhg -sun
  
  bool monB = true;
  bool tueB = true;
  bool webB = true;
  bool thurB = true;
  bool friB = true;
  bool satB = true;
  bool sunB = true;
  int size = 0; //size 

  for (int i = 0; i < name.size(); i++) {
    if (workDay[i].empty()) //break loop, just need to see how big it is
      i = name.size();
    size++; //increase size

  }

  for (int i = 0; i < size - 1; i++) {
    if (workDay[i].at(monday) == '1') { //check if there is a one in anyones name and if it is the set to false 

      monB = false;
    }
    if (workDay[i].at(tuesday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      tueB = false;
    }
    if (workDay[i].at(wensday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      webB = false;
    }
    if (workDay[i].at(thursday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      thurB = false;
    }
    if (workDay[i].at(friday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      friB = false;
    }
    if (workDay[i].at(saturday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      satB = false;
    }
    if (workDay[i].at(sunday) == '1') { //check if there is a one in anyones name and if it is the set to false 
      sunB = false;
    }
  }
  std::cout << " --- Days no nurse works --- \n"; //print statement
  int allDay = 0;
  //if its true then print it 
  if (sunB) {
    std::cout << "Sunday\n";
    allDay++;
  }
  if (monB) {
    allDay++;
    std::cout << "Monday\n";
  }
  if (tueB) {
    std::cout << "Tuesday\n";
    allDay++;
  }
  if (webB) {
    std::cout << "Wednesday\n";
    allDay++;
  }
  if (thurB) {
    std::cout << "Thursday\n";
    allDay++;
  }
  if (friB) {
    allDay++;
    std::cout << "Friday\n";
  }
  if (satB) {
    allDay++;
    std::cout << "Saturday\n";
  }

  if (allDay == 0)
    std::cout << "Each day at least one nurse has a shift! \n";

}

//print the menu
void printMenu() { //prints the menu 
  std::cout << "--------------------------------\n";
  std::cout << " Nurse Shift Query Application\n";
  std::cout << "--------------------------------\n";
  std::cout << " 1 List shift days of the nurse\n";
  std::cout << " 2 List nurses for the day\n";
  std::cout << " 3 List days that all nurses work\n";
  std::cout << " 4 List days no nurse works\n";
  std::cout << " 5 List names of nurses\n";
  std::cout << "-1 Exit\n";
  std::cout << "--------------------------------\n";

}

// if needed, add other user-defined functions here

// Add functions  for menuOption 1 to 4

// if needed, add other user-defined functions here