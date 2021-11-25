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
    cout << "Insertion time for " << containerType << " " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";
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
    cout << "Search time for " << containerName << str << " " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";
}

template <class K>
/**
 * @brief - a search for sets and unordered sets
 * 
 * @param container - the type of container that will be searched
 * @param containerName - the name of the container
 * @param fromEnd - if its searching container that was inserted from front or back
 */
void searchContainer2(K &container, string containerName, bool fromEnd)
{
    int search = 10000;
    auto startTime = chrono::system_clock::now();
    for (int i = 1; i <= search; ++i)
    {
        //look for value i from beginning to end
        std::unordered_set<int>::const_iterator got = container.find(i);
    }

    auto endTime = chrono::system_clock::now();
    cout << "Search time for " << containerName << " " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";
};

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
    cout << "Creation time inital Vector: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";

    int initalTotalTime = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    cout << "initalTotalTime " << initalTotalTime << endl;
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

    set<int>::iterator it;
    startTime = chrono::system_clock::now();
    for (int i = 0; i < setA.size(); ++i)
        it = setA.find(i);

    endTime = chrono::system_clock::now();
    cout << "Search time for setA " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";

    startTime = chrono::system_clock::now();
    for (int i = 0; i < setB.size(); ++i)
        it = setB.find(i);
        
    endTime = chrono::system_clock::now();
    cout << "Search time for setB " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " mirco sec \n";

    cout << "\n";

    //searching list
    searchContainer(listA, "List", true);
    searchContainer(listB, "List", false);

    cout << "\n";

    //searching unordered_set
    //https://www.cplusplus.com/reference/unordered_set/unordered_set/find/
    //starting with 1 up to 10k
    searchContainer2(unordered_setA, "unordered_setA", true);
    searchContainer2(unordered_setB, "unordered_setB", false);
}