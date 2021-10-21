//Junior Hernandez
//CISC 3142
//Homework 2.2 .hpp

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Ordpair
{

private:
    T first;
    T second;

public:
    Ordpair(T f, T s) : first{f}, second{s}{ 
        //since first and second will be defined in TTPlayer with the enum values, we will be able to tell if f<s and throw on true;
        if (this->second < this->first || this->first == this->second)
        {
            throw invalid_argument("Error");
        }
    };

    void setFirst(T first)
    {
        if (first == 1)
            this->first = first;
        else
            throw invalid_argument("Error");
    };
    void setSecond(T second)
    {
        if (second == 0)
            this->second = second;
        else
            throw invalid_argument("Error");
    };
    T getFirst() { return first; };
    T getSecond() { return second; };

    //using type T, take in 'a' ordpair's data member
    //if the 'a' ordpair data member is the same as this ordpair's data member, return true;
    const T &operator==(Ordpair<T> a) const
    {
        if (this->first == a.first && this->second == a.second)
            return true;
    };


    //this will return Orpdair's string along side the first and second toString
    string toString() {return string("(") + first.toString() + string(" | ") + second.toString() + string(")"); };
};