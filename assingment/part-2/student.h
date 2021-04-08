#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
#include "unsortedtype.h"

class Student
{
private:
    int id;
    std::string name;
    float cgpa;
    UnsortedType<int> marks;
    int totalExams;
    float findAverage();
    std::string examMarks();

public:
    Student();
    Student(int, std::string, float, UnsortedType<int>, int);
    bool operator<(Student s);
    friend std::ostream &operator<<(std::ostream &, Student &);
};
#endif // STUDENT_H_INCLUDED