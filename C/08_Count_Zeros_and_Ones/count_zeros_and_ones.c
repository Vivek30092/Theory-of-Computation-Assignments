/* Question:
   Design a program to count the number of 0s and 1s in a binary string.
*/

#include <stdio.h>

int main()
{
    char input[1000];
    int count0 = 0, count1 = 0;

    printf("Enter binary string: ");
    if (scanf("%999s", input) != 1)
    {
        return 0;
    }

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        if (ch == '0')
            count0++;
        else if (ch == '1')
            count1++;
        else
        {
            printf("Invalid input");
            return 0;
        }
    }

    printf("Number of 0's: %d\n", count0);
    printf("Number of 1's: %d\n", count1);

    return 0;
}
