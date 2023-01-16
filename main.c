#include <stdio.h>

int main()
{
    printf("hello world");
    return 0;
}
void main(void)
{
    int number[12]; /* 12 cells, one cell per student */
    int index, sum = 0;

    /* Always initialize array before use */
    for (index = 0; index < 12; index++)
    {
        number[index] = index;
    }

    /* Now, number[index]=index; Error: Why? What kind?*/
    for (index = 0; index < 12; index = index + 1)
    {
        sum += number[index]; /* Sum array elements */
    }
    return;
}