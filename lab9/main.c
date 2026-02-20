#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void addNode(struct studentNode **start, char n[], int a, char s, float g);
void deleteNode(struct studentNode **start, char n[]);
void editNode(struct studentNode *start, char n[]);
void findNode(struct studentNode *start, char n[]);
void showAll(struct studentNode *start);
void saveToFile(struct studentNode *start);
void loadFromFile(struct studentNode **start);

int main() {
    struct studentNode *start = NULL; 
    int menu;
    char searchName[20];

    loadFromFile(&start);

    do {
        printf("\n======= STUDENT MENU =======\n");
        printf("(1) Add Data\n");
        printf("(2) Edit Data\n");
        printf("(3) Delete Data\n");
        printf("(4) Find Student\n");
        printf("(5) Show All\n");
        printf("(0) Exit & Save\n");
        printf("Select Menu: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1: {
                char n[20], s; int a; float g;
                printf("Name: "); scanf("%s", n);
                printf("Age: ");  scanf("%d", &a);
                printf("Sex (M/F): "); scanf(" %c", &s);
                printf("GPA: ");  scanf("%f", &g);
                addNode(&start, n, a, s, g);
                break;
            }
            case 2:
                printf("Enter Name to Edit: "); scanf("%s", searchName);
                editNode(start, searchName);
                break;
            case 3:
                printf("Enter Name to Delete: "); scanf("%s", searchName);
                deleteNode(&start, searchName);
                break;
            case 4:
                printf("Enter Name to Find: "); scanf("%s", searchName);
                findNode(start, searchName);
                break;
            case 5:
                showAll(start);
                break;
            case 0:
                saveToFile(start);
                printf("Saving data... Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(menu != 0);

    return 0;
}

void addNode(struct studentNode **start, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("Added successfully!\n");
}

void showAll(struct studentNode *start) {
    struct studentNode *temp = start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\n%-15s %-5s %-5s %-5s\n", "NAME", "AGE", "SEX", "GPA");
    while (temp != NULL) {
        printf("%-15s %-5d %-5c %-5.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

void findNode(struct studentNode *start, char n[]) {
    struct studentNode *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            printf("Found! Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            return;
        }
        temp = temp->next;
    }
    printf("Student '%s' not found.\n", n);
}

void deleteNode(struct studentNode **start, char n[]) {
    struct studentNode *temp = *start, *prev = NULL;
    
    if (temp != NULL && strcmp(temp->name, n) == 0) {
        *start = temp->next;
        free(temp);
        printf("Deleted '%s'\n", n);
        return;
    }

    while (temp != NULL && strcmp(temp->name, n) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Name not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted successfully.\n");
}

void editNode(struct studentNode *start, char n[]) {
    struct studentNode *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            printf("Enter New Age: ");  scanf("%d", &temp->age);
            printf("Enter New Sex: ");  scanf(" %c", &temp->sex);
            printf("Enter New GPA: ");  scanf("%f", &temp->gpa);
            printf("Updated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not found.\n");
}

void saveToFile(struct studentNode *start) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) return;
    
    struct studentNode *temp = start;
    while (temp != NULL) {
        fprintf(fp, "%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
    fclose(fp);
}

void loadFromFile(struct studentNode **start) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) return;

    char n[20], s; int a; float g;
    while (fscanf(fp, "%s %d %c %f", n, &a, &s, &g) != EOF) {
        addNode(start, n, a, s, g);
    }
    fclose(fp);
}