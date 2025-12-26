#include <stdio.h>

#define maxroom 20
#define studentroom 10

struct Studentinput {
    char name[20];
    int age;
    char gender;
    float gpa;
};

void inputStudents(struct Studentinput list[][studentroom], int *totalRooms);


void inputStudents(struct Studentinput list[][studentroom], int *totalRooms) {
    int x, z;

    printf("Enter number of classrooms: ");
    scanf("%d", totalRooms);

    for (x = 0; x < *totalRooms; x++) {
        printf("\n=== Room %d ===\n", x + 1);

        for (z = 0; z < studentroom; z++) {
            printf("Student %d -> Name Age Gender GPA: ", z + 1);
            scanf("%s %d %c %f",
                  list[x][z].name,
                  &list[x][z].age,
                  &list[x][z].gender,
                  &list[x][z].gpa);
        }
    }
}

int main() {
    struct Studentinput classroom[maxroom][studentroom];
    int count = 0;

    inputStudents(classroom, &count);

    return 0;
}
