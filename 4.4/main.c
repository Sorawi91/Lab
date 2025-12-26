#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ประกาศ struct สำหรับเก็บข้อมูลนักศึกษา
typedef struct Student {
    char name[50];     
    int age;          
    char gender;       
    float gpa;        
    struct Student *next; // ตัวชี้ไปยังคนถัดไป
} Student;

// ประกาศชื่อฟังก์ชันไว้ก่อน (Prototype)
Student *createStudent(char *n, int a, char s, float g);
void moveNext(Student **ptr);

int main(void) {
    Student *head = NULL;
    Student *current = NULL;

    // สร้างข้อมูลนักศึกษา 3 คน เชื่อมต่อกัน
    head = createStudent("Somchai", 19, 'M', 2.50);
    head->next = createStudent("Somsri", 18, 'F', 3.85);
    head->next->next = createStudent("Sompong", 20, 'M', 3.10);

    // ให้ current ชี้ที่คนแรกสุด
    current = head;

    // ขยับไปคนถัดไป (จากคนแรก ไปคนที่สอง)
    moveNext(&current);

    // แสดงชื่อของคนที่ชี้อยู่ปัจจุบัน
    printf("Current student name: %s\n", current->name);

    // คืนพื้นที่หน่วยความจำ (Free memory)
    Student *temp = head;
    while (temp != NULL) {
        Student *nextNode = temp->next; // เก็บตัวถัดไปไว้ก่อน
        free(temp);                     // ลบตัวปัจจุบัน
        temp = nextNode;                // ขยับไปตัวถัดไป
    }

    return 0;
}

// ฟังก์ชันสำหรับสร้างโหนดนักศึกษาใหม่
Student *createStudent(char *n, int a, char s, float g) {
    // จอง memory ขนาดเท่ากับ struct Student
    Student *new_node = malloc(sizeof(Student));

    strcpy(new_node->name, n);
    new_node->age = a;
    new_node->gender = s;
    new_node->gpa = g;
    new_node->next = NULL; 
    
    return new_node;
}

// ฟังก์ชันเลื่อน Pointer ไปตัวถัดไป
void moveNext(Student **ptr) {
    // เช็คก่อนว่า pointer มีค่าไหม และมีตัวถัดไปหรือเปล่า
    if (*ptr != NULL && (*ptr)->next != NULL) {
        *ptr = (*ptr)->next; 
        // ขยับไปชี้ตัวถัดไป
    }
}