// Design a program to create a PDA that accepts well-parenthesized expressions using ()
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    stack<char> st;

    cout << "Enter expression containing parentheses: ";
    cin >> input;

    bool valid = true;

    for (char ch : input) {
        switch (ch) {
            case '(':
                st.push(ch);      // PDA push operation
                break;

            case ')':
                if (st.empty()) { // No matching '('
                    valid = false;
                } else {
                    st.pop();     // PDA pop operation
                }
                break;

            default:
                // Ignore other characters
                break;
        }

        if (!valid)
            break;
    }

    // PDA accepts if stack is empty and no error occurred
    if (valid && st.empty())
        cout << "Accepted: Well-parenthesized expression" << endl;
    else
        cout << "Rejected: Not a well-parenthesized expression" << endl;

    return 0;
}