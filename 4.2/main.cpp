#include <stdio.h>

// ประกาศฟังก์ชัน
void go( int ***p, int **z );

int main() {
    int *b = new int ; *b = 10 ; 
    // b เก็บที่อยู่ของเลข 10
    int *c = new int ; *c = 20 ; 
    // c เก็บที่อยู่ของเลข 20
    int **a ;                    
    // a เป็น Pointer 2 ดาว (เอาไว้ชี้ b หรือ c อีกที)

    // รอบแรก: ส่งที่อยู่ของ a และ b ไป
    go( &a, &b ); 
    printf( "%d %p %p %p \n", **a, *a, a, &a );
    
    // รอบสอง: ส่งที่อยู่ของ a และ c ไป
    go( &a, &c );
    printf( "%d %p %p %p \n", **a, *a, a, &a );
    
    return 0 ;
}

// ฟังก์ชันที่เเขียนเพิ่ม
void go( int ***p, int **z ) {
    *p = z;
}