#include <stdio.h>

typedef struct
{
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

static Student upgrade(Student Gender)
{
    if (Gender.sex == 'M') {       
        Gender.gpa = Gender.gpa + Gender.gpa * 0.10; 
    } else
        Gender.gpa = Gender.gpa + Gender.gpa * 0.20;

    printf("%.2f\n", Gender.gpa); 
    return Gender;     
}

int main(void)
{
    Student Male;

    Male.sex = 'M';  
    Male.gpa = 3.00; 

    printf("%.2f\n", Male.gpa); 

    Male = upgrade(Male);

    printf("%.2f\n", Male.gpa); 

    return 0;
}

