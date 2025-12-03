#include <stdio.h>

void GetSet(int a[], int *n);

int main()
{
    int *data, num;
    GetSet(data, &num);
    return 0;
}

void GetSet(int a[], int *n)
{
    int i;

    printf("Pls Fill Number : ");

    scanf("%d", n);

    for (i = 0; i < *n; i++)
    {
        printf("Show Row %d : ", i + 1);

        scanf("%d", &a[i]);
    }
}