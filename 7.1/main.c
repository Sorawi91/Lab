#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//โครงสร้าง
typedef struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
} studentNode;

typedef struct {
    studentNode *start;
    studentNode *now;
} LinkedList;

void initList(LinkedList *list);
void InsNode(LinkedList *list, char n[], int a, char s, float g);
void DelNode(LinkedList *list);
void GoNext(LinkedList *list);
void GoFirst(LinkedList *list);
void ShowNode(LinkedList *list);

int main() {
    LinkedList listA, listB;
    LinkedList *listC;

    initList(&listA);
    initList(&listB);

    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);
    GoNext(&listA);
    ShowNode(&listA);

    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);
    GoNext(&listB);
    DelNode(&listB);
    ShowNode(&listB);

    listC = &listA;
    GoNext(listC);
    ShowNode(listC);

    listC = &listB;
    ShowNode(listC);

    return 0;
}

void initList(LinkedList *list) {
    list->start = NULL;
    list->now = NULL;
}

void InsNode(LinkedList *list, char n[], int a, char s, float g) {
    studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (list->start == NULL) {
        list->start = newNode;
        list->now = newNode;
    } else {
        list->now->next = newNode;
        list->now = newNode;
    }
}

void DelNode(LinkedList *list) {
    if (list->start == NULL) return;

    studentNode *temp = list->start;
    list->start = list->start->next;
    free(temp);

    if (list->start == NULL)
        list->now = NULL;
}

void GoNext(LinkedList *list) {
    if (list->now != NULL && list->now->next != NULL)
        list->now = list->now->next;
}

void GoFirst(LinkedList *list) {
    list->now = list->start;
}

void ShowNode(LinkedList *list) {
    studentNode *temp = list->start;

    while (temp != NULL) {
        printf("%s %d %c %.1f\n",
               temp->name,
               temp->age,
               temp->sex,
               temp->gpa);
        temp = temp->next;
    }
    printf("-----------------\n");
}
