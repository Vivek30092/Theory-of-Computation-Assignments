/* Question:
   Design a program for DFA to accept decimal numbers divisible by 3 (mod 3 = 0).
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int state = 0; // q0=0, q1=1, q2=2

    printf("Enter decimal number: ");
    if (scanf("%999s", input) != 1)
    {
        return 0;
    }

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        if (ch < '0' || ch > '9')
        {
            printf("Invalid input");
            return 0;
        }

        int d = ch - '0';

        switch (state)
        {
            case 0: // remainder 0
                state = d % 3;
                break;

            case 1: // remainder 1
                state = (1 + d) % 3;
                break;

            case 2: // remainder 2
                state = (2 + d) % 3;
                break;
        }
    }

    if (state == 0)
        printf("Accepted (number mod 3 = 0)");
    else
        printf("Rejected");

    return 0;
}
