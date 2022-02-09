#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    double y;
    char opr;
    int output;
    string firstName;
    string lastName;
    string fullName;
    cout << "What is your first name? ";
    cin >> firstName;
    cout << "What is your last name? ";
    cin >> lastName;
    firstName += " ";
    cout << "testprint: " + fullName;
    cout << "Your full Name has been registered as: " << firstName.append(lastName) << endl;
    cout << "Input first number: ";
    cin >> x;
    cout << "Input operation to be performed: ";
    cin >> opr;
    cout << "Input second number: ";
    cin >> y;
    if (opr=='+') {
        cout << x + y;
    } else if (opr=='-') {
        cout << x - y;
    } else if (opr=='*') {
        cout << x * y;
    } else if (opr=='/') {
        cout << x / y;
    } else {
        cout << "Incorrect operation";
    }
    return 0;
}