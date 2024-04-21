// Experiment 1
// Create a structure for student which should contain fields like roll No., name, CGPI, semester. Create an array of structure student to store this information about 10 students. Write individual functions to perform the following task:
// (a)	Insert a new record of student at kth position (value of k will be entered by the user at run time).
// (b)	Display the record of all students.
// (c)	Display records of all students having CGPI greater than k (value of k will be entered by the user at run time).

// Write a menu-driven program to implement above operations.

#include <iostream>
using namespace std;

struct student
{
  string name;
  int roll;
  float CGPI;
  int sem;
};

void enterData(student student[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "Roll No. " << i + 1 << endl;
    cout << "Enter the name : " << endl;
    cin >> student[i].name;
    cout << "Enter the CGPI : " << endl;
    cin >> student[i].CGPI;
    cout << "Enter the semester : " << endl;
    cin >> student[i].sem;
  }
}

void displayData(student student[], int size)
{
  cout << "The details are : " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Student " << i + 1 << endl;
    cout << "Roll Number " << i + 1 << endl;
    cout << "Name : " << student[i].name << endl;
    cout << "CGPI : " << student[i].CGPI << endl;
    cout << "Semester : " << student[i].sem << endl;
  }
}

void cgpiGreater(student student[], int k, int size)
{
  cout << "CGPI greater than "
       << " " << k << endl;
  for (int i = 0; i < size; i++)
  {
    if (student[i].CGPI > k)
    {
      cout << student[i].CGPI << endl;
    }
  }
}

void enterNewRecord(student student[], int k)
{
  cout << "Enter the roll number " << student[k].roll << endl;
  cout << "Enter the name " << student[k].name << endl;
  cout << "Enter the semester " << student[k].sem << endl;
  cout << "Enter the CGPI " << student[k].CGPI << endl;
}

int main()
{
  int n;
  int cgp;
  cout << "Enter the total number of students : ";
  cin >> n;
  student student[n];
  enterData(student, n);
  displayData(student, n);
  cout << "Enter the CGPI to compare : ";
  cin >> cgp;
  cgpiGreater(student, cgp, n);
  return 0;
}