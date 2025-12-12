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
    
    //หาความยาวของ อาเร หรือข้อความ
    while (str1[len] != '\0') { 
        len++;                        
    } 
    //ทำการ loop โดยเริ่มตั้งเเต่ตัวที่ 0 ของ str คือ len เเละ 

    for (int i = len -1; i >= 0 ; i--) { 
    //ใช้ for โดยให้ i คือ ความยาวของ len - 1 จะเท่ากับ 9 เเละให้ i วนจนครบหรือเท่ากับ 0 โดยลดค่าลงไปทีล่ะหนึ่ง
        str2[j] = str1[i]; 
        j++; 
        //เเละทำการบวก j ไปทีล่ะหนึ่งเพิ่มทำการขยับตำเเหน่งตัวอักษร
    }

    str2[j] = '\0'; 
    // ให้ str[j] ปิดท้ายด้วย \0 สำคัญคือ ต้องปิดท้ายด้วย \0 เสมอ
}
