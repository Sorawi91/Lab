#include <stdio.h>

void reverse (char str1[] , char *str2);

int main () {
    char text [50];
    char *out;

    reverse(text,out);

    printf("%s",out);

    return 0;
}

void reverse (char str1[]  , char *str2){
    gets(str1);
    
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }

    int b = 0;

    for (int i = len - 1; i >= 0 ; i--) {
        str2[b] = str1[i];
        b++;
    }
}