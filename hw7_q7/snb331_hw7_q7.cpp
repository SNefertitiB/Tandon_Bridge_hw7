/*
Question 7:
Implement the function:
int* findMissing(int arr[], int n, int& resArrSize)
This function gets an array of integers arr and its logical size n.
All elements in arr are in the range {0, 1, 2, ... , n}.

Note that since the array contains n numbers taken from a range of size n+1,
there must be at least one number that is missing (could be more than one
number missing, if there are duplicate values in arr).

When called, it should create and return a new array, that contains all the
numbers in range {0, 1, 2, ... , n} that are not in arr. The function should
also update the output parameter, resArrSize, with the logical size of the
new array that was created.

For example, if arr=[3, 1, 3, 0, 6, 4], after calling
findMissing(arr, 6, resArrSize), the function should create and return an
array that contains [2, 5], and update the value in resArrSize to be 2.

Implementation requirements:
1. Your function should run in linear time. That is, it should run in 𝜃(𝑛).
2. Write a main() program that tests this function..
 */

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArray (int arr[], int arrSize);
int main() {
    int *missingFromArr1, missingFromArr1LogicalSize;
    int arr1[6] = {3, 1, 3, 0, 6, 4}, arr1LogicalSize = 6;

    int *missingFromArr2, missingFromArr2LogicalSize;
    int arr2[10] = {1, 1, 3, 3, 5, 5, 7, 7, 8, 8}, arr2LogicalSize = 10;

    int *missingFromArr3, missingFromArr3LogicalSize;
    int arr3[2] = {0, 2}, arr3LogicalSize = 2;

    missingFromArr1 = findMissing(arr1, arr1LogicalSize, missingFromArr1LogicalSize);
    printArray(arr1, arr1LogicalSize);
    cout<<" is missing ";
    printArray(missingFromArr1, missingFromArr1LogicalSize);
    cout<<endl;

    missingFromArr2 = findMissing(arr2, arr2LogicalSize, missingFromArr2LogicalSize);
    printArray(arr2, arr2LogicalSize);
    cout<<" is missing ";
    printArray(missingFromArr2, missingFromArr2LogicalSize);
    cout<<endl;

    missingFromArr3 = findMissing(arr3, arr3LogicalSize, missingFromArr3LogicalSize);
    printArray(arr3, arr3LogicalSize);
    cout<<" is missing ";
    printArray(missingFromArr3, missingFromArr3LogicalSize);
    cout<<endl;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int* arrRange = new int[n + 1];
    int* missing;
    int missingCount = 0, missingInd;

    for (int ind = 0; ind < n; ind++){
        arrRange[arr[ind]] += 1;
    }

    for (int ind = 0; ind < n +1; ind++){
        if (arrRange[ind] == 0)
            missingCount += 1;
    }

    missing = new int[missingCount];
    missingInd = 0;
    for (int ind = 0; ind < n+1; ind ++) {
        if (arrRange[ind] == 0) {
            missing[missingInd] = ind;
            missingInd += 1;
        }
        if (missingInd == missingCount)
            break;
    }

    resArrSize = missingCount;
    return missing;
}

void printArray (int arr[], int arrSize){
    cout<<"[";
    for (int ind= 0; ind < arrSize; ind++){
        cout<<arr[ind];
        if (ind != arrSize - 1)
            cout<<", ";
    }
    cout<<']';
}