#include <iostream>
using namespace std;

int calculation(int one, int two, char opr);

int main() {

    int firstNum;
    int secondNum;
    char opr;

    cout << "Calculator 1.0\n";
    cout << "Enter the first number: ";
    cin >> firstNum;
    cout << "Enter the operator: ";
    cin >> opr;
    cout << "Enter the second number: ";
    cin >> secondNum;
    int output = calculation(firstNum, secondNum, opr);
    cout << "\nAnswer: " << output;
}

int calculation(int one, int two, char opr) {
    int output;
    switch (opr) {
        case '+':
            output = one + two;
            break;
        case '-':
            output = one - two;
            break;
        case '*':
            output = one * two;
            break;
        case '/':
            output = one / two;
            break;
        default:
            cout << "Invalid operator";
            output = 0;
    }
    return output;
}