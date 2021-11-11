//Junior Hernandez
//CISC 3142
//Homework 3.2

#include <iostream>
#include <map>
#include <algorithm> //find_if
#include <vector>
#include <fstream>
#include <ios>     //used to get stream size
#include <limits>  //used to get numeric limits
#include <sstream> //converts string to number

using namespace std;

// //functor to get the areaCode of phone number
struct AreaCode
{
    string areaCode;                            //the area code we are searching for
    AreaCode(string t) : areaCode(t) {}         // take in a struct with a unknown area  code
    bool operator()(const pair<int, string> &p) //compare if the string(area code) is the same as the area code
    {
        string str = p.second;
        cout << "inside struct where str is: " << str.substr(0, 4) << endl;
        string str2 = str;
        return str2 == areaCode;
    }
};

//functor that takes in a phone number
// struct PhoneNumber
// {
//     int key;
//     string phoneNum;
// };

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
       // cin.ignore(' ');
        // string -> integer
        std::istringstream(str) >> key;
       // cin.ignore(' '); //skip the empty space
        cout << key << endl;
        //get the remaining line
        getline(myfile, phoneNumber);
        cout << phoneNumber << endl;
        //map.insert
        map.insert(pair<int, string>(key, phoneNumber));
    }
    cout << "Size of map: " << map.size() << endl;

    auto p = find_if(map.begin(), map.end(), AreaCode{"212"});
    if (p != map.end())
        ++count;
    cout << count;

    for (auto it = map.begin(); it != map.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

    myfile.close();
    return 0;
}