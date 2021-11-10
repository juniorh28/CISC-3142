//Juniot Hernandez
//CISC 3142
//Homework 3.1
//Refernce
//https://en.cppreference.com/w/cpp/container
//https://cplusplus.com/reference/vector/vector/?kw=vector
//https://en.cppreference.com/w/cpp/chrono

#include <iostream>
#include <algorithm>     // std::find
#include <chrono>        //duration, system_clock
#include <random>        //shuffle
#include <set>           // __________________
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

template <class P> //T will be allow use of different kinds of containers.

/**
 * @brief - Will search the container for the numbers 1 ~ 10000. Then it will print the total time to complete search.
 * 
 * @param container - the randomly filled container being searched
 * @param containerName - the name of the container
 * @param fromEnd - checking if the container was filled from the end
 */
void searchContainer(P &container, string containerName, bool fromEnd)
{
    string str;
    if (fromEnd)
        str = "A";
    else
        str = "B";
    int search = 10000;
    auto startTime = chrono::system_clock::now();

    //starting with 1 up to 10k
    for (int i = 1; i <= search; ++i)
    {
        //look for value i from beginning to end
        auto it = find(container.begin(), container.end(), i);
    }
    auto endTime = chrono::system_clock::now();
    chrono::duration<double> diff = endTime - startTime;
    cout << "Search time for " << containerName << str << " " << diff.count() << "s \n";
}

template <class K>
/**
 * @brief - a search for sets and unordered sets
 * 
 * @param container - the type of container that will be searched
 * @param containerName - the name of the container
 * @param fromEnd - if its searching container that was inserted from front or back
 * @param unordered - if its an unordered set or set
 */
void searchContainer2(K &container, string containerName, bool fromEnd, bool unordered)
{
    int search = 10000;
    auto startTime = chrono::system_clock::now();
    //if its unordered set, use its find method
    if (unordered)
    {
        for (int i = 1; i <= search; ++i)
        {
            //look for value i from beginning to end
            std::unordered_set<int>::const_iterator got = container.find(i);
        }
    }
    //else use the set's find method
    else
    {
        for (int i = 1; i <= search; ++i)
        {
            //look for value i from beginning to end
            //std::set<int>::const_iterator it;
            //it = container.find(i);
        }
    }
    auto endTime = chrono::system_clock::now();
    chrono::duration<double> difference = endTime - startTime;
    cout << "Search time for " << containerName << " " << difference.count() << "s\n";
}

//bool operator < (const vector) const{}
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

    cout << "\nInsertion from end\n";
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

    cout << "\n\nInsertion from beginning\n";
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

    cout << "\n\n";

    //searching the container for int 1~10k
    //searching vector
    searchContainer(vectorA, "Vector", true);
    searchContainer(vectorB, "Vector", false);

    cout << "\n";

    searchContainer(setA, "Set", true);
    searchContainer(setB, "Set", false);

    cout << "\n";
    //searching set

    // startTime = chrono::system_clock::now();
    // for (int i = 1; i <= 10000; ++i){
    //     auto search = setA.find(i);
    // }
    // endTime = chrono::system_clock::now();
    // chrono::duration<double> difference = endTime - startTime;
    // cout << "Search time for SetA " << difference.count() << "s\n ";
    // searchContainer2(setA, "setA", true, false);
    //searchContainer2(setB, "setB", false , false);

/*
    std::set<int>::iterator it;
    startTime = chrono::system_clock::now();
    for (it = setA.begin(); it != setA.end(); ++it)
    {
        cout << setA.find(it) << endl;
    }
    endTime = chrono::system_clock::now();
    chrono::duration<double> difference = endTime - startTime;
    cout << "Search time for setA " << difference.count() << " s\n ";
*/

    //searching list
    searchContainer(listA, "List", true);
    searchContainer(listB, "List", false);

    cout << "\n";

    //searching unordered_set
    //https://www.cplusplus.com/reference/unordered_set/unordered_set/find/
    //starting with 1 up to 10k
    searchContainer2(unordered_setA, "unordered_setA", true, true);
    searchContainer2(unordered_setB, "unordered_setB", false, true);
}