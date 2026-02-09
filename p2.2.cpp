#include <iostream>
using namespace std;

class University
{
    int roll;
    string name;
    float m1, m2, m3;

public:
    University();
    University(int, string, float, float, float);
    float average();
    void display();
};



University::University()
{
    roll = 1;
    name = "Test";
    m1 = 50;
    m2 = 69;
    m3 = 90;
}


University::University(int r, string n, float a, float b, float c)
{
    roll = r;
    name = n;
    m1 = a;
    m2 = b;
    m3 = c;
}


float University::average()
{
    return (m1 + m2 + m3) / 3;
}


void University::display()
{
    cout << "Roll No: " << roll << endl;
    cout << "Name: " << name << endl;
    cout << "Average Marks: " << average() << endl;
    cout << "------------------" << endl;
}

int main()
{

    University s1;


    int roll;
    string name;
    float m1, m2, m3;

    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 3 Marks: ";
    cin >> m1 >> m2 >> m3;

    University s2(roll, name, m1, m2, m3);


    s1.display();
    s2.display();

    return 0;
}
