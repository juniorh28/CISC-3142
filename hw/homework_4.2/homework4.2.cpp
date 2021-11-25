//Junior Hernandez
//CISC 3142
// Homework 4.2

#include <iostream>

using namespace std;

class ItemRecord {
    public:
        string title;
        double price;
        char rating;
        ItemRecord(string title="placeholder", double price = .99, char rating ='D'){
            this->title = title;
            this->price = price;
            this->rating = rating;
        };

        //overload the nool operator to compare the rating
        bool operator==(const ItemRecord& b){

        }
};

int main(){
    
    ItemRecord item;
    ItemRecord item2("Game of Thrones", 29.99, 'A');
    cout << "title is: " << item.title << " price: " << item.price << " rating: " << item.rating << endl;
    cout << "title is: " << item2.title << " price: " << item2.price << " rating: " << item2.rating << endl;
    return 0;
};