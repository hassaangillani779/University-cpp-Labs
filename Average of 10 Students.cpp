#include <iostream>
using namespace std;

int main()
{
    string name;
    float pf, aict, ap;
    float total, classTotal = 0;

    for(int i = 1; i <= 10; i++)
    {
        cout << "Enter name of student " << i << ": ";
        cin >> name;

        cout << "Enter marks of Programming Fundamentals: ";
        cin >> pf;

        cout << "Enter marks of AICT: ";
        cin >> aict;

        cout << "Enter marks of Applied Physics: ";
        cin >> ap;

        total = pf + aict + ap;

        cout << "Total marks of " << name << " = " << total << endl << endl;

        classTotal = classTotal + total;
    }

    float classAverage = classTotal / 10;

    cout << "Average marks of the whole class = " << classAverage << endl;

    return 0;
}
