#include <stdio.h>

void GetSet(int ptrdata[],int *number);

int main(){ int data[50],num;GetSet(data,&num);return 0; }

void GetSet(int ptrdata[],int *number){ printf("Plsese Fill Number For Member you need to input data: "); scanf("%d",number); for(int i = 0 ; i < *number ; i++){ printf("Plsese Fill data for member [%d] : ",i+1); scanf("%d",ptrdata[i]); }
}