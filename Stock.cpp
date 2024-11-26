#include "Stock.h"

//constructor that will be edited later
Stock::Stock() {}


//Getter method

double Stock::get_Price() const {

    return 0.0;  //returning a placeholder for right now
}

//Getter method 

int Stock::get_Quantity() const {

    return 0; //returning a 0 for right now
}

//Getter method to retrieve the symbol
std::string Stock::get_Symbol() const {

    return "blank";   //placeholder
}

//setter methods which has void return type 

void Stock::set_Price(double p) {
     price = p;
}

//for setting the quantity 

void Stock::set_Quantity(int q) {
    quantity = q;
}

