#include <stdio.h>
#include <stdlib.h>

int *Dijkstra( int *L, int n ) ;

int main() {
    int n = 5, i = 0, j = 0, *d, *g ;
    
    g = (int *)malloc( n * n * sizeof(int) ) ;
    
    for( i = 0 ; i < n ; i++ ) 
        for( j = 0 ; j < n ; j++ )
            g[ i * n + j ] = -1 ;

    g[ 0 * n + 1 ] = 100 ;    g[ 0 * n + 2 ] = 80 ;
    g[ 0 * n + 3 ] = 30 ;     g[ 0 * n + 4 ] = 10 ;
    g[ 1 * n + 2 ] = 20 ;     g[ 3 * n + 1 ] = 20 ;
    g[ 3 * n + 2 ] = 20 ;     g[ 4 * n + 3 ] = 10 ;

    d = Dijkstra( g, n ) ;
    
    for( i = 0 ; i < n - 1 ; i++ )
        printf( "%d ", d[ i ] ) ;
        
    return 0 ;
}

int *Dijkstra(int *L, int n) {
    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    int INF = 999999;

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int min = INF;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            int weight = L[u * n + v];
            if (weight != -1 && visited[v] == 0) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    int *result = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        result[i] = dist[i + 1];
    }

    free(dist);
    free(visited);

    return result;
}