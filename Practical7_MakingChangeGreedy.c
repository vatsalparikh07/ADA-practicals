/* Making Change Program Greedy Algorithm */
// -Vatsal Parikh

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{

    int a[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n;
    int i = 0;
    int j;

    printf("Enter an amount: ");
    scanf("%d", &n);

    while(n > 0)
    {
        if(n >= a[i])
        {
            n = n - a[i];
            printf("%d ", a[i]);
        }

        else{
            i++;
        }
    }

}
