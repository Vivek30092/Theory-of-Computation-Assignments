/* Question:
   Design a program for Turing machine that accepts the language a^n b^n c^n where n > 0.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char tape[1000];
    printf("Enter string (a^n b^n c^n): ");
    if (scanf("%999s", tape) != 1) {
        return 0;
    }

    int reject = 0;
    int len = strlen(tape);

    while (1) {
        int i;

        // Find leftmost unmarked a
        for (i = 0; i < len; i++) {
            if (tape[i] == 'a')
                break;
        }

        // No a left
        if (i == len)
            break;

        tape[i] = 'X';

        // Find matching b
        int foundB = 0;
        for (int j = i + 1; j < len; j++) {
            switch (tape[j]) {
                case 'a':
                case 'X':
                    break;

                case 'b':
                    tape[j] = 'Y';
                    foundB = 1;
                    j = len; // break inner loop
                    break;
            }
        }

        if (!foundB) {
            reject = 1;
            break;
        }

        // Find matching c
        int foundC = 0;
        for (int j = 0; j < len; j++) {
            switch (tape[j]) {
                case 'a':
                case 'b':
                case 'X':
                case 'Y':
                    break;

                case 'c':
                    tape[j] = 'Z';
                    foundC = 1;
                    j = len; // break inner loop
                    break;
            }
        }

        if (!foundC) {
            reject = 1;
            break;
        }
    }

    // Final verification
    if (!reject) {
        for (int i = 0; i < len; i++) {
            char ch = tape[i];
            switch (ch) {
                case 'X':
                case 'Y':
                case 'Z':
                    break;

                default:
                    reject = 1;
            }

            if (reject)
                break;
        }
    }

    if (!reject)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
