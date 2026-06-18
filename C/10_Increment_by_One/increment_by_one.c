/* Question:
   Design a program/transducer to increment a binary number by 1.
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

    // Validate input
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Invalid input");
            return 0;
        }
    }

    int len = strlen(input);
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

    printf("Incremented Binary: ");
    if (carry == 1)
    {
        printf("1");
    }
    printf("%s\n", input);

    return 0;
}
