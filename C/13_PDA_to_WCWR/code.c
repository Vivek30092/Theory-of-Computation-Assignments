/* Question:
   Design a program for PDA to accept wCwR where w is any string and wR is the reverse of that string and C is a Special symbol.
*/

#include <stdio.h>

#define MAX_STACK 1000

char st[MAX_STACK];
int top = -1;

void push(char val) {
    if (top < MAX_STACK - 1) {
        st[++top] = val;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

char get_top() {
    if (top >= 0) {
        return st[top];
    }
    return '\0';
}

int empty() {
    return top == -1;
}

int main() {
    char str[1000];

    printf("Enter string of form wCwR: ");
    if (scanf("%999s", str) != 1) {
        return 0;
    }

    int foundC = 0;
    int valid = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (ch) {
            case 'c':
            case 'C':
                if (foundC) { // More than one C
                    valid = 0;
                } else {
                    foundC = 1;
                }
                break;

            default:
                if (!foundC) {
                    // Push symbols before C
                    push(ch);
                } else {
                    // Match symbols after C
                    if (empty() || get_top() != ch) {
                        valid = 0;
                    } else {
                        pop();
                    }
                }
                break;
        }

        if (!valid)
            break;
    }

    if (valid && foundC && empty())
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
