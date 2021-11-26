//Junior Hernandez
//CISC 3142
//Homework 4.1

#include <iostream>
#include <string>
#include <stdio.h>
#include <locale>

using std::cout;
using std::endl;
using std::string;

/**
 * @brief - will move all the characters up 1 int at a time until it finds the word 'Yanks' or it reaches its original state
 * 
 * @param s1 - The first char array to compare to find 'Yanks' and get us the shiftNum
 * @return int - the amount of attempts to find the word 'Yanks
 */
int decipher(const char s1[], const string hint)
{

    //copy s1 into temp to allow manipulation
    int length = strlen(s1);
    char temp[length];
    strcpy(temp, s1);

    //the number of times it took to find the hint
    int attempt = 0;

    //checks to see if temp and s1 are the same, initially it is, but once it goes loops we need to check if its back to original state
    int value = strcmp(s1, temp);

    bool found = false;

    string str;
    do
    {
        //loop and increase the char value of temp[i] by 1
        for (int i = 0; i < length; ++i)
        {
            //reset back to Capital A
            if (temp[i] == 'Z')
            {
                temp[i] = 'a';
            }
            //reset back to lower case A
            else if (temp[i] == 'z')
            {
                temp[i] = 'A';
            }
            //set the char value of temp to the next char value
            else
            {
                temp[i] = ++temp[i];
            }
        }

        //compare if temp is back to original state
        value = strcmp(s1, temp);


        ++attempt; //increase the attempt

        //string so we can use .find of the hint
        string str2(temp);
        str = str2; //convert the char array into string

        if (str.find(hint) != string::npos)
        {
            cout << "found on attempt #: " << attempt << endl;
            cout << "s1: " << s1 << endl;
            cout << "str: " << str << endl;
            found = true;
            break;
        }

        //need to set str outside do while but without appending all the time

    } while (strcmp(s1, temp) != 0); //loop until the value we seek is found or the temp is back to original state

    if (found == false)
    {
        attempt = -1;
    }

    return attempt;
}

/**
 * @brief - will take the 2nd string and move it up to the shiftNum, using the alphabet as reference
 * 
 * @param s2 - the string that needs to be deciphered
 * @param shiftNum - how many space we will move the string
 * @param alphabet - a reference to find the modulus 
 */
void decipherUpTo(const char s2[], int shiftNum, const string alphabet)
{
    int length = strlen(s2);
    char temp[length];
    strcpy(temp, s2);

    //loop and increase the char value of temp[i] up to the shift number
    for (int i = 0; i < length; ++i)
    {
        //get the index of the letter
        int indx = alphabet.find(temp[i]);
        //if the indx and shiftNum combined is larger than 52, get the remainder
        if (indx + shiftNum > alphabet.length())
        {
            int newShiftNum = (indx + shiftNum) % alphabet.length();
            temp[i] = alphabet[newShiftNum];
        }
        //else assign temp the value of indx moved by the shiftNum
        else{
            temp[i] = alphabet[indx + shiftNum];
        }
    }

    cout << temp << endl;
}

int main()
{

    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    //strings to be deciphered
    char s1[] = "uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST";
    char s2[] = "dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT";

    const string hint = "Yanks";

    int decipherNum = decipher(s1, hint);

    if (decipherNum > 0)
    {
        cout << hint << " was found on attempt #" << decipherNum << endl;
    }
    decipherUpTo(s2, decipherNum, alphabet);

    return 0;
}