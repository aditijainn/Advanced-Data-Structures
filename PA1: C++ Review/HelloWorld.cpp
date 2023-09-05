#include <iostream>
#include <string>
using namespace std;

/**
 * Ask user to enter their name, and then greet them
 */
int main() {
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!\nWelcome to CSE 100!";

    if(cin.fail()) {
        cerr << "Bad input!" << endl;
    }
}
