// #include "unsortedtype.cpp"
#include "student.cpp"

#include <iostream>
using namespace std;

void Print(UnsortedType<Student> list) //not using pointer to keep the original list intact
{
    //this method sorts the unsorted list in ascending order (operator overloading is used)
    list.sortListInAscOrder();

    Student tempStudent;
    cout << endl;
    for (int i = 0; i < list.lengthIs(); i++)
    {
        list.getNextItem(tempStudent);
        cout << tempStudent;
    }
}

int main()
{
    int number_of_students, total_exams_taken;

    cout << "Number of students in CSE225?: ";
    cin >> number_of_students;

    cout << "Number of Exams?: ";
    cin >> total_exams_taken;

    //creating a sutdentList object
    UnsortedType<Student> studentList;

    //vars for taking user iput
    int id, mark;
    string name;
    float cgpa;
    int number_of_attended_exam;
    UnsortedType<int> student_marks;
    for (int i = 0; i < number_of_students; i++)
    {
        cout << endl
             << "Student ID: ";
        cin >> id;

        cout << "Student Name: ";
        cin >> name;

        cout << "Student CGPA: ";
        cin >> cgpa;

        cout << "Number of Exams attended: ";
        cin >> number_of_attended_exam;

        for (int i = 0; i < number_of_attended_exam; i++)
        {
            cout << "Exam " << i << ": ";
            cin >> mark;
            student_marks.insertItem(mark);
        }

        Student newStudent(id, name, cgpa, student_marks, total_exams_taken); //creating newStudent obj with usergiven data
        studentList.insertItem(newStudent);                                   //inserting the newStudent object to the studentList

        student_marks.makeEmpty(); //emptying the student_marks list
    }

    //printing the studentList
    Print(studentList);

    // UnsortedType<int> marks;
    // Student s1(141, "shamim", 3.99, marks, 5);
    // Student s2(111, "shamim", 3.99, marks, 5);
    // Student s3(142, "shamim", 3.99, marks, 5);
    // Student s4(111, "shamim", 3.99, marks, 5);
    // Student s5(101, "shamim", 3.99, marks, 5);
    // UnsortedType<Student> dummy;
    // dummy.insertItem(s1);
    // dummy.insertItem(s2);
    // dummy.insertItem(s3);
    // dummy.insertItem(s4);
    // dummy.insertItem(s5);

    // Print(dummy);

    return 0;
}
