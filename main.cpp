#include <iostream>
#include "Stock.h"
#include "Trader.h"
using namespace std;

int main() {
    cout << endl;
    cout << "Welcome to the Stock Market Simulation!!!" << endl;
    cout << "You can buy and sell stocks, view your portfolio, and manage your funds." << endl;

    // Create a Stock object
    Stock stock;
    stock.set_Price(100.0);
    stock.set_Quantity(100);
    stock.set_Symbol("AAL");
     
    Stock stock2;

    stock2.set_Price(300.0);
    stock2.set_Quantity(90);
    stock2.set_Symbol("TSLA");


    // Create a Trader object
    Trader trader;

    bool running = true;
    while(running) {
        // Display the menu
        cout << "\nMenu:" << endl;
        cout << "1. View Available Stocks" << endl;
        cout << "2. View Portfolio" << endl;
        cout << "3. Exit" << endl;

        int c;
        cout << "Please select an option (1-3): ";
        cin >> c;
        if (c == 1) {
          // View Available Stocks
          cout << "\nAvailable Stocks:" << endl;
          cout << stock.get_Symbol() << " - $" << stock.get_Price() << " per share" << endl;
          cout << stock2.get_Symbol() << " - $" << stock2.get_Price() << " per share" << endl;
         }
        else if (c == 2) {
        // View Portfolio
        trader.show_Portfolio();
        }
       else if (c == 3) {
       // Exit
       cout << "Exiting the program. Thank you for using the Stock Market Simulation!" << endl;
       running = false;
       }
       else {
       cout << "Invalid choice. Please try again." << endl;
       }
       }

    // Print a message

    return 0;
}
