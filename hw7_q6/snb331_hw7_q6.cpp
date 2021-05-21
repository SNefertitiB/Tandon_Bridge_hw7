/*
Question 6:
In this question, you will write two versions of a program that reads
from the user a sequenceof positive integers ending with -1, and another
positive integer num that the user wishes to search for.
The program should then print all the line numbers in sequence entered by
the user, that contain num, or a message saying that num does not show at all in the sequence.
13
5
8
2
9
5
8
8
-1

Please enter a number you want to search: 5
5 shows in lines 2, 6.
a) The first version of the program, is not allowed to use the vector data structure.
b) The second version of the program, should use the vector data structure.

Implementation requirements (for both programs):
1. Think how to break down your implementation to functions.
2. Your programs should run in linear time. That is, if there are n numbers in the input
sequence, your program should run in 𝜃(𝑛).
3. Write the two programs in two functions named main1() and main2(). Also have
the main() test these two functions.
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int arrSize);
void printVector (vector <int> vect);
void main1();
void main2();
void arrayPush_Back(int* & arr, int &logicalArrSize, int &actualArrSize, int newInt);
void arrayOfIntLines(int arr[], int arrSize, int searchVal, int * &outArray, int &outArraySize);
vector <int> findIntIndices(vector <int> searchVector, int searchInt);
int main() {
    main1();
    main2();
    return 0;
}

void main1(){
    int currentInt, findInt;
    int* uiArr = new int[5];
    int logicalUIArrSize = 0, actualUIArrSize = 5;
    int* searchArr;
    int logicalSearchArrSize = 0, actualSearchArrSize;

    cout<<"Please enter a sequence of positive integers ending with -1:"<<endl;
    cin>>currentInt;
    while (currentInt >= 0 ){
        arrayPush_Back(uiArr, logicalUIArrSize, actualUIArrSize, currentInt);
        cin>>currentInt;                                           // 13, 5, 8, 2, 9, 5, 8, 8
    }

    cout<<"Please enter a number you want to search: ";
    cin>>findInt;                                                  //  5

    actualSearchArrSize = logicalUIArrSize;
    searchArr = new int[actualSearchArrSize];
    arrayOfIntLines(uiArr, logicalUIArrSize, findInt, searchArr, logicalSearchArrSize);
    if (logicalSearchArrSize == 0)
        cout<<findInt<<" not found in sequence"<<endl;
    else{
        cout<<findInt<<" shows in line(s) ";
        printArray(searchArr, logicalSearchArrSize);                   // 2, 6.
        cout<<endl;
    }
    cout<<endl;
}

void arrayPush_Back(int* &arr, int &logicalArrSize, int &actualArrSize, int newInt){
    int* tempArray;

    if (logicalArrSize == actualArrSize - 1){
        tempArray = new int[actualArrSize * 2];
        for (int ind = 0; ind < logicalArrSize; ind++)
            tempArray[ind] = arr[ind];
        delete []arr;
        arr = tempArray;
        actualArrSize *= 2;
    }
    arr[logicalArrSize] = newInt;
    logicalArrSize += 1;
}

void arrayOfIntLines(int arr[], int arrSize, int searchVal, int* &outArray, int &outArraySize){
    int lineNumber;
    for (int ind = 0; ind < arrSize; ind++) {
        if (arr[ind] == searchVal){
            lineNumber = ind + 1;
            arrayPush_Back(outArray, outArraySize, arrSize, lineNumber);
        }
    }
}

void main2(){
    int currentInt, intCounter, findInt;
    vector <int> intVector, indexVector;

    cout<<"Please enter a sequence of positive integers ending with -1:"<<endl;
    cin>>currentInt;

    intCounter = 0;
    while (currentInt >= 0 ){
        intVector.push_back(currentInt);
        intCounter += 1;
        cin>>currentInt;
    }
    cout<<"Please enter a number you want to search: ";
    cin>>findInt;                                         //  5

    indexVector = findIntIndices(intVector, findInt);

    if (indexVector.size() == 0 )
        cout<<findInt<<" not found in sequence"<<endl;
    else{
        cout<<findInt<<" shows in line(s) ";
        printVector(indexVector);                        // 2, 6.
        cout<<endl;
    }

}

void printArray(int arr[], int arrSize){
    for (int ind = 0; ind < arrSize; ind++){
        if (ind != arrSize - 1)
            cout<<arr[ind]<<", ";
        else
            cout<<arr[ind]<<".";
    }
}

void printVector(vector<int> vect){
    for (int ind = 0; ind < vect.size(); ind++){
        if (ind != vect.size() - 1)
            cout<<vect[ind]<<", ";
        else
            cout<<vect[ind]<<".";
    }
}

vector <int> findIntIndices(vector <int> searchVector, int searchInt){
    vector <int> indVector;
    for (int ind = 0; ind < searchVector.size(); ind++){
        if (searchVector[ind] == searchInt)
            indVector.push_back(ind+1);
    }
    return indVector;
}

