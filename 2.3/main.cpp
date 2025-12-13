#include <stdio.h>
#include <string.h>

void explode (char str1[],char splitter , char str2[20][10] , int *count);


int main() {
    char Ex[50];
    char sprit = '/';
    char out [20][10];
    int num = 0;

    fgets(Ex,50,stdin);
    
    //กำหนดตัวเเปร
    explode(Ex,sprit,out,&num);
    //เรียกใช้ funtionc 
    for (int i = 0 ; i < num ; i++ ) {
        printf("str2[%d] = \ %s \ \n",i,out[i]);
    }    
    printf("Count = %d",num);

    return 0;
}

void explode (char str1[],char splitter , char str2[20][10] , int *count){
    int col = 0;
    int radius = 0;

    // loop for โดย ลูปตามตัวอักษรไปจนถึง \0 เเละเช็คว่ามันมีไม่มี \ ถ้าไม่มีให้ยัดลงไปใน str2
    for (int i = 0 ; str1[i] != '\0' ; i++) {
        if (str1[i] != splitter) {
            str2[col][radius] = str1[i];
            radius++;
        } else { 
            //ถ้าเจอ / ก็ให้ยัด \0 เข้าไปเเล้วเเละ ขยับตัวอักษรไปอีกตัวด้วย x เเละรีเซ็ตตำเเหน่งให้เป็น 0
            str2[col][radius] = '\0';
            col++;
            radius = 0;
        }
    }

    str2[col][radius] = '\0';

    *count = col + 1;
}
