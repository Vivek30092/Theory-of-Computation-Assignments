// Design a program for PDA to accept WCW<sup>R where w is any string and W<sup>R is the reverse of that string and C is a Special symbol.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    stack<char> st;

    cout << "Enter string of form wCwR: ";
    cin >> str;

    bool foundC = false;
    bool valid = true;

    for (char ch : str) {
        switch (ch) {
            case 'c':
            case 'C':
                if (foundC) { // More than one C
                    valid = false;
                } else {
                    foundC = true;
                }
                break;

            default:
                if (!foundC) {
                    // Push symbols before C
                    st.push(ch);
                } else {
                    // Match symbols after C
                    if (st.empty() || st.top() != ch) {
                        valid = false;
                    } else {
                        st.pop();
                    }
                }
                break;
        }

        if (!valid)
            break;
    }

    if (valid && foundC && st.empty())
        cout << "String Accepted" << endl;
    else
        cout << "String Rejected" << endl;

    return 0;
}