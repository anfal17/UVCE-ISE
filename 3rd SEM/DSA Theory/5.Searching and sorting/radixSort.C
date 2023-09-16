#include <stdio.h>
#include <stdlib.h>
#define n 7

void radixSort(int a[])
{
    int i, j, big, nod = 0, steps, noeb[10], bucket[10][10], loc = 0, div = 1;

    // Finding the largest value
    big = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > big)
        {
            big = a[i];
        }
    }
    // finding the number of digits in the largest value
    while (big > 0)
    {
        nod++;
        big = big / 10;
    }

    // no of pass == no of digits in big
    for (steps = 1; steps <= nod; steps++)
    {
        int k = 0;
        // Initializing no of elements in each bucket to zero
        for (j = 0; j < 10; j++)
        {
            noeb[j] = 0;
        }

        // finding location of each element and placing in respective buckets
        for (i = 0; i < n; i++)
        {
            loc = (a[i] / div) % 10;
            // in first iteration div = 1 then 10 , 100 ...
            bucket[loc][noeb[loc]++] = a[i];
        }
        // Placing bucket elements into resultant array
        for (j = 0; j < 10; j++)
        {
            for (i = 0; i < noeb[j]; i++)
            {
                a[k++] = bucket[j][i];
            }
        }
        div = div * 10;
    }
}

int main()
{
    int a[10] = {150, 232, 541, 153, 675, 276, 423};

    radixSort(a);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}