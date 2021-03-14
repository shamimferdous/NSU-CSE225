#include "studentInfo.h"
#include <iostream>
using namespace std;

studentInfo::studentInfo()
{
    // cout << "Creating obj with empty constructor";
}

studentInfo::studentInfo(int id)
{
    this->id = id;
}

studentInfo::studentInfo(int id, string name, double CGPA)
{
    this->id = id;
    this->name = name;
    this->CGPA = CGPA;
}

bool studentInfo::operator==(studentInfo s)
{
    if (this->id == s.id)
        return true;
    else
        return false;
}
bool studentInfo::operator!=(studentInfo s)
{
    if (this->id != s.id)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &os, studentInfo &student)
{
    os << student.id << "," << student.name << "," << student.CGPA << endl;
    return os;
}
