/*
Question 4:
Implement the function:
string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence.
When called, it should create and return a new array (of strings),
that contains all the words in sentence. The function should also
update the output parameter, outWordsArrSize, with the logical size
of the new array that was created.

Note: Assume that the words in the sentence are separated by a single space.

 For example, if sentence=”You can do it”, after calling createWordsArray(sentence, outWordsArrSize), the function should create and return an array that contains [”You” , ”can” , ”do” , ”it”], and update the value in outWordsArrSize to be 4.
Implementation requirements:
1. You may want to use some of the string methods, such as find, substr, etc.
2. Your function should run in linear time. That is, if sentence contains n characters,
your function should run in 𝜃(𝑛).
3. Write a main() program that tests this function..
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printStringArray(string arr[], int size);
int main() {
    string uiString;
    int wordsArrSize;
    string* wordsArray;

    cout<<"Please enter a sentence:"<<endl;
    getline(cin, uiString);

    wordsArray = createWordsArray(uiString, wordsArrSize);
    cout<<"There are "<<wordsArrSize<<" words in your sentence and they are:"<<endl;
    printStringArray(wordsArray, wordsArrSize);
    cout<<endl;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){ //string* createWordsArray(string sentence, int& outWordsArrSize)
    int numberOfWords = 0;
    int startWordIndex, wordLength;
    string currentWord;
    vector <string> tempWordsVector;
    string* wordsArray;

    startWordIndex = 0;
    for (int ind = 0; ind < sentence.length(); ind++){
        if (sentence[ind] == ' ' || ind == sentence.length()-1 ){
            if (sentence[ind] == ' ')
                wordLength = ind - (startWordIndex);
            else if (ind == sentence.length()-1){
                if ((sentence[ind] >='A' && sentence[ind] <= 'Z') ||
                (sentence[ind] >='a' && sentence[ind] <= 'z'))
                    wordLength = (ind +1) - startWordIndex;
                else
                    wordLength = (ind) - startWordIndex;
            }
            currentWord = sentence.substr(startWordIndex, wordLength);
            numberOfWords += 1;
            tempWordsVector.push_back(currentWord);
            startWordIndex = ind + 1;
        }
    }

    wordsArray = new string[numberOfWords];
    for (int ind = 0; ind < numberOfWords; ind++){
        wordsArray[ind] = tempWordsVector[ind];
    }

    outWordsArrSize = numberOfWords;
    return wordsArray;
}

void printStringArray(string arr[], int size){
    for (int ind = 0; ind < size; ind++)
        cout<<"\""<<arr[ind]<<"\""<<"\t";
}