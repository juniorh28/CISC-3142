//Junior Hernandez
//homework 1.2 Factor
//CISC 3142

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/**
 * printArray
 * params: int[] a
 * params: int n
 * params: ofstream outputFile
 * return: void
 * method: write all values of array onto an output file
*/
void printArray(int a[], int n, ofstream &outputFile)
{
    for (int i = 0; i < n; i++)
        if(i == n-1)
            outputFile << a[i];
        else
            outputFile << a[i] << ", ";
    outputFile << "\n";
}

/**
 * swapInt
 * params: int i1
 * params: int i2
 * params: int[] a
 * return: void
 * method: changes the integers of the given params
*/
void swapInt(int &i1, int &i2, int a[])
{
    int temp = a[i1];
    a[i1] = a[i2];
    a[i2] = temp;
}

/**
 * reverseArray
 * params: int[] a
 * params: int n
 * return: void
 * method: gets an array and reverse it, swaping int with function
*/
void reverseArray(int a[], int n, ofstream &outputFile)
{

    for (int i = 0; i < n/2; i++)
    {
        int b = n - i - 1;
        swapInt(i, b, a);
    }
    printArray(a, n, outputFile);
}

int main()
{
    try
    {
        int num;
        string fileNum;
        int factors[num];
        ifstream inputFile("input.txt");
        if (!inputFile.good())
            throw string("Failure opening input.txt");

        ofstream outputFile("output.txt");
        if (!outputFile.good())
            throw string("Failure opening output.txt");

        while (getline(inputFile, fileNum))
        {
            int idx = 0;
            //converts string to int
            num = stoi(fileNum);
            outputFile << num << ": ";
            bool isFirst = true;
            //go up to sqrt of the num
            //print factor of num, i, and add its compliement to array
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (num % i == 0)//its a factor
                {
                    outputFile << (isFirst ? "" : ", ") << i;
                    if (num / i != sqrt(num))//its repeating
                        factors[idx++] = num / i;
                    if (isFirst)
                        isFirst = false;
                }
            }
            
            if(isFirst)//prime number
                outputFile << "None\n";
            else{
                if(idx<1)
                    outputFile << "\n";
                else
                    outputFile << ", ";
            }
            if (idx > 0)
                reverseArray(factors, idx, outputFile);
        }
        inputFile.close();
        outputFile.close();
    }
    catch (string message)
    {
        cerr << message << endl;
        exit(1);
    }
}