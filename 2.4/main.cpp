#include <stdio.h>
#include <string.h>

void explode(char str1[], char str2[20][20], char splitter, int *count);

int main() {
    char text[] = "I/Love/You";
    char result[20][20]; 
    char split = '/'; 
    int numberCount = 0; 

    explode(text, result, split, &numberCount);

    for (int index = 0; index < numberCount; index++) {
        printf("str2[%d] = \"%s\"\n", index, result[index]);
    }

    printf("count = %d", numberCount);
    
    return 0;
}

void explode(char str1[], char str2[20][20], char splitter, int *count) {
    int wordIndex = 0; 
    int charIndex = 0; 

    for (int index = 0; str1[index] != '\0'; index++) {
        
        if (str1[index] != splitter) {
            str2[wordIndex][charIndex] = str1[index]; 
            charIndex++; 
        } 
        else {
            str2[wordIndex][charIndex] = '\0'; 
            wordIndex++; 
            charIndex = 0; 
        }
    }
    
    str2[wordIndex][charIndex] = '\0';

    *count = wordIndex + 1;
}
