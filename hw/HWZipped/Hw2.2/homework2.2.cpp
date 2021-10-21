//Juniot Hernandez
//CISC 3142
//Homework 2.2

#include <iostream>
#include <string>
#include "ordpair.hpp"

using namespace std;

enum Gender
{
    female,
    male
};

class TTPlayer
{
    char *name;
    Gender gen;

public:
    //allocate memory for TTPlayer to copy the arguements
    //this will be used by the regular constructor outside class
    TTPlayer(const char *s, Gender g);

    // copy constructor
    //inline inmplementation
    TTPlayer(const TTPlayer &ttp) : TTPlayer(ttp.name, ttp.gen){};

    //TTPlayer's enum will let us know which to look for for gen.
    string toString()
    {
        return string(name) + string(", ") + (gen ? "M" : "F");
    }

    //bool operator is going to compare TTPlayer's own gender with the rhs's gender
    //return true if its less than and false if not.
    bool operator<(const TTPlayer &rhs)
    {
        return this->gen < rhs.gen;
    }
    //if the gender are the same it will return true, else false.
    bool operator==(const TTPlayer &rhs)
    {
        return this->gen == rhs.gen;
    }

    //release resources
    ~TTPlayer() { delete[] name; };

    //strLength is needed to copy the name from char* s
    int strLen(const char *s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            ++i;
        }
        return i;
    };
};

//Not inline mean outside of class
//regular constructor (NOT inline)
//Since gen does not require any manipulation to gain access, we include it inline initalizer list
//since since name needs to be copied over from the pointer, we need a for loop and strLength function.
//defining not declaring outside a class
TTPlayer::TTPlayer(const char *s, Gender g) : gen(g)
{
    //copy name into ttp class
    int length = strLen(s);
    name = new char[length];
    for (int i = 0; i < length; ++i)
    {
        name[i] = s[i];
    }
    name[length] = '\0';
};

int main()
{

        TTPlayer players[] = {
            {"Player1", Gender::male},
            {"Player2", Gender::female},
            {"Player3", Gender::male},
            {"Player4", Gender::female},
            {"Player5", Gender::male}};

        int n = sizeof(players) / sizeof(TTPlayer);

        //loop through the array of TTPlayers, if they F<M print out the pair, 
        //if M<F or M==M or F==F, ordpair will throw and catch will continue to the next pair.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                try
                {
                    Ordpair<TTPlayer> pair(players[i], players[j]);
                    cout << "pair valid: " << pair.toString() <<endl;
                }
                catch (invalid_argument)
                {
                    continue;
                };
            }
        }
    
};