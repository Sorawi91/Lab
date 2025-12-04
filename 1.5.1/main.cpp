#include <stdio.h>
void GetMatrix(int **value, int *row, int *col);
int main()
{
    int *arr, m, n;
    GetMatrix(&arr, &m, &n);
    return 0;
}
void GetMatrix(int **value, int *row, int *col)
{
    printf("Plsese Fill row and col: ");
    scanf("%d %d", row, col);
    int size = (*row) * (*col);
    *value = new int[size];
    printf("Plsese Fill %d number\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("[%d]: ", i + 1);
        scanf("%d", &value[i]);
    }
}
