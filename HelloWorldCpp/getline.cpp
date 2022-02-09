#include <iostream>
#include <string>
using namespace std;

/*
 *      Note 1: getline();
 *  Using cin on strings with whitespaces will only capture the first word,
 *  so it is preferrable to use getline (cin, str);
 * 
 * 
 * 
 */

int main() {
	string fullName;
	cout << "Enter your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName;
    return 0;
}