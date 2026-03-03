#include <stdio.h>
#include <stdlib.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) {
    if (i == n || wx <= 0) {
        for (int k = i; k < n; k++) x[k] = 0;
        return 0;
    }

    int x_left[n], x_right[n];
    
    int val_not_pick = KnapsackBT(w, v, n, wx, i + 1, x_left);

    int val_pick = -1;
    if (wx >= w[i]) {
        val_pick = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x_right);
    }

    if (val_pick > val_not_pick) {
        x[i] = 1;
        for (int k = i + 1; k < n; k++) x[k] = x_right[k];
        return val_pick;
    } else {
        x[i] = 0;
        for (int k = i + 1; k < n; k++) x[k] = x_left[k];
        return val_not_pick;
    }
}

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x, vx ;
    
    x = (int*)malloc(n * sizeof(int)); 
    
    vx = KnapsackBT( w, v, n, wx, 0, x ) ;
    
    printf( "Value = %d ", vx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    
    free(x);
    return 0 ;
}