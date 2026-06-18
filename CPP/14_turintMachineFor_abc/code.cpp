#include <iostream>
#include <string>
using namespace std;

int main() {
    string tape;
    cout << "Enter string (a^n b^n c^n): ";
    cin >> tape;

    bool reject = false;

    while (true) {
        int i;

        // Find leftmost unmarked a
        for (i = 0; i < tape.length(); i++) {
            if (tape[i] == 'a')
                break;
        }

        // No a left
        if (i == tape.length())
            break;

        tape[i] = 'X';

        // Find matching b
        bool foundB = false;
        for (int j = i + 1; j < tape.length(); j++) {
            switch (tape[j]) {
                case 'a':
                case 'X':
                    break;

                case 'b':
                    tape[j] = 'Y';
                    foundB = true;
                    j = tape.length();
                    break;
            }
        }

        if (!foundB) {
            reject = true;
            break;
        }

        // Find matching c
        bool foundC = false;
        for (int j = 0; j < tape.length(); j++) {
            switch (tape[j]) {
                case 'a':
                case 'b':
                case 'X':
                case 'Y':
                    break;

                case 'c':
                    tape[j] = 'Z';
                    foundC = true;
                    j = tape.length();
                    break;
            }
        }

        if (!foundC) {
            reject = true;
            break;
        }
    }

    // Final verification
    if (!reject) {
        for (char ch : tape) {
            switch (ch) {
                case 'X':
                case 'Y':
                case 'Z':
                    break;

                default:
                    reject = true;
            }

            if (reject)
                break;
        }
    }

    if (!reject)
        cout << "String Accepted" << endl;
    else
        cout << "String Rejected" << endl;

    return 0;
}