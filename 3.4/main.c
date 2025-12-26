#include <stdio.h>

struct student {
    char name[30];
    int score;
};

void GetStudent(struct student child[][10], int *room)
{
    int i, j;

    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (i = 0; i < *room; i++) {
        printf("\nRoom %d\n", i + 1);

        for (j = 0; j < 10; j++) {
            printf("Student %d name: ", j + 1);
            scanf("%s", child[i][j].name);

            printf("Student %d score: ", j + 1);
            scanf("%d", &child[i][j].score);
        }
    }
}

int main()
{
    struct student children[20][10];
    int group;

    GetStudent(children, &group);

    return 0;
}
