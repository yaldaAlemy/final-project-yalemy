#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {

//attributes for Stock {


private:
//stock symbol variable
std:: string symbol;

double price;  //variable for current stock price
int quantity;  //variable int for Quantity available

public:
//constructor for right now
Stock();
Stock(const std::string& symbol, double price, int quantity);
//two setter methods called set_Pricedouble p), and setQuantity(n)


void set_Price(double p);
void set_Quantity(int n_);
void set_Symbol(const std::string& symbol);  


//three getter methods get_Symbol, get_Price, and get_Quantity() const {
std::string get_Symbol() const;
double get_Price() const;
int get_Quantity() const;


};

#endif
