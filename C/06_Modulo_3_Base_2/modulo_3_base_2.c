/* Question:
   Design a program for DFA to accept binary strings representing numbers divisible by 3 (mod 3 = 0).
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int state = 0; // q0=0, q1=1, q2=2

    printf("Enter binary string: ");
    if (scanf("%999s", input) != 1)
    {
        return 0;
    }

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        switch (state)
        {
            case 0: // remainder 0
                if (ch == '0') state = 0;
                else if (ch == '1') state = 1;
                else { printf("Invalid input"); return 0; }
                break;

            case 1: // remainder 1
                if (ch == '0') state = 2;
                else if (ch == '1') state = 0;
                else { printf("Invalid input"); return 0; }
                break;

            case 2: // remainder 2
                if (ch == '0') state = 1;
                else if (ch == '1') state = 2;
                else { printf("Invalid input"); return 0; }
                break;
        }
    }

    if (state == 0)
        printf("Accepted (binary number mod 3 = 0)\n");
    else
        printf("Rejected\n");

    return 0;
}
