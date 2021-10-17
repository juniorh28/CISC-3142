// y.xiang@bc lec4-2.cpp
// a concrete type example - container Vector

// output
//Element 3 is: 3, out of total: 5 items
//v2's size: 0

#include <iostream>
#include <initializer_list>
#include <algorithm> // for copy

using namespace std;

class Vector
{
private:
    double *elem; // elem points to an array of sz doubles
    int sz;

public:
    Vector(int s = 0) : elem{new double[s]}, sz{s}
    { // constructor: acquire resources
        for (int i = 0; i != s; ++i)
            elem[i] = 0; // initialize elements with zeros
    }
    Vector(std::initializer_list<double> lst) // enabling initialization with a list
        : elem{new double[lst.size()]}, sz{lst.size()}
    {
        copy(lst.begin(), lst.end(), elem); // copy from lst into elem
    }

    ~Vector() { delete[] elem; } // destructor: release resource

    double &operator[](int i) { return elem[i]; };

    void push_back(double); // implementation skipped, which need to manage a capacity

    int size() const { return sz; }
};

int main()
{
    Vector v1 = {1, 2, 3, 4, 5};
    cout << "Element 3 is: " << v1[2] << ", out of total: " << v1.size() << " items\n";
    Vector v2; // default ctor
    cout << "v2's size: " << v2.size() << endl;
}
