#include <stdio.h>

// ประกาศ Prototype ของฟังก์ชัน
int BinSearch( int data[], int n, int find ) ;

int main() {
    int data[ 6 ] = { 1, 2, 3, 4, 5, 7 } ;
    int n = 6, find = 5 ;
    int pos = BinSearch( data, n, find ) ;
    
    // แสดงผลลัพธ์ให้ตรงตาม Test Case 1
    if ( pos != -1 ) {
        printf( "Found %d at %d", find, pos ) ;
    } else {
        printf( "%d not found", find ) ;
    }
    
    return 0 ;
}

// ฟังก์ชัน Binary Search
int BinSearch( int data[], int n, int find ) {
    int low = 0 ;
    int high = n - 1 ;
    
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        
        if ( data[ mid ] == find ) {
            return mid ; 
        } else if ( data[ mid ] < find ) {
            low = mid + 1 ; 
        } else {
            high = mid - 1 ;
        }
    }
    
    return -1 ;
}