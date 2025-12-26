#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

static void upgrade(Student *Gender) {
    if (Gender->sex == 'M') {   
        Gender->gpa *= 1.10;      
    } else                     
        Gender->gpa *= 1.20;       
}

int main(void) {
    Student aboy;  

    aboy.sex = 'M';  
    aboy.gpa = 3.00; 

    upgrade(&aboy);   

    printf("%.2f", aboy.gpa); 
    return 0; 
}
