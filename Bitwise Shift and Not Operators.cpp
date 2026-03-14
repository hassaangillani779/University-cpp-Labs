#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int notResult = ~num;
    int leftShift = num << 1;
    int rightShift = num >> 1;

    cout << "Bitwise NOT (~num): " << notResult << endl;
    cout << "Left Shift (num << 1): " << leftShift << endl;
    cout << "Right Shift (num >> 1): " << rightShift << endl;

    return 0;
}
