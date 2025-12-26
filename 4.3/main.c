#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    char name[20];
    int age;
    char gender;
    float gpa;
    struct StudentNode *next;
} StudentNode;

void setupNode(StudentNode *s, const char *n, int a, char g, float gp);
void stepNext(StudentNode **cursor);
void showNode(StudentNode *cursor);

int main(void) {
    StudentNode *head = NULL;
    StudentNode *current = NULL;

    head = malloc(sizeof(StudentNode));
    setupNode(head, "one", 6, 'M', 3.11f);

    head->next = malloc(sizeof(StudentNode));
    setupNode(head->next, "two", 8, 'F', 3.22f);

    head->next->next = malloc(sizeof(StudentNode));
    setupNode(head->next->next, "three", 10, 'M', 3.33f);

    head->next->next->next = malloc(sizeof(StudentNode));
    setupNode(head->next->next->next, "four", 12, 'F', 3.44f);

    current = head;

    showNode(current);

    stepNext(&current);

    showNode(current);

    StudentNode *temp = head;
    while (temp) {
        StudentNode *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

void setupNode(StudentNode *s, const char *n, int a, char g, float gp) {
    strcpy(s->name, n);
    s->age = a;
    s->gender = g;
    s->gpa = gp;
    s->next = NULL;
}

void stepNext(StudentNode **cursor) {
    if (*cursor && (*cursor)->next) {
        *cursor = (*cursor)->next;
    }
}

void showNode(StudentNode *cursor) {
    if (cursor) {
        printf("Student: %s, Age: %d, GPA: %.2f\n", cursor->name, cursor->age, cursor->gpa);
    }
}