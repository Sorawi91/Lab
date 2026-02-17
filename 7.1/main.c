#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct node *next;
} node;

typedef struct {
    node *first;
    node *point;
} List;

/* prototype */
void startList(List *L);
void addData(List *L, char name[], int age, char sex, float gpa);
void removeHead(List *L);
void moveNext(List *L);
void printList(List *L);

int main() {
    List A;
    List B;
    List *C;

    startList(&A);
    startList(&B);

    addData(&A, "one", 1, 'A', 1.1);
    addData(&A, "two", 2, 'B', 2.2);
    addData(&A, "three", 3, 'C', 3.3);

    moveNext(&A);
    printList(&A);

    addData(&B, "four", 4, 'D', 4.4);
    addData(&B, "five", 5, 'E', 5.5);
    addData(&B, "six", 6, 'F', 6.6);

    moveNext(&B);
    removeHead(&B);
    printList(&B);

    C = &A;
    moveNext(C);
    printList(C);

    C = &B;
    printList(C);

    return 0;
}

/* ===== function part ===== */

void startList(List *L) {
    L->first = NULL;
    L->point = NULL;
}

void addData(List *L, char name[], int age, char sex, float gpa) {
    node *newNode;
    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("no memory\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (L->first == NULL) {
        L->first = newNode;
        L->point = newNode;
    } else {
        L->point->next = newNode;
        L->point = newNode;
    }
}

void removeHead(List *L) {
    node *temp;

    if (L->first == NULL) {
        printf("empty list\n");
        return;
    }

    temp = L->first;
    L->first = L->first->next;
    free(temp);

    if (L->first == NULL) {
        L->point = NULL;
    }
}

void moveNext(List *L) {
    if (L->point != NULL) {
        if (L->point->next != NULL) {
            L->point = L->point->next;
        }
    }
}

void printList(List *L) {
    node *temp;

    if (L->first == NULL) {
        printf("empty list\n");
        return;
    }

    temp = L->first;

    while (temp != NULL) {
        printf("%s %d %c %.1f\n",
               temp->name,
               temp->age,
               temp->sex,
               temp->gpa);
        temp = temp->next;
    }

    printf("------\n");
}
