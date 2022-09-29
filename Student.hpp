#pragma once
#include <cstring>
#include <iostream>

using namespace std;
class Student
{
  private:
    int id;
    string firstName;
    string middleName;
    string lastName;
  
  public:
    Student(int id, string firstName, string middleName, string lastName) : id(id), firstName(firstName), middleName(middleName), lastName(lastName) {}
    Student() : id(0) {}
  
  public:
    int GetId() const              { return this->id; }
    string GetFirstName() const    { return this->firstName; }
    string GetMiddleName() const   { return this->middleName; }
    string GetLastName() const     { return this->lastName; }
    void Print() const             { cout << this->id << ' ' << this->firstName << ' '  << this->middleName << ' ' << this->lastName << '\n'; }
    
    bool operator == (const Student& another) { return (this->firstName == another.GetFirstName() && this->middleName == another.GetMiddleName() && this->lastName == another.GetLastName()); }
    bool operator != (const Student& another) { return (this->firstName == another.GetFirstName() && this->middleName == another.GetMiddleName() && this->lastName == another.GetLastName()); }
    bool operator > (const Student& another) { return this->id > another.GetId(); }
    bool operator < (const Student& another) { return this->id < another.GetId(); }
    Student& operator = (const Student* another)
    {
      if(this == another) return *this;
      this->id          = another->GetId();
      this->firstName   = another->GetFirstName();
      this->middleName  = another->GetMiddleName();
      this->lastName    = another->GetLastName();

      return *this;
    }
};