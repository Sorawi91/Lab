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

void setStudent(Student *s, const char *name, int age, char sex, float gpa);
void moveNext(Student **ptr);

int main(void) {
    Student *head = NULL;
    Student *current = NULL;

    head = malloc(sizeof(Student));
    setStudent(head, "one", 6, 'M', 3.11f);

    head->next = malloc(sizeof(Student));
    setStudent(head->next, "two", 8, 'F', 3.22f);

    head->next->next = malloc(sizeof(Student));
    setStudent(head->next->next, "three", 10, 'M', 3.33f);

    head->next->next->next = malloc(sizeof(Student));
    setStudent(head->next->next->next, "four", 12, 'F', 3.44f);

    current = head;

    printf("Before jump: %s\n", current->name);

    moveNext(&current);

    printf("After jump:  %s\n", current->name);

    Student *temp = head;
    while (temp) {
        Student *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

void setStudent(Student *s, const char *name, int age, char sex, float gpa) {
    strcpy(s->name, name);
    s->age = age;
    s->sex = sex;
    s->gpa = gpa;
    s->next = NULL;
}

void moveNext(Student **ptr) {
    if (*ptr && (*ptr)->next) {
        *ptr = (*ptr)->next;
    }
}