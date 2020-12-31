/*
 * This is another test program to go along with Timer.c
 * It's probably not good but it's bogosort so what does 
 * it matter. 
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
isSorted(int* data, int len){
        for (int i = 0; i < len - 1; ++i){
                if (!(data[i] < data[i + 1])){
                        return 0;
                }
        }
        return 1;
}

void
printArray(int* data, int len){
        for (int i = 0; i < len; ++i){
                printf("%i ", data[i]);
        }
        putchar('\n');
}


// Should this act like an iterator or should it just swap every position?

void
shuffle(int* data, int len){
        // i = current position in array
        // shufflePos = position to swap with i
        for (int i = 0; i < len; ++i){
                int shufflePos = rand() % len;
                
                int temp = data[i];
                data[i] = data[shufflePos];
                data[shufflePos] = temp;
        }
}

int
bogosort(int* data, int len){
        int i = 0;
        while(!(isSorted(data, len))){
                shuffle(data, len);
                ++i;
        }
        return i;
}


int main(int argc, char** argv){

        // Initialize rand()
        srand(time(NULL));
        int testArr[12] = {9,1,8,2,7,3,6,4,5,10,15,17};
        int len = sizeof(testArr) / sizeof(testArr[0]);
        // TODO: converty argv to int
        printf("Length: %i\n", len);
        printf("Initial: ");
        printArray(testArr, len);
        
        printf("Bogosort took %i cycles\n", bogosort(testArr, len));
        
        printf("Sorted: ");
        printArray(testArr, len);
}
