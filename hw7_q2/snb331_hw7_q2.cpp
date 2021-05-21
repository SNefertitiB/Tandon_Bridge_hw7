/*
Question 2:
Two strings are anagrams if the letters can be rearranged to form each other.
For example, “Eleven plus two” is an anagram of “Twelve plus one”. Each string
contains one ‘v’, three ‘e’s, two ‘l’s, etc.

Write a program that determines if two strings are anagrams. The program should
not be case sensitive and should disregard any punctuation or spaces.

Notes:
1)  Think how to break down your implementation to functions
2)  Pay attention to the running time of your program. If each input string contains 𝑛
characters, an efficient implementation would run in a linear time (that is Θ(𝑛)).

 */


#include <iostream>
#include <string>
using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void count_letters(string str, int counter[]);
bool are_anagrams(string string1, string string2);
int main() {
    string str1, str2;

    cout<<"Please enter string 1"<<endl;
    getline(cin, str1);

    cout<<"Please enter string 2"<<endl;
    getline(cin, str2);

    if(are_anagrams(str1, str2))
        cout<<"String 1 and 2 are anagrams"<<endl;
    else
         cout<<"String 1 and 2 are not anagrams"<<endl;

    return 0;
}

void count_letters(string str, int counter[]){
    char currentChar;
    int counterIndex;

    for (int ind = 0; ind < str.length(); ind++){
        if (str[ind] >= 'A' && str[ind]<= 'Z')
            currentChar = str[ind] + 32;
        else
            currentChar = str[ind];

        if (ALPHABET.find(currentChar) != string :: npos){
            counterIndex = ALPHABET.find(currentChar);
            counter[counterIndex] += 1;
        }
    }
}

bool are_anagrams(string string1, string string2){
    int string1Counter[26] = {0};
    int string2Counter[26] = {0};

    count_letters(string1, string1Counter);
    count_letters(string2, string2Counter);

    for (int ind = 0; ind < 26; ind++){
        if (string1Counter[ind] != string2Counter[ind])
            return false;
    }

    return true;
}
