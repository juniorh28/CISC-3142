//Junior Hernandez
//CISC 3142
//Homework 2.1

#include <iostream>

using namespace std;

/**
 * strCmp
 * params: const char* (pointer of string 1)
 * params: const char* (pointer of string 2)
 * return: int
 * method: compares two strings and return -1 if s1 < s2, 0 if equal, or 1 if s1 > s2
*/
int strCmp(const char *s1, const char *s2){

    int index = 0;
    //as long as s1 is not finished (looking at null terminating char)
    while (s1[index] != '\0')
    {  
        //if s1 comes before s2
        if(s1[index] < s2[index])
            return -1;
        //if s1 comes after s2
        else if(s1[index] > s2[index])
            return 1;
        //if both are equal check the next index
        else 
            ++index;
    }
    
    //since there's no more comparision for s1, if the same is true for s2, then s1 and s2 MUST be equal
    if(s1[index] == s2[index])
        return 0;
    //if not equal then s1 MUST be smaller
    else
        return -1;
}

/**
 * strSwap
 * params: char *&s1 (pointer to a reference of s1)
 * params: char *&s2 (pointer to a reference of s2)
 * return: void
 * method: have s1 point to s2 and s2 point to s1.
*/
void strSwap(char *&s1, char *&s2){
    char* temp = s1;
    s1 = s2;
    s2 = temp;
}

/**
 * strBubbleSort
 * params: char* arrStr[] (char pointer to array)
 * params: int
 * return: void
 * method: sort the array in ascending order.
*/
void strBubbleSort(char *arrStr[], int n){
    int result;
    for(int i=1; i < n; ++i){
        for(int j=1; j < n-i; ++j){
            result = strCmp(arrStr[j],arrStr[j+1]);
            if(result == 1)
                strSwap(arrStr[j],arrStr[j+1]);
        }
    }
}

/**
 * printArr
 * params: char* arrStr[]
 * params: int
 * return: void
 * method: print the array
*/
void printArr(char *arrStr[], int n){
    for(int i=1; i<n; ++i){
        cout << arrStr[i] <<endl;
    }
}

int main(int argc, char* argv[]){
/*
    command line arguements uses c-strings meaning the size of the string is the number of char + 1.
    + 1 refering to the null terminating character \0.
    e.g. "Hello" size 5, is really size 6, because we need to store room for \0.
*/

    //if there is no args (besides the executable) .
    if(argc == 1)
        cout <<"Error no argugments" << endl;

    else{
        //allocate memory for argsCopy to copy the arguemtns
        char **argCopy = new char* [argc];
        cout << "your input is:\n";

        //deep copy all content of arguement into argsCopy.
        for(int i = 1; i<argc; ++i){
            argCopy[i] = argv[i];
            cout<< argCopy[i] << endl;
        }

        cout << "\nYour output is:" << endl;

        //bubble sort the copy in ascending order
        strBubbleSort(argCopy, argc);
        printArr(argCopy, argc);

        //deallocate memory
        delete[] argCopy;
    }

    return 0;
}