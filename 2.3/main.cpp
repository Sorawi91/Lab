#include <stdio.h>
#include <string.h>

void explode (char str1[],char splitter , char str2[20][10] , int *count);


int main() {
    char Ex[] = "I/Love/You";
    char sprit = '/';
    char out [20][10];
    int num = 0;

    explode(Ex,sprit,out,&num);

    for (int i = 0 ; i < num ; i++ ) {
        printf("str2[%d] = \ %s \ \n",i,out[i]);
    }    
    printf("Count = %d",num);

    return 0;
}

void explode (char str1[],char splitter , char str2[20][10] , int *count){
    int x = 0;
    int z = 0;

    for (int i = 0 ; str1[i] != '\0' ; i++) {
        if (str1[i] != splitter) {
            str2[x][z] = str1[i];
            z++;
        } else {
            str2[x][z] = '\0';
            x++;
            z = 0;
        }
    }
    str2[x][z] = '\0';

    *count = x + 1;
}
