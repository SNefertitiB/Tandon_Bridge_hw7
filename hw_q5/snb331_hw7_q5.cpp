/*
Question 5:
In this question, you will write four versions of a function getPosNums that gets an
array of integers arr, and its logical size. When called it creates a new array containing
only the positive numbers from arr.

For example, if arr=[3, -1, -3, 0, 6, 4], the functions should create an array
containing the following 3 elements: [3, 6, 4],

The four versions you should implement differ in the way the output is returned.
The prototypes of the functions are:
a) int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
returns the base address of the array (containing the positive numbers), and updates the output parameter outPosArrSize with the array’s logical size.

b) int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
returns the base address of the array (containing the positive numbers), and uses the pointer outPosArrSizePtr to update the array’s logical size.

c) void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
updates the output parameter outPosArr with the base address of the array (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.

d) void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.

 Note: You should also write a program that calls and tests all these functions.
 */

#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
//returns the base address of the array (containing the positive numbers),
// and updates the output parameter outPosArrSize with the array’s logical size.

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
//returns the base address of the array (containing the positive numbers),
// and uses the pointer outPosArrSizePtr to update the array’s logical size.

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
//updates the output parameter outPosArr with the base address of the array (containing the positive numbers),
// and the output parameter outPosArrSize with the array’s logical size.

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
//uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers),
// and the pointer outPosArrSizePtr to update the array’s logical size.

void printIntArr(int arr[], int arrSize);
void testArr1();
void testArr2();
int main() {

    testArr1();

    testArr2();



    return 0;
}

void printIntArr(int arr[], int arrSize){
    for (int ind = 0; ind < arrSize; ind++)
        cout<<arr[ind]<<" ";
    cout<<endl;
}

// returns the base address of the array (containing the positive numbers),
// and updates the output parameter outPosArrSize with the array’s logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int posCounter = 0;
    int* posArray;
    vector <int> posVector;
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind] > 0){
            posCounter += 1;
            posVector.push_back(arr[ind]);
        }
    }

    posArray = new int[posCounter];
    for (int ind = 0; ind < posCounter; ind++){
        posArray[ind] = posVector[ind];
    }

    outPosArrSize = posCounter;
    return posArray;

}

//returns the base address of the array (containing the positive numbers),
// and uses the pointer outPosArrSizePtr to update the array’s logical size.
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int posCounter = 0;
    int* posArray;
    vector <int> posVector;
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind] > 0){
            posCounter += 1;
            posVector.push_back(arr[ind]);
        }
    }

    posArray = new int[posCounter];
    for (int ind = 0; ind < posCounter; ind++){
        posArray[ind] = posVector[ind];
    }

    *outPosArrSizePtr = posCounter;
    return posArray;
}

//updates the output parameter outPosArr with the base address of the array
// (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int posCounter = 0;
    vector <int> posVector;
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind] > 0){
            posCounter += 1;
            posVector.push_back(arr[ind]);
        }
    }

    outPosArr = new int[posCounter];
    for (int ind = 0; ind < posCounter; ind++){
        outPosArr[ind] = posVector[ind];
    }

    outPosArrSize = posCounter;
}

//uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers),
// and the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int posCounter = 0;
    vector <int> posVector;
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind] > 0){
            posCounter += 1;
            posVector.push_back(arr[ind]);
        }
    }

    *outPosArrPtr = new int[posCounter];
    for (int ind = 0; ind < posCounter; ind++){
        (*outPosArrPtr)[ind] = posVector[ind];
    }

    *outPosArrSizePtr = posCounter;
}

void testArr1(){
    int arr1[6]= {3, -1, -3, 0, 6, 4};
    int arr1Size = 6;
    int *test1Arr1, posArr1Size;
    int *test2Arr1, posArr1Size2;
    int *test3Arr1, posArr1Size3;
    int *test4Arr1, posArr1Size4;


    cout<<"Testing on arr 1 \nValues are:";
    printIntArr(arr1, arr1Size);

    cout<<"getPosNums1:\t";
    test1Arr1 = getPosNums1(arr1, arr1Size, posArr1Size);
    printIntArr(test1Arr1, posArr1Size);                        // 3 6 4

    cout<<"getPosNums2:\t";
    test2Arr1 = getPosNums2(arr1, arr1Size, &posArr1Size2);
    printIntArr(test2Arr1, posArr1Size2);                   // 3 6 4

    cout<<"getPosNums3:\t";
    getPosNums3(arr1, arr1Size, test3Arr1, posArr1Size3);
    printIntArr(test3Arr1, posArr1Size3);                       // 3 6 4
    delete []test3Arr1;

    cout<<"getPosNums4:\t";
    getPosNums4(arr1, arr1Size, &test4Arr1, &posArr1Size4);
    printIntArr(test4Arr1, posArr1Size4);
    delete []test4Arr1;

    cout<<endl;
}

void testArr2(){
    int arr2[10] = {-5, -4, 4, -3, 3, -2, 2, -1, 1, 0};
    int arr2Size = 10, *testArr2, posArr2Size;

    cout<<"Testing on arr 2 \nValues are:";
    printIntArr(arr2, arr2Size);

    cout<<"getPosNums1:\t";
    testArr2 = getPosNums1(arr2, arr2Size, posArr2Size);
    printIntArr(testArr2, posArr2Size);
    delete [] testArr2;
    testArr2 = NULL;

    cout<<"getPosNums2:\t";
    testArr2 = getPosNums2(arr2, arr2Size, &posArr2Size);
    printIntArr(testArr2, posArr2Size);
    delete [] testArr2;
    testArr2 = NULL;

    cout<<"getPosNums3:\t";
    getPosNums3(arr2, arr2Size, testArr2, posArr2Size);
    printIntArr(testArr2, posArr2Size);
    delete [] testArr2;
    testArr2 = NULL;

    cout<<"getPosNums4:\t";
    getPosNums4(arr2, arr2Size, &testArr2, &posArr2Size);
    printIntArr(testArr2, posArr2Size);
    delete [] testArr2;
    testArr2 = NULL;

    cout<<endl;
}