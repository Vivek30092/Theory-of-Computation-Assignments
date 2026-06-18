/* Question:
   Design a program for DFA to accept binary strings ending with '101'.
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int state = 0; // q0=0, q1=1, q2=2, q3=3

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
            case 0: // q0
                if (ch == '1')
                    state = 1;
                else if (ch == '0')
                    state = 0;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;

            case 1: // q1 (seen 1)
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

            case 2: // q2 (seen 10)
                if (ch == '1')
                    state = 3;
                else if (ch == '0')
                    state = 0;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;

            case 3: // q3 (ends with 101)
                if (ch == '1')
                    state = 1;
                else if (ch == '0')
                    state = 2;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;
        }
    }

    if (state == 3)
        printf("String Accepted (ends with 101)\n");
    else
        printf("String Rejected\n");

    return 0;
}
