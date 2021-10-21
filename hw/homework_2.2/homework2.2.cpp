//Juniot Hernandez
//CISC 3142
//Homework 2.2

#include <iostream>
#include "ordpair.hpp"

using namespace std;

enum Gender{female, male};

class TTPlayer{
    char* name;
    Gender gen;

public:

    //allocate memory for TTPlayer to copy the arguements
    //this will be used by the regular constructor outside class
    TTPlayer(const char *s, Gender g);

    // copy constructor
    //inline inmplementation
    TTPlayer(const TTPlayer &ttp) : TTPlayer(ttp.name, ttp.gen){};

    //TTPlayer's enum will let us know which to look for for gen.
    std::string toString()
    {
        return name + std::string(", ") + (gen ? "M" : "F");
    }

    //bool operator is going to compare TTPlayer's own gender with the rhs's gender
    //return true if its less than and false if not.
    bool operator<(const TTPlayer& rhs){
        return this->gen < rhs.gen;
    }

    //release resources
    ~TTPlayer(){delete[] name;};

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
TTPlayer::TTPlayer(const char *s, Gender g): gen(g){
    //copy name into ttp class
    int length = strLen(s);
    name = new char [length + 1];
    for(int i =0; i < length; ++i){
        name[i] = s[i]; 
    }
};

int main(){
    try{

        TTPlayer players[] = {
            {"Player1", Gender::male},
            {"Player2", Gender::female},
            {"Player3", Gender::male},
            {"Player4", Gender::female},
            {"Player5", Gender::male}};

        int n = sizeof(players) / sizeof(TTPlayer);

        
        for(int i=0; i < n; ++i){
             for(int j=i+1; j < n; ++j){
                Ordpair<TTPlayer> pair(players[i], players[j]);
                pair.toString();

            }
        }
         

    }
    catch(std::invalid_argument const &ex)
    {
        cout << "not valid pair" << endl;
    }
};