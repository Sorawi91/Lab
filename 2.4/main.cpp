#include <stdio.h>
#include <string.h>

void explode(char str1[] , char str2[20][20] ,char spliter ,int *count);
     
int main () {
    char stater1[] = "I/Love/You";
    char stater2[20][20];
    // stater2 [เก็บได้กี่ตัวอักษร][สูงสุดได้้กี่ตัวอักษร]

    char split = '/';
    int numberCount = 0;

    explode(stater1,stater2,split,&numberCount);

    for (int i = 0 ; i < numberCount ; i++) {
        printf("str[%d] = %s \n",i,stater2[i]);
    }

    printf("count = %d",numberCount);
    
    return 0;
} 

void explode(char str1[] , char str2[20][20] ,char spliter ,int *count){
    int colum = 0;
    // c คือ คอลัม ที่ไว้ขยับตัวอักษร เเละเป็น ตำเเหน่งที่เก็บตัวอักษร 
    
    int radius = 0; //1 0 1 0 1
    //เป็นเเค่เเถว เเละขนาดตัวอักษรสูงสุด

    for (int i = 0 ; str1[i] != '\0' ; i++) {
        //ให้ลูปไปจนถึง /0 ของ str[1]
        
        if (str1[i] != spliter) {
            str2[colum][radius] = str1[i];
            //มันจะยัด str1[i] เข้าไปที่ str2[c] เเละรูปครั้งหน้ามันจะเลื่อนเเถว ไป อีกบรรทัดหนึ่ง
            radius++;

        } else {
            str2[colum][radius] = '\0'; 
            //ถ้ามันเจอ / มัันก็จะจบ เเละไปเริ่มที่ตำเเหน่งเเรกใหม่เโดยให้ r = 0;เเละ ลูปครั้งหน้ามันก็จะเริ่มที่ r 0 เเละ ขยับหลักไปอีกหนึ่งหลัก
            colum++; 
            radius = 0;
            // ขยับหลัก
        }
    }
    str2[colum][radius] = '\0';

    *count = colum + 1;
}
     
