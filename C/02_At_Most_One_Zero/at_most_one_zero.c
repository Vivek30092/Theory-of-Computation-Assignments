/* Question:
   Design a program for DFA to accept binary strings containing at most one '0'.
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int state = 0; // q0=0, q1=1, q2=2 (dead state)

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
            case 0: // q0 : no 0 seen
                if (ch == '0')
                    state = 1;
                else if (ch == '1')
                    state = 0;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;

            case 1: // q1 : one 0 seen
                if (ch == '0')
                    state = 2;
                else if (ch == '1')
                    state = 1;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;

            case 2: // q2 : more than one 0
                if (ch == '0' || ch == '1')
                    state = 2;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;
        }
    }

    if (state == 0 || state == 1)
        printf("String Accepted (at most one 0)\n");
    else
        printf("String Rejected (more than one 0)\n");

    return 0;
}
