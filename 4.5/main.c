#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct Student *next;
} Student;

Student *createStudent(const char *name, int age, char sex, float gpa);
void moveNext(Student **ptr);

int main(void) {
    Student *head = NULL;
    Student *current = NULL;

    head = createStudent("one", 6, 'M', 3.11f);
    head->next = createStudent("two", 8, 'F', 3.22f);
    head->next->next = createStudent("three", 10, 'M', 3.33f);
    head->next->next->next = createStudent("four", 12, 'F', 3.44f);

    current = head;

    moveNext(&current);

    printf("Current student: %s\n", current->name);

    Student *temp = head;
    while (temp) {
        Student *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

Student *createStudent(const char *name, int age, char sex, float gpa) {
    Student *new_node = malloc(sizeof(Student));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->sex = sex;
    new_node->gpa = gpa;
    new_node->next = NULL;
    return new_node;
}

void moveNext(Student **ptr) {
    if (*ptr && (*ptr)->next) {
        *ptr = (*ptr)->next;
    }
}