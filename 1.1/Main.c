#include <stdio.h>

int main() {

    int n;

    printf("Fill Number in textbox for print(Hello world): ");

    if (scanf("%d",&n) != 1) {
        return 1;
    }

    if (n <= 0) {
        printf("Error Pls Fill above (1-n)");
        return 1;
    }

    for(int i = 0 ; i < n ; i++){
        printf("[%d]",i+1);
        printf(" Hello world\n"); 
    }
    
}