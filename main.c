#include <stdio.h>
#include <stdlib.h>

typedef u_int8_t byte;

void swap_int(int *a, int *b);
void getArrElemVals(int **arrPtr, int len);
void allocateArray_int(int **arrPtr, byte arrLen);
void insertionSort(int *arrPtr1, int **arrPtr2, byte arrLen);
void printArrElems(int *arr, byte arrLen);

/*/ The Main Program /*/
int main() {

    // Variables
    auto int *arr1;
    auto int *arr2;
    auto byte arrLen;

    // Get Array with It's Length
    printf( "Please enter a length for array: " );
    scanf("%i", &arrLen);

    // Exit If The Length is Greater than 255
    if(arrLen > 255) return 0;

    // Allocate Arrays and Point to It
    allocateArray_int(&arr1, arrLen);
    allocateArray_int(&arr2, arrLen);

    // Get Value of Elements from User
    getArrElemVals(&arr1, arrLen);

    // Sort The Array Using Insertion Sort Algorithm
    insertionSort(arr1, &arr2, arrLen);

    // Print Array Elements
    printArrElems(arr2, arrLen);

    free(arr1);
    free(arr2);
    return 0;
}

/*/ Swap Values /*/
void swap_int(int *a, int *b){

    auto int tmp = *a;
    *a = *b;
    *b = tmp;

}

/*/ Point to Allocated Array /*/
void allocateArray_int(int **arrPtr, byte arrLen){

    *arrPtr = calloc( (size_t) arrLen, sizeof(int) );

    if (*arrPtr == NULL) {
        printf("\nArray Allocation FAILED !!!\n");
        exit(0);
    }

}

/*/ Get Value of Array Elements from User Input /*/
void getArrElemVals(int **arrPtr, int len){

    for( register byte i = 0; i < len; i++ ){

        printf("Value of Index %i: ", i);
        scanf( "%i", (*arrPtr + i) );

    }

}

/*/ Sort Array Using Insertion Sort Algorithm /*///e.g. {12, 6, 9, 11, 7, 10, 2, 5, 3, 1, 4, 8}
void insertionSort(int *arrPtr1, int **arrPtr2, byte arrLen) {

    // Insert The First Element
    *(*arrPtr2) = *arrPtr1;

    for (register byte i = 1; i < arrLen; i++) {

        // Insert This Element
        *(*arrPtr2 + i) = *(arrPtr1 + i);

        // Hold It's Index
        register byte elemIndex = i;

        // Loop
        // if :: it's not the first element
        // and if :: this element is less than it's previous element
        while ( elemIndex != 0 && *(*arrPtr2 + elemIndex) < *(*arrPtr2 + (elemIndex - 1)) ) {

            // Swap This Element with It's Previous Element
            swap_int( *arrPtr2 + elemIndex, *arrPtr2 + elemIndex - 1 );
            elemIndex--;

        }

    }

}

/*/ Show Array Elements /*/
void printArrElems(int *arr, byte arrLen){

    for (register byte i = 0; i < arrLen; i++)
        printf("%i, ", *(arr + i));

    printf("\b\b\n");

}