# 2.1 Sorting command line arguments (3-pt)

This exercise is all about procedural programming (lec3), and specifically the topics of pointers, arrays, and loops. 
Write a C++ program that prints out all command line arguments both in their original order and in the alphabetically sorted order. 
To demonstrate your grasp of the language's built-in facility, your program should NOT use any standard library features except for cout from iostream. 
Specifically you should write your own versions of the following functions (some of these are named differently from their standard library counterparts):

    int strCmp(const char* s1, const char* s2); // returns -1 if s1 should appear before s2, 0 if s1 and s2 are exactly the same, 1 if s1 appears after s2. All in alphabetic order according to the ASCII table. Note: you could instead return the ASCII table position difference of the unmatched characters from s1 and s2, which is the behavior of the C-library function strcmp().
    void strSwap(char* &s1, char* &s2); // allows two char* pointers to be swapped, i.e. afterwards, s1 will point to what s2 was pointing at and vice versa
    void strBubbleSort(char* arrStr[], int n); // uses bubble sort to put all strings in arrStr in an alphabetic order. The array has size of n and will be modified as the result of this function

Example output
>hw2_1 an agile fox jumps over a lazy dog

Your input is:
  an
  agile
  fox
  jumps
  over
  a
  lazy
  dog

Your output is:
  a
  agile
  an
  dog
  fox
  jumps
  lazy
  over
Some Helpful Info

    In int main(int argc, char* argv[]){}, the value of argc is 1 plus the actual number of command line parameters entered after the executable. argv[1] is the first paramter (argv[0] refers to the executable itself)
    Your program should leave argv[] untouched, i.e. do not modify argv[] itself! This means that you need to allocate memory (using new) to make a copy of argv[], and properly release the memory when you're done with it.
        To allocate memory to hold an array of C-style strings: use char** argCopy = new char*[n];
        Then, each argCopy[i] can hold one of the words. The individual characters of each word need not to be copied.
    In case that you don't know bubble sort (many students have submitted incorrect implementations in the past), please take a look at this wiki article - only that now we're comparing c-style strings, not integers.
    Your program should print an error message and exit if no command line parameters were passed
    Please make sure to test with the example shown above

Reference
https://www.youtube.com/watch?v=h2LGTzQXzJU