#include <stdio.h>
#include <string.h>

void explode(char str1[], char str2[20][20], char splitter, int *count);

int main() {
    char text[] = "I/Love/You";
    char result[20][20]; 
    char split = '/';
    int num = 0;

    explode(text, result, split, &num);

    for (int i = 0; i < num; i++) {
        printf("str[%d] = \"%s\"\n", i, result[i]);
    }

    printf("count = %d", num);
    
    return 0;
}

void explode(char str1[], char str2[20][20], char splitter, int *count) {
    int w = 0; 
    int c = 0; 

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != splitter) {
            str2[w][c] = str1[i];
            c++;
        } else {
            str2[w][c] = '\0';
            w++;
            c = 0;
        }
    }
    str2[w][c] = '\0';

    *count = w + 1;
}
