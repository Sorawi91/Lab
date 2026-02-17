#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//โครงสร้างข้อมูล
typedef struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
} studentNode;

typedef struct {
    studentNode *head;      
    // ตัวแรกของ list
    studentNode *current;   
    // ตัวปัจจุบัน
} LinkedList;

void initList(LinkedList *list);
void insertNode(LinkedList *list, char name[], int age, char sex, float gpa);
void deleteFirstNode(LinkedList *list);
void goNext(LinkedList *list);
void goFirst(LinkedList *list);
void showAllNodes(LinkedList *list);

int main() {
    LinkedList listA, listB;
    LinkedList *listC;

    initList(&listA);
    initList(&listB);

    //เพิ่มข้อมูล listA
    insertNode(&listA, "one", 1, 'A', 1.1);
    insertNode(&listA, "two", 2, 'B', 2.2);
    insertNode(&listA, "three", 3, 'C', 3.3);

    goNext(&listA);
    showAllNodes(&listA);

    // เพิ่มข้อมูล listB
    insertNode(&listB, "four", 4, 'D', 4.4);
    insertNode(&listB, "five", 5, 'E', 5.5);
    insertNode(&listB, "six", 6, 'F', 6.6);

    goNext(&listB);
    deleteFirstNode(&listB);
    showAllNodes(&listB);

    // ใช้ pointer ชี้ไปยัง listA
    listC = &listA;
    goNext(listC);
    showAllNodes(listC);

    // ใช้ pointer ชี้ไปยัง listB
    listC = &listB;
    showAllNodes(listC);

    return 0;
}

// เริ่มต้น list ให้เป็นค่าว่าง
void initList(LinkedList *list) {
    list->head = NULL;
    list->current = NULL;
}

// เพิ่ม node ต่อท้าย
void insertNode(LinkedList *list, char name[], int age, char sex, float gpa) {
    studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->current = newNode;
    } else {
        list->current->next = newNode;
        list->current = newNode;
    }
}

// ลบ node ตัวแรก
void deleteFirstNode(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    studentNode *temp = list->head;
    list->head = list->head->next;
    free(temp);

    if (list->head == NULL)
        list->current = NULL;
}

// ไป node ถัดไป
void goNext(LinkedList *list) {
    if (list->current != NULL && list->current->next != NULL) {
        list->current = list->current->next;
    }
}

// กลับไป node แรก
void goFirst(LinkedList *list) {
    list->current = list->head;
}

// แสดงข้อมูลทั้งหมดใน list
void showAllNodes(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    studentNode *temp = list->head;

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
