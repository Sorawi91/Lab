#include <stdio.h>
#include <string.h>

void reverse (char str1[], char str2[]);

int main () {
    char text [50] ; 
    char out [50] ;
    fgets(text,50,stdin);
    reverse (text,out);
    printf("%s",out);
    return 0;
}

void reverse (char str1[], char str2[]){
    int len = 0;
    int j = 0;
    
    while (str1[len] != '\0') { 
        len++;                        
    } 

    for (int i = len -1; i >= 0 ; i--) { 

        str2[j] = str1[i]; 

        j++; 
    }

    str2[j] = '\0'; 
}
