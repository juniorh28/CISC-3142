//Junior Hernandez
//CISC 3142
//Homework 1.2

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Prime
{

public:
    /**
     * checkPrime
     * params: int num
     * return: bool
     * method: checks if the number given is a prime number or not.
    */
    bool checkPrime(int& num)
    {
        if (num == 2 || num == 3)
            return true;

        if (num <= 1 || num % 2 == 0 || num % 3 == 0)
            return false;

        for (int i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }

        return true;
    }
    
    /**
     * factor
     * params: int num
     * return: void
     * method: prints all factor of a given number
    */
    void factor(int& num, ofstream& outputFile)
    {
        //idx is the starting idx
        int idx = 0;
        double a = round(num / 2);
        int factorArr[int(a)];
        for (int i = 2; i <= sqrt(num); i++)
        {

            if (num % i == 0)
            {
                if (sqrt(num) == i) //if the sqrt(num) and i are same number, increase idx by 1.
                {
                    factorArr[idx] = i;
                    idx += 1;
                }
                else
                {
                    //assign the two factors
                    factorArr[idx] = i;
                    factorArr[idx + 1] = num / i;
                    idx += 2;
                }
            }
        }

        //if the size of array is greater than 2
        //reorder in ascending order
        if (idx > 2)
        {
            int temp;
            for (int i = 1; i < idx; i++)
            {
                for (int j = 1; j < idx; j++)
                {
                    if (j + 1 < idx)
                    {
                        if (factorArr[j] > factorArr[j + 1])
                        {
                            temp = factorArr[j];
                            factorArr[j] = factorArr[j + 1];
                            factorArr[j + 1] = temp;
                        }
                    }
                }
            }
        }

        printArray(factorArr, idx, outputFile);
    }


    /**
     * printArray
     * params: int arr[]
     * params:int idx
     * return: void
     * method: prints all values inside of the given array
    */
    void printArray(int arr[], int& idx, ofstream& outputFile)
    {
        for (int i = 0; i < idx; i++)
        {
            if (i == idx - 1)
                outputFile << arr[i];
            else
                outputFile << arr[i] << ", ";
        }
    }
};

int main()
{
    try
    {
        Prime prime;
        int num = 0;
        string fileNum;
        ifstream inputFile("input.txt");
        if (!inputFile.good())
            throw string("Failure opening input.txt");

        ofstream outputFile("output.txt");
        if (!outputFile.good())
            throw string("Failure opening output.txt");
        while (getline(inputFile, fileNum))
        {
            //converts the string to int
            num = stoi(fileNum);
            outputFile << num << " : ";
            if (prime.checkPrime(num))
            {
                outputFile << "None" << endl;
            }
            else
            {
                prime.factor(num, outputFile);
                outputFile << "\n";
            }
        }
        inputFile.close();
        outputFile.close();
    }
    catch (string message)
    {
        cerr << message << endl;
        exit(1);
    }

    return 0;
}