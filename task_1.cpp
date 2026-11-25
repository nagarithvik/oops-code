#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
    static int count;

public:
    Student(int r, string n, float m) : rollNo(r), name(n), marks(m) {
        count++;
    }

    ~Student() {
        count--;
    }

    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    float getMarks() const { return marks; }

    void setMarks(float m) {
        if (m >= 0 && m <= 100) marks = m;
        else cout << "Invalid marks! Must be between 0 and 100.\n";
    }

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }

    void display(bool showMarks) const {
        display();
        if (showMarks) cout << "Marks : " << fixed << setprecision(2) << marks << endl;
    }

    static int getCount() { return count; }

    bool operator>(const Student &other) const {
        return marks > other.marks;
    }

    friend void showDetails(const Student &s);
};

int Student::count = 0;

void showDetails(const Student &s) {
    cout << "[Friend] " << s.name << " (Roll " << s.rollNo
         << ") scored " << fixed << setprecision(2) << s.marks << " marks." << endl;
}

int main() {
    cout << "===== Student Management using OOP in C++ =====\n\n";

    Student s1(101, "Aarav", 85.5);
    Student s2(102, "Diya", 92.0);
    Student s3(103, "Rohan", 78.25);

    cout << "Total students created: " << Student::getCount() << "\n\n";

    cout << "--- Student Details (overloaded display) ---\n";
    s1.display();
    cout << endl;
    s2.display(true);
    cout << endl;
    s3.display(true);

    cout << "\n--- Friend Function ---\n";
    showDetails(s1);
    showDetails(s2);
    showDetails(s3);

    cout << "\n--- Comparison using overloaded > operator ---\n";
    if (s1 > s2) cout << s1.getName() << " has higher marks than " << s2.getName() << endl;
    else         cout << s2.getName() << " has higher marks than " << s1.getName() << endl;

    if (s1 > s3) cout << s1.getName() << " has higher marks than " << s3.getName() << endl;
    else         cout << s3.getName() << " has higher marks than " << s1.getName() << endl;

    cout << "\n--- Dynamic object creation ---\n";
    Student *p = new Student(104, "Meera", 88.0);
    p->display(true);
    cout << "Total students now: " << Student::getCount() << endl;
    delete p;
    cout << "After deleting Meera, total students: " << Student::getCount() << endl;

    return 0;
}