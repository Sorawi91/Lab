#include <stdio.h>

void GetSet(int ptrarr[],int *n);

int main(){
    int arr[100], num;
    GetSet(arr,&num);
    return 0;
}


void GetSet(int ptrarr[],int *n){
    printf("Pls Fill Number For Member: ");
    scanf("%d",n);

    for(int i = 0 ; i < *n ; i++){
        printf("Pls Fill data for member [%d]: ",i+1);
        scanf("%d",&ptrarr[i]);
    }
}
