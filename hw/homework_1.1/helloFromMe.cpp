//Junior Hernandez
//CISC 3142
//Homework 1.1 Hello From You

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Border
{

public: // Access specifier

    /**
     * PrintArray
     * params: string[]
     * return: void
     * method: prints all value of an array
    */
    void PrintArray(string array[], int arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            cout << " " << array[i];
        }
    }

    /**
     * Gap
     * params: int borderSize
     * params: int stringSize
     * parmas: int nameSize
     * return: void
     * method: adds gap up to the the border
    */
    void Gap(int borderSize, int stringSize, int nameSize)
    {
        int spaceRemaining = (borderSize - (stringSize + nameSize));
        for (int x = 0; x < spaceRemaining; x++)
        {
            cout << " ";
        }
    }

    /**
     * BorderBox
     * params: none
     * return: void
     * method: reads in input file, prints results in box
    */
    void BorderBox()
    {
        try
        {
            int a = 0;
            int longestWord = 0;
            int sizeOfAllWords = 0;
            int borderSize = 0;
            string name;
            string word;
            string helloStr = " Hello From ";
            string programStr = " Have programmed in:";

            ifstream inputFile("input.txt");
            if (!inputFile.good())
                throw string("Failure opening input.txt");

            string languageArray[20];
            int languageKnown = 0;

            //grab all the name and all the programming language from file
            while (getline(inputFile, word))
            {
                if (word.length() > longestWord && a != 0)
                    longestWord = word.length();
                if (a == 0) //the first line is the name
                    name = word;
                else
                {
                    //add the langauge to the array, a-1 to set proper index
                    languageArray[languageKnown] = word;
                    languageKnown++;
                    //+ 1 is the space before the word(i.e:_Java)
                    sizeOfAllWords += word.length() + 1;
                }
                a++;
            }

            
            int nameLength = name.length();
            //border size of the box
            if (sizeOfAllWords > programStr.length() && sizeOfAllWords > (helloStr.length() + name.length()))
                borderSize = sizeOfAllWords;
            else if (name.length() + helloStr.length() > programStr.length())
                borderSize = name.length() + helloStr.length();
            else
                borderSize = programStr.length();

            //3 is the number of line we want the box to be
            for (int i = 0; i < 3; i++)
            {

                if (i == 0 || i == 2)
                {
                    //starting top +
                    cout << "+";
                    for (int j = 0; j <= borderSize; j++)
                    {
                        cout << "-";
                    }
                    //ending top +
                    cout << "+\n";
                }
                else
                {
                    for (int j = 0; j < 3; j++)
                    {
                        //starting line
                        cout << "|";
                        if (j == 0)
                        {
                            cout << helloStr << name;
                            Gap(borderSize, helloStr.length(), name.length());
                        }
                        else if (j == 1)
                        {
                            cout << programStr;
                            Gap(borderSize, programStr.length(), 0);
                            cout << " |\n";
                            continue;
                        }
                        else
                        {
                            PrintArray(languageArray, languageKnown);
                            Gap(borderSize, sizeOfAllWords, 0);
                        }
                        //closing line then new line
                        cout << " |\n";
                    }
                }
            }
            inputFile.close();
        }
        catch (string message)
        {
            cerr << message << endl;
            exit(1);
        }
    }
};

int main()
{
    Border Obj;    // Create an object of MyClass
    Obj.BorderBox(); // Call the method

    return 0;
}