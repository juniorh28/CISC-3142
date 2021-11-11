//Junior Hernandez
//CISC 3142
//Homework 3.2

#include <iostream>
#include <map>
#include <algorithm> //find_if
#include <vector>
#include <set>
#include <fstream>
#include <ios>     //used to get stream size
#include <limits>  //used to get numeric limits
#include <sstream> //converts string to number
#include <cstddef>

using namespace std;

// //functor to get the areaCode of phone number
struct AreaCode
{
    int areaCode;                               //the area code we are searching for
    AreaCode(int t) : areaCode(t) {}            // take in a struct with a unknown area  code
    bool operator()(const pair<int, string> &p) //compare if the string(area code) is the same as the area code
    {
        int number;
        string str = p.second.substr(1, 3);
        cout << "Str: " << str <<endl;
        istringstream(str) >> number;
        return number == areaCode;
    }
};

int main()
{

    //creates a map of key int and value string
    map<int, string> map;
    //input file to read in keys and phone numbers
    ifstream myfile;
    myfile.open("phoneno.txt", ifstream::in);
    int key;
    string phoneNumber;
    string str;

    int count = 0; //counter for people with area code 347

    //struct PhoneNumber phoneNum;
    //map<int, string>::iterator it = map.begin();
    while (myfile.good())
    {

        //read the line upto the comma
        getline(myfile, str, ',');
        // converts string -> integer
        istringstream(str) >> key;

        //get the remaining line
        getline(myfile, phoneNumber);

        //map.insert
        map.insert(pair<int, string>(key, phoneNumber));
    }
    cout << "Size of map: " << map.size() << endl;

    vector<string> vect1;
    set<string> set1;

    cout << "\nThe ID(s) with the given phone# 212-536-6331: " << endl;
    for (auto it = map.begin(); it != map.end(); ++it)
    {

        if (it->second.substr(1, 3) == "347")
            ++count;

        //This is the right way but result for cout is total amp size, for now im using substr till I find out how to fix
        // auto p = find_if(map.begin(), map.end(), AreaCode(347))
        // if(p != map.end())
        //     ++count;



        if (it->second == " 212-536-6331")
            cout << it->first << endl;

        if (it->second.substr(1, 3) == "212")
            vect1.insert(vect1.end(), it->second);
    }

    cout << "\nphone number with 347 is: " << count << endl;

    cout << "\n";
    for (int i = 0; i < vect1.size(); ++i)
    {
        set1.insert(vect1[i]);
    }

    vector<string> vect2(set1.begin(), set1.end());

    cout << "non-unique vector1 size: " << vect1.size() << endl;
    cout << "unique vector2 size: " << vect2.size() << endl;

    myfile.close();
    return 0;
}