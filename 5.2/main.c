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

// กำหนดฟังชั่นเริ่มต้น
void ShowAll(struct studentNode **walk);
void InsNode(struct studentNode **now, char *n, int a, char s, float g);
void GoNext(struct studentNode ***now);
void DelNode(struct studentNode **now);

//ในเมน
int main() {
    struct studentNode *start, **now;
    start = NULL; 
    now = &start;

    InsNode(now, "one", 6, 'M', 3.11); 
    ShowAll(&start);

    InsNode(now, "two", 8, 'F', 3.22); 
    ShowAll(&start);

    GoNext(&now);
    //ให้ now ขยับไปตัวถัดไป

    InsNode(now, "three", 10, 'M', 3.33); 
    ShowAll(&start);

    InsNode(now, "four", 12, 'F', 3.44); 
    ShowAll(&start);

    GoNext(&now);
    //ให้ now ขยับไปตัวถัดไป

    DelNode(now); 
    //ลบ list ที่ now ชี้อยู่
    ShowAll(&start);
    
    return 0;
}

void ShowAll(struct studentNode **walk) {
    while (*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &(*walk)->next;
    }
    printf("\n");
}

//ฟังชั่นที่ให้ชี้ตัวถัดไป
void GoNext(struct studentNode ***now) {
    if ((**now) != NULL) {
        *now = &((**now)->next);
    }
}

//ฟั่งชั่นเเทรก Node ใหม่
void InsNode(struct studentNode **now, char *n, int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = *now;
    *now = newNode;
}

//ฟังชั่นลบNodeของตำเเหน่้งที่ now ชี้อยู่
void DelNode(struct studentNode **now) {
    struct studentNode *temp;
    if (*now != NULL) {
        temp = *now;
        *now = temp->next;
        free(temp);
    }
}