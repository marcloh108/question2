#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(char *str1)
{
    int offset[128];
    int subtract = 0;
    int length = 0;
    int index = 0;

    memset(offset, 0xff, sizeof(offset));
    while (*str1 != '\0')
    {
        if (offset[*str1] == -1)
          {
            length++;
          }
          else {
            if (index - offset[*str1] > length)
                {
                length++;
            }
            else
            {
            length = index - offset[*str1];
            }
        }
        if (length > subtract)
        {
            subtract = length;
        }
        offset[*str1++] = index++;
    }

    return subtract;
}

int main(void)
 {
    char *str1 = "xyzxyzyy";
    printf("\nOriginal String: %s", str1);
    printf("\nLength of the longest substring without repeating characters: %d\n", test(str1));
    return 0;
}
