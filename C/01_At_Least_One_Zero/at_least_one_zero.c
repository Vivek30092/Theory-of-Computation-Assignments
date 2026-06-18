/* Question:
   Design a program for DFA to accept binary strings containing at least one '0'.
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int state = 0; // q0 = 0 (no 0 seen), q1 = 1 (at least one 0 seen)

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

            case 1: // q1
                if (ch == '0' || ch == '1')
                    state = 1;
                else
                {
                    printf("Invalid input");
                    return 0;
                }
                break;
        }
    }

    if (state == 1)
        printf("String Accepted (contains at least one 0)");
    else
        printf("String Rejected (no 0 present)\n");

    return 0;
}
