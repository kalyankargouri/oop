#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public: 
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollNumber;
    string branch;
    float marks[5]; 
    float CGPA;
public:
    Student(string n, int a, int roll, string br, float m[5]) : Person(n, a), rollNumber(roll), branch(br) {
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
        calculateCGPA();
    }   
    void calculateCGPA() {
        float totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
        }
        CGPA = totalMarks / 5.0;  
    }
   
    void display() override {
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
        cout << "CGPA: " << CGPA << endl;
    }
    friend class Administration;
};

class Faculty : public Person {
protected:
    int facultyID;
    string department;
    float salary;
public: 
    Faculty(string n, int a, int id, string dept, float sal) : Person(n, a), facultyID(id), department(dept), salary(sal) {}
  
    void display() override {
        Person::display();
        cout << "Faculty ID: " << facultyID << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
    friend class Administration;
};

class TeachingAssistant : public Student, public Faculty {
public:  
    TeachingAssistant(string n, int a, int roll, string br, float m[5], int id, string dept, float sal) 
        : Student(n, a, roll, br, m), Faculty(n, a, id, dept, sal) {}   
    void display() override {
        Faculty::display();
    }
};
class Administration {
public:  
    void displayPrivateDetails(Student& s, Faculty& f) {
        cout << "---- Administration friend function----" << endl;
        cout << "Student name " << s.name << " from "<<s.branch<<" scored "<<s.marks[5]<<endl;
        cout << "Faculty name " << f.name<<" teaches ITBM" << endl;
    }
};
int main() { 
    float studentMarks[5] = {8.5, 9.0, 7.9, 9.5, 8.5};  
    Student s1("Tejshree", 20, 49, "CSE(AI-ML)", studentMarks);
    Faculty f1("Rekha Kamble", 30, 1001, "Computer Science", 75000);
    TeachingAssistant ta1("Mahajan sir", 40, 102, "AI-ML", studentMarks, 1002, "AI-ML", 80000); 
    cout << "Student Details: " << endl;
    s1.display();
    cout << endl;   
    cout << "Faculty Details: " << endl;
    f1.display();
    cout << endl;    
    cout << "Teaching Assistant Details: " << endl;
    ta1.display();
    cout << endl;   
    Administration admin;
    admin.displayPrivateDetails(s1, f1);
   return 0;
}

			
			
		




