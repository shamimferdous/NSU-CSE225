#include <iostream>
#include "unsortedtype.cpp"
#include "studentInfo.cpp"
using namespace std;

int main()
{
    //creating a list of integers
    UnsortedType<int> ul;

    if (ul.isEmpty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }

    //inserting four items
    int temp;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        ul.insertItem(temp);
    }

    //printing the list
    cout << endl;
    for (int i = 0; i < ul.lengthIs(); i++)
    {
        ul.getNextItem(temp);
        cout << temp << "\t";
    }
    ul.resetList();

    //printing length of the list
    cout << endl
         << "Length of the list: " << ul.lengthIs() << endl;

    //inserting one item
    ul.insertItem(5);

    //printing the list
    cout << endl;
    for (int i = 0; i < ul.lengthIs(); i++)
    {
        ul.getNextItem(temp);
        cout << temp << "\t";
    }
    ul.resetList();

    //retriving 4 user given items
    bool isFound = false;
    for (int i = 0; i < ul.lengthIs(); i++)
    {
        cout << endl
             << "Enter a number: ";
        cin >> temp;
        ul.retriveItem(temp, isFound);

        cout << (isFound ? "Found" : "Not Found") << endl;
    }

    //priniting if the list is full or not
    if (ul.isFull())
    {
        cout << "List is full!" << endl;
    }
    else
    {
        cout << "List is not full!" << endl;
    }

    //deleting 5 and displaying if list is full or not
    ul.deleteItem(5);
    if (ul.isFull())
    {
        cout << "List is full!" << endl;
    }
    else
    {
        cout << "List is not full!" << endl;
    }

    //deleting 1 and printing the list
    ul.deleteItem(1);
    cout << endl;
    for (int i = 0; i < ul.lengthIs(); i++)
    {
        ul.getNextItem(temp);
        cout << temp << "\t";
    }
    ul.resetList();

    //deleting 6 and printing the list
    ul.deleteItem(1);
    cout << endl;
    for (int i = 0; i < ul.lengthIs(); i++)
    {
        ul.getNextItem(temp);
        cout << temp << "\t";
    }
    ul.resetList();

    //creating studentInfo object
    UnsortedType<studentInfo> students;

    //inserting 5 students record
    studentInfo student_1(15234, "Jon", 2.6),
        student_2(13732, "Tyrion", 3.9),
        student_3(13569, "Sandor", 1.2),
        student_4(15467, "Ramsey 2", 3.1),
        student_5(16285, "Arya", 3.1);

    students.insertItem(student_1);
    students.insertItem(student_2);
    students.insertItem(student_3);
    students.insertItem(student_4);
    students.insertItem(student_5);

    //deleting the record with id 15467
    studentInfo tempStudentD = 15467;
    students.deleteItem(tempStudentD);

    // Retrieve the record with ID 13569
    studentInfo tempStudent = 13569;
    bool isStudentIsFound = false;
    students.retriveItem(tempStudent, isStudentIsFound);

    if (isStudentIsFound)
    {
        cout << endl
             << "Student is found" << endl;
        cout << student_3;
    }

    //printing the list
    cout << endl
         << "\t";
    for (int i = 0; i < students.lengthIs(); i++)
    {
        students.getNextItem(tempStudent);
        cout << tempStudent << "\t";
    }
    ul.resetList();

    return 0;
}