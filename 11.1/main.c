#include <stdio.h>

#define ARRAY_SIZE 6


int binarySearch(int dataArray[], int size, int targetValue);

int main() {
    int data[ARRAY_SIZE] = {1, 2, 3, 4, 5, 7};
    
    int targetValue = 5;
    
    int resultPosition = binarySearch(data, ARRAY_SIZE, targetValue);
    
    if (resultPosition != -1) {
        printf("Found %d at %d\n", targetValue, resultPosition);
    } else {
        printf("%d not found\n", targetValue);
    }
    
    return 0;
}

int binarySearch(int dataArray[], int size, int targetValue) {
    int lowIndex = 0;
    int highIndex = size - 1;
    
    while (lowIndex <= highIndex) {

        int midIndex = lowIndex + (highIndex - lowIndex) / 2;
        
        if (dataArray[midIndex] == targetValue) {
            return midIndex; 
        } else if (dataArray[midIndex] < targetValue) {
            lowIndex = midIndex + 1; 
        } else {
            highIndex = midIndex - 1;
        }
    }
    
    return -1;
}
