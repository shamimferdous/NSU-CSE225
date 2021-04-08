#include "student.h"
#include "unsortedtype.cpp"

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
namespace patch
{
    template <typename T>
    std::string to_string(const T &n)
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

Student::Student()
{
    // cout << "Default constructor";
}

//defining the main constructor
Student::Student(int id, std::string name, float cgpa, UnsortedType<int> marks, int totalExams)
{
    this->id = id;
    this->name = name;
    this->cgpa = cgpa;
    this->marks = marks;
    this->totalExams = totalExams;
}

//defining the private findAverage method
float Student::findAverage()
{

    int temp, totalMarks = 0;
    float average;
    //declaring an array of length, number of exams which is essentially the length of the marks u-list
    int marksArr[marks.lengthIs()];

    //pushing all the marks from the marks list to the array
    for (int i = 0; i < marks.lengthIs(); i++)
    {
        marks.getNextItem(temp);
        marksArr[i] = temp;
    }
    marks.resetList();

    //using bubble-sorting algorithm to sort the marksArr arr in descending order
    for (int foo = 0; foo < marks.lengthIs() - 1; foo++)
    {
        for (int bar = 0; bar < marks.lengthIs() - foo - 1; bar++)
        {
            if (marksArr[bar] < marksArr[bar + 1])
            {
                temp = marksArr[bar];
                marksArr[bar] = marksArr[bar + 1];
                marksArr[bar + 1] = temp;
            }
        }
    }

    //now that the array is sorted finding totalmarks excluding worth two exams
    for (int i = 0; i < totalExams - 2; i++)
    {
        totalMarks = totalMarks + marksArr[i];
    }

    average = (float)totalMarks / (totalExams - 2);

    return average;
}

//defining examMarks method
std::string Student::examMarks()
{
    int temp;
    std::string marksString = "";

    for (int i = 0; i < marks.lengthIs(); i++)
    {
        marks.getNextItem(temp);
        marksString = i == marks.lengthIs() - 1 ? marksString + patch::to_string(temp) : marksString + patch::to_string(temp) + ", ";
    }

    return marksString;
}

//defining the less than operator overload method
bool Student::operator<(Student s)
{
    if (this->id > s.id)
        return true;
    else
        return false;
}

//defining the toString method
std::ostream &operator<<(std::ostream &os, Student &student)
{
    os
        << "ID: " << student.id << " ; Name: " << student.name << " ; CGPA: " << student.cgpa << " ; Exams: " << student.examMarks() << " ; Average Mark: " << fixed << std::setprecision(2) << student.findAverage() << endl;
    return os;
}