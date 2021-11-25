2.2 A toy template class (5-pt)
This exercise attempts to tie together the abstraction mechanisms covered in lec4.

OrdPair

You are asked to define a template class called OrdPair, which stands for an ordered pair of some parameterized type, T. Your definition should form an ordpair.hpp header file which can be included in your main cpp file (#include "ordpair.hpp"). The key feature of OrdPair is that the pair is strictly ordered, with its two data members, named first and second, always satisfying the invariant: first < second. You should define a constructor that enforces the invariant, i.e. if the constructor is passed arguments that violate it, a std::invalid_argument should be thrown. Besides the constructor, you should also define the following member functions:

    std::string toString() // which produces the string representation of the pair in the form of: "(first | second)"
    bool operator==() // returns true when both parts of the pair are equal
    getters/setters for data members. Make sure that setFirst() and setSecond() also enforce the invariant mentioned above

Note: OrdPair assumes the parameterized type T also implements toString(), operator==(), as well as operator<(), which you will do for the type  argument, TTPlayer, as described below:

TTPlayer

To test OrdPair, in your main cpp file, define a concrete type called TTPlayer, which stands for Table Tennis Player. Suppose we are trying to list possible mixed double pairings for a tournament from a pool of female/male players.

For simplicity, TTPlayer only has two data members:

    char* name; // must be of type char* so it needs memory allocation in constructor, and you must implement destructor as well
    Gender gen; // Gender is an enum class, which only has two values: female, male - in this given order

And you only need to define the bare minimum interface as follows (all are inline, i.e. inside the class definition, except for the regular constructor):

    TTPlayer(const char* s, Gender g) // regular constructor (NOT inline)
    TTPlayer(const TTPlayer& ttp) // copy constructor
    std::string toString() // produces "name, F" or "name, M"
    bool operator<(const TTPlayer& rhs) // only returns true if the current object's gender appears before the right-hand-side object's gender (basically, true when female < male)
    destructor
    Note: normally a copy assignment should always be included together with the copy constructor and destructor (the rule of three). But for this project you can get away without it, the same way getters/setters are left out - that's why the above is the bare minimum. However, if you are to use "=" assignment for TTPlayer in your code (the setters in OrdPair actually use it but they are never called), you must implement the copy assignment in the form of: TTPlayer& operator=(const TTPlayer& rhs)
    int strLen(const char* s); // returns the length of s. This is a free-standing function used by TTPlayer to allocate memory for its data member, char* name)

Your main()

To tie up everything together, in your main() create an array of TTPlayer named players:

TTPlayer players[] = {
    {"Player1", Gender::male},
    {"Player2", Gender::female},
    {"Player3", Gender::male},
    {"Player4", Gender::female},
    {"Player5", Gender::male}
};

The trick to get the size of the array is: int n = sizeof(players) / sizeof(TTPlayer);

Now, take advantage of OrdPair's facilities, with its invariant enforcement via exceptions, use try-catch blocks to instantiate all possible pairings. When a pairing is valid, print it out on screen using OrdPair's toString(). An example output is shown below:
Example output
Pair valid: (Player2, F | Player1, M)
Pair valid: (Player4, F | Player1, M)
Pair valid: (Player2, F | Player3, M)
Pair valid: (Player2, F | Player5, M)
Pair valid: (Player4, F | Player3, M)
Pair valid: (Player4, F | Player5, M)

