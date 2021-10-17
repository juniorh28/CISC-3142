// y.xiang@bc lec4-1.cpp
// a Complex number example - simplified version, with fixed type of double

// output:
//c2 is now: (3.1,3.2)
//c3 is now: (-3.63,10.34)
//c4 is now: (1.1,2.2)

#include <iostream>

using namespace std;

class Complex
{
    double re, im; // representation: two doubles
public:
    // by default, all functions defined in-class are inlined, and those outside of class are not inlined
    // though for the latter you can use the keyword "inline" before return type to force it
    // only simple operations should be inlined for performance boost

    Complex(double r, double i) : re{r}, im{i} {} // construct Complex from two scalars
    Complex(double r) : re{r}, im{0} {}           // construct Complex from one scalar
    Complex() : re{0}, im{0} {}                   // default Complex: {0,0}, so �Complex c;� won�t trigger a compiler error

    Complex(const Complex &c) : re{c.re}, im{c.im} {} // copy constructor
    Complex &operator=(const Complex &c)
    {
        re = c.re;
        im = c.im;
        return *this;
    } // copy assignment

    // getters
    double real() const { return re; } // accessors/mutators, notice the const specifiers in accessors
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }

    // overloaded arithmetic operators
    // unary operator:
    Complex operator-(void)
    {
        re = -re;
        im = -im;
        return *this;
    }

    // binary operators:
    Complex &operator+=(Complex z)
    { // add to re and im and return the result
        re += z.re, im += z.im;
        return *this;
    }
    Complex &operator-=(Complex z)
    { // these are inlined
        re -= z.re, im -= z.im;
        return *this;
    }
    Complex &operator*=(Complex); // defined out-of-class
    Complex &operator/=(Complex); // defined out-of-class
};

// these member functions are not inlined
Complex &Complex::operator*=(Complex z)
{
    double temp = re * z.re - im * z.im;
    im = im * z.re + re * z.im;
    re = temp;
    return *this;
}

Complex &Complex::operator/=(Complex z)
{
    double temp = (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im);
    im = (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im);
    re = temp;
    return *this;
}

// Other overloaded operations do not require direct access to the representation of Complex,
// so they can be defined separately from the class definition. They can call member functions though
Complex operator+(Complex a, Complex b) { return a += b; } // calling the overloaded +=()
Complex operator-(Complex a, Complex b) { return a -= b; } // since a is passed by value
Complex operator*(Complex a, Complex b) { return a *= b; } // a can be modified
Complex operator/(Complex a, Complex b) { return a /= b; }

ostream &operator<<(ostream &os, const Complex &z)
{
    return os << "(" << z.real() << ", " << z.imag() << ")";
}

int main()
{
    Complex c1{1.1, 2.2};
    Complex c2 = c1;         // copy ctor
    c2 += Complex{2.0, 1.0}; // c2 is now (3.1, 3.2}
    Complex c3 = c2 * c1;    // c3 is now (-3.63, 10.34)
    Complex c4;              // default ctor, c4 is (0, 0)
    c4 = c3 / c2;            // copy assignment, c4 is now equal to c1 (1.1, 2.2)
    cout << "c2 is now: " << c2 << endl;
    cout << "c3 is now: " << c3 << endl;
    cout << "c4 is now: " << c4 << endl;
}
