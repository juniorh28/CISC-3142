//Junior Hernandez
//CISC 3142
//Homework 2.2 .hpp

#include <iostream>

using namespace std;

template <typename T>
class Ordpair{

private:
    T first;
    T second;

public:
    Ordpair(T first, T second);
    
    //since first and second will be defined in TTPlayer with the enum values, we will be able to tell if f<s and throw on true;
    if(first < second){
        throw std::invalid_argument;
    }
    void setFirst(T first){this->first = first;};
    void setSecond(T second){this->second = second;};
    T getFirst(){return first;};
    T getSecond(){return second;};
    
    //using type T, take in 'a' ordpair's data member
    //if the 'a' ordpair data member is the same as this ordpair's data member, return true;
    const T &operator==(Ordpair<T> a) const{ 
        if(this->first == a.first && this->second == a.second)
            return true; 
    };
    
    string toString() { return "(" + this->first + " | " + this->second + ")" + endl; };

    ~Ordpair() { delete[] first, second;};
}