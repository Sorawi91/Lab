#include <stdio.h>

void update(int ***target, int **source);
void print(const char *label, int **pp);

void update(int ***target, int **source)
{
    *target = source;
}

void print(const char *label, int **pp)
{
    printf("%s\n", label);
    printf("Value via **pp: %d\n", **pp);
    printf("*pp (points to int*): %p\n", (void *)*pp);
    printf("pp  (int** itself):   %p\n\n", (void *)pp);
}

int main(void)
{
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;
    int **handle = NULL;

    update(&handle, &pa);
    print("After pointing to a", handle);

    update(&handle, &pb);
    print("After pointing to b", handle);

    return 0;
}

