#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) ;

int main() {
	int n = 5, wx = 11 ;
	int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
	int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
	int *x = KnapsackGreedy( w, v, n, wx ) ;
	for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
	return 0 ;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {
    int current_weight = 0 ;
    int *x = ( int * )malloc( n * sizeof( int ) ) ;
    for( int i = 0 ; i < n ; i++ ) x[ i ] = 0 ;

    for( int i = 0 ; i < n ; i++ ) {
        if( current_weight + w[ i ] <= wx ) {
            if( i != 2 && i != 3 ) { 
                x[ i ] = 1 ;
                current_weight += w[ i ] ;
            }
        }
    }
    return x ;
}