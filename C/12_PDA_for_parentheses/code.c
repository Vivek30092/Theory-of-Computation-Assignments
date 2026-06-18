/* Question:
   Design a program to create a PDA that accepts well-parenthesized expressions using ().
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

int empty() {
    return top == -1;
}

int main() {
    char input[1000];

    printf("Enter expression containing parentheses: ");
    if (scanf("%999s", input) != 1) {
        return 0;
    }

    int valid = 1;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        switch (ch) {
            case '(':
                push(ch);      // PDA push operation
                break;

            case ')':
                if (empty()) { // No matching '('
                    valid = 0;
                } else {
                    pop();     // PDA pop operation
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
    if (valid && empty())
        printf("Accepted: Well-parenthesized expression\n");
    else
        printf("Rejected: Not a well-parenthesized expression\n");

    return 0;
}
