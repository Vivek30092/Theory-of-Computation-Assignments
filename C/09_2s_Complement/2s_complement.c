/* Question:
   Design a program/transducer to output the 2's complement of a binary string.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    printf("Enter binary string: ");
    if (scanf("%999s", input) != 1)
    {
        return 0;
    }

    // Check valid input
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Invalid input");
            return 0;
        }
    }

    int len = strlen(input);

    // Step 1: Find 1's complement
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '0')
            input[i] = '1';
        else
            input[i] = '0';
    }

    // Step 2: Add 1
    int carry = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (input[i] == '1' && carry == 1)
        {
            input[i] = '0';
            carry = 1;
        }
        else if (input[i] == '0' && carry == 1)
        {
            input[i] = '1';
            carry = 0;
        }
    }

    printf("2's Complement: ");
    if (carry == 1)
    {
        printf("1");
    }
    printf("%s", input);

    return 0;
}
