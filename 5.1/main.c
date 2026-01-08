#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode *AddNode(struct studentNode **start, char *n, int a, char s, float g);
void InsNode(struct studentNode *prevNode, char *n, int a, char s, float g);
void DelNode(struct studentNode **start, struct studentNode *nodeToDelete);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start = NULL , *now = NULL;
    
    now = AddNode(&start, "one", 6, 'M', 3.11); 
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22); 
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33); 
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44); 
    ShowAll(start);

    DelNode(&start, now);
    ShowAll(start);

    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, char *n, int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}

void InsNode(struct studentNode *prevNode, char *n, int a, char s, float g) {
    if (prevNode == NULL) return;

    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void DelNode(struct studentNode **start, struct studentNode *nodeToDelete) {
    if (*start == NULL || nodeToDelete == NULL) return;

    if (*start == nodeToDelete) {
        *start = nodeToDelete->next;
        free(nodeToDelete);
        return;
    }

    struct studentNode *prev = *start;
    while (prev->next != NULL && prev->next != nodeToDelete) {
        prev = prev->next;
    }

    if (prev->next == nodeToDelete) {
        prev->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}