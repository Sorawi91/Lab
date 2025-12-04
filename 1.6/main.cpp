#include <stdio.h>
int GetMatrix(int **ar,int *row , int *col);
int main(){ int *data,m,n; GetMatrix(&data,&m,&n); return 0; }
int GetMatrix(int **ar,int *row , int *col){ printf("Fill row and col pls: "); scanf("%d %d",&(*row),&(*col)); int size = (*row) * (*col); *ar = new int[size]; printf("enter your %d data\n",size); for (int i = 0; i < size; i++){ printf("[%d] ",i+1); scanf("%d",&(*ar)[i]); } return 0; }