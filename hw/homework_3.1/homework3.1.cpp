//Juniot Hernandez
//CISC 3142
//Homework 3.1
//Refernce
//https://en.cppreference.com/w/cpp/container
//https://cplusplus.com/reference/vector/vector/?kw=vector
//https://en.cppreference.com/w/cpp/chrono

#include <iostream>
#include <chrono>        //duration, system_clock
#include <random>        //shuffle
#include <set>           // ------------------
#include <list>          //|  Containers      |
#include <unordered_set> //|   Used           |
#include <vector>        // ------------------

using namespace std;
using namespace chrono_literals; // use for system_clock

template <class T> //T will be allow use of different kinds of containers.

/**
 * @brief - Will insert all the value of the inital vector to the empty container inserting  at the beginning instead of at the end.
 * 
 * @param initalVector - the starting vector created in main
 * @param emptyContainer - the empty container made in main, being inserted
 * @param InsertingFromEnd- indicate if insertion is from beginning or end
 * @param containerType - the name of the container
 */
void containerInsert(vector<int> initalVector, T &emptyContainer, bool InsertingFromEnd, string containerType)
{

    //the starting time of insertion process.
    auto startTime = chrono::system_clock::now();

    //starting at the begining of the intial vector,
    //while iterator not at the end of inital vector
    for (auto itValue = initalVector.begin(); itValue != initalVector.end(); ++itValue)
    {
        if (InsertingFromEnd)
        {
            //insert at the end of empty container the value itValue points to
            auto itr = emptyContainer.insert(emptyContainer.end(), *itValue);
        }
        else
        {
            //insert into the beginning of empty container the value itValue points to
            auto itr = emptyContainer.insert(emptyContainer.begin(), *itValue);
        }
    }

    //ending time of the insertion process.
    auto endTime = chrono::system_clock::now();

    //total amount of time to create
    chrono::duration<double> diff = endTime - startTime;
    cout << "Insertion time for " << containerType << " " << diff.count() << "s \n";
}

int main()
{

    // Create a empty vector
    vector<int> vect;

    int maxSize = 100000;
    //the time at the beginning of the creation of the vector
    auto startTime = chrono::system_clock::now();

    //fill vector up to 100000 int
    for (int i = 1; i <= maxSize; ++i)
        vect.push_back(i);

    //the time at the end of the list
    auto endTime = chrono::system_clock::now();

    //total amount of time to create
    chrono::duration<double> diff = endTime - startTime;

    cout << "Creation time inital Vector: " << diff.count() << "s \n";

    //shuffle the vector
    shuffle(vect.begin(), vect.end(), default_random_engine(time(NULL)));

    //insert contant of vect into the 4 empty containers

    cout << "\n\nInsertion from end\n";
    //new vector
    vector<int> vectorA;
    containerInsert(vect, vectorA, true, "vector");

    //set
    set<int> setA;
    containerInsert(vect, setA, true, "set");

    //list
    list<int> listA;
    containerInsert(vect, listA, true, "list");

    //unordered_set
    unordered_set<int> unordered_setA;
    containerInsert(vect, unordered_setA, true, "unordered_set");

    cout<< "\n\nInsertion from beginning\n";
    //inserting at the beginning

    //new vector
    vector<int> vectorB;
    containerInsert(vect, vectorB, false, "vector");

    //set
    set<int> setB;
    containerInsert(vect, setB, true, "set");

    //list
    list<int> listB;
    containerInsert(vect, listB, true, "list");

    //unordered_set
    unordered_set<int> unordered_setB;
    containerInsert(vect, unordered_setB, true, "unordered_set");
}