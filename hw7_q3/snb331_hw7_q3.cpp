/*
Question 3:
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)
This function gets an array of integers arr and its logical size arrSize. When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).
For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]

Implementation requirements:
1. Your function should run in linear time. That is, if there are n items in arr, calling
oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
2. Write a main() program that tests this function.
3. Note that at the end, the elements should be stored starting at the same base
address, as was given in arr.
 */

#include <iostream>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void splitParity(int arr[], int arrSize);
int findMinEven(int arr[], int arrSize);
void reverseEvens(int arr[], int indFirstEven, int arrSize);
int main() {
    int testCase1[6] = {5, 2, 11, 7, 6, 4};
    int testCase2[6] = {5, 2, 11, 6, 4, 7};
    int testCase3[6] = {2, 4, 6, 8, 10, 12};
    int testCase4[6] = {1, 3, 5, 7, 9, 11};
    int testCase5[5] = {2,3,5,9,7};
    int testCase6[5] = {2,4,5,6,8};

    oddsKeepEvensFlip(testCase1, 6);
    printArray(testCase1, 6);            // 5 11 7 4 6 2

    oddsKeepEvensFlip(testCase2, 6);
    printArray(testCase2, 6);            // 5 11 7 4 6 2

    oddsKeepEvensFlip(testCase3, 6);
    printArray(testCase3, 6);            // 12 10 8 6 4 2

    oddsKeepEvensFlip(testCase4, 6);
    printArray(testCase4, 6);            // 1 3 5 7 9 11

    oddsKeepEvensFlip(testCase5, 5);
    printArray(testCase5, 5);            // 3 5 9 7 2

    oddsKeepEvensFlip(testCase6, 5);     // 5 8 6 4 2
    printArray(testCase6, 5);



    return 0;
}


void printArray(int arr[], int arrSize){
    for (int ind = 0; ind < arrSize; ind++)
        cout<<arr[ind]<<" ";

    cout<<endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    int indexOfFirstEven, indOfLastEven;
    splitParity(arr, arrSize);

    if(findMinEven(arr, arrSize) != string::npos){
        indexOfFirstEven = findMinEven(arr, arrSize);
        indOfLastEven = arrSize - 1;
        reverseEvens(arr, indexOfFirstEven, indOfLastEven);
    }
}

void reverseEvens(int arr[], int indFirstEven, int indLastEven){
    int tempInt, indMidEven;

    indMidEven = indFirstEven + ((indLastEven-indFirstEven)/2);
    while (indFirstEven <= indMidEven) {
        tempInt = arr[indFirstEven];
        arr[indFirstEven] = arr[indLastEven];
        arr[indLastEven] = tempInt;
        indFirstEven += 1;
        indLastEven -= 1;
    }
}

void splitParity(int arr[], int arrSize){
    int i1, j1, i2, j2;
    int ival1, jval1, ival2, jval2;

    i1 = 0;
    j1 = 1;
    i2 = arrSize - 2;
    j2 = arrSize -1;

    while (i1 <= arrSize && i2 >= 0) {
        ival1 = arr[i1];
        jval1 = arr[j1];
        if (ival1 % 2 ==0 && jval1 % 2 != 0){
            arr[i1] = jval1;
            arr[j1] = ival1;
        }
        i1 += 1;
        j1 += 1;
        ival2 = arr[i2];
        jval2 = arr[j2];
        if (ival2 % 2 ==0 && jval2 % 2 != 0){
            arr[i2] = jval2;
            arr[j2] = ival2;
        }
        i2 -= 1;
        j2 -= 1;
    }
}

int findMinEven(int arr[], int arrSize){
    for (int ind = 0 ; ind < arrSize; ind++){
        if (arr[ind] % 2 == 0)
            return ind;
    }
    return string::npos;
}