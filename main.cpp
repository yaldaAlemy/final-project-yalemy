#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Stock.h"
#include "Trader.h"

using namespace std;

// Display the menu
void displayMenu() {
    cout << "\nStock Market Simulation Menu:" << endl;
    cout << "1. View available stocks" << endl;
    cout << "2. Buy stock" << endl;
    cout << "3. Sell stock" << endl;
    cout << "4. View portfolio" << endl;
    cout << "5. Deposit money" << endl;
    cout << "6. Withdraw money" << endl;
    cout << "7. View account balance" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option (1-8): ";
}

// Randomly update stock prices 
void updateStockPrices(vector<Stock>& stocks) {
    for (size_t i = 0; i < stocks.size(); i++) {
        // Simulating price changes (sometimes down 7% or soemtimes up 7%
        double priceChange = (rand() % 15 - 7) / 100.0;
        double newPrice = stocks[i].get_Price() * (1 + priceChange);
        stocks[i].set_Price(newPrice);
    }
    cout << "Stock prices have been updated!" << endl;
}

int main() {
    cout << endl;

    srand(time(0)); // Seed for randomness

    // Initial stock options
    vector<Stock> availableStocks = {
        Stock("AAPL", 150.00, 100),
        Stock("GOOGL", 2800.00, 50),
        Stock("TSLA", 700.00, 200),
        Stock("AMZN", 3200.00, 30),
        Stock("MSFT", 290.00, 150),
        Stock("NFLX", 620.00, 80),
        Stock("META", 340.00, 60)
    };

    // Create trader object
    Trader trader;
    string traderName;
    cout << "Welcome to the Stock Market Simulator!" << endl;
    cout << "What’s your name? ";
    getline(cin, traderName);
    trader.set_Name(traderName);

    // Starting balance
    trader.set_Balance(10000.00);
    cout << "Hi, " << trader.fetch_Name() << "! You start with a balance of $10,000. Happy trading!" << endl;

    int choice = 0;
    while (choice != 8) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Display available stocks
                cout << "\nAvailable stocks:" << endl;
                for (size_t i = 0; i < availableStocks.size(); i++) {
                    cout << "Symbol: " << availableStocks[i].get_Symbol()
                         << ", Price: $" << availableStocks[i].get_Price()
                         << ", Quantity available: " << availableStocks[i].get_Quantity() << endl;
                }
                break;
            }
            case 2: {
                string symbol;
                int quantity;
                cout << "Enter the stock symbol you want to buy: ";
                cin >> symbol;
                cout << "Enter the quantity: ";
                cin >> quantity;

                bool stockFound = false;
                for (size_t i = 0; i < availableStocks.size(); i++) {
                    if (availableStocks[i].get_Symbol() == symbol) {
                        stockFound = true;
                        double totalPrice = availableStocks[i].get_Price() * quantity;

                        if (totalPrice > trader.fetch_Balance()) {
                            cout << "Insufficient funds. Try buying fewer shares!" << endl;
                        } else {
                            trader.add_Stock(availableStocks[i], quantity);
                            trader.set_Balance(trader.fetch_Balance() - totalPrice);
                            cout << "Bought " << quantity << " shares of " << symbol << " for $" << totalPrice << "." << endl;
                        }
                        break;
                    }
                }

                if (!stockFound) {
                    cout << "Invalid stock symbol. Please try again." << endl;
                }
                break;
            }
            case 3: {
                string symbol;
                int quantity;
                cout << "Enter the stock symbol you want to sell: ";
                cin >> symbol;
                cout << "Enter the quantity: ";
                cin >> quantity;

                if (!trader.remove_Stock(symbol, quantity)) {
                    cout << "Not enough shares to sell. Check your portfolio!" << endl;
                } else {
                    for (size_t i = 0; i < availableStocks.size(); i++) {
                        if (availableStocks[i].get_Symbol() == symbol) {
                            double totalSalePrice = availableStocks[i].get_Price() * quantity;
                            trader.set_Balance(trader.fetch_Balance() + totalSalePrice);
                            cout << "Sold " << quantity << " shares of " << symbol << " for $" << totalSalePrice << "." << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                // Display portfolio
                cout << "Here’s your portfolio:" << endl;
                trader.show_Portfolio();
                break;
            }
            case 5: {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;

                if (amount > 0) {
                    trader.deposit_money(amount);
                    cout << "Deposited $" << amount << ". Your new balance is $" << trader.fetch_Balance() << "." << endl;
                } else {
                    cout << "Deposit amount must be positive." << endl;
                }
                break;
            }
            case 6: {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Withdrawal amount must be positive." << endl;
                } else if (amount > trader.fetch_Balance()) {
                    cout << "Insufficient balance to withdraw." << endl;
                } else {
                    trader.withdraw_money(amount);
                    cout << "Withdrew $" << amount << ". Your new balance is $" << trader.fetch_Balance() << "." << endl;
                }
                break;
            }
            case 7: {
                // Display account balance
                cout << "Your account balance is: $" << trader.fetch_Balance() << endl;
                break;
            }
            case 8: {
                cout << "Thanks for using the Stock Market Simulator. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid option. Please choose again!" << endl;
        }

        // Update stock prices after each interaction
        updateStockPrices(availableStocks);
    }

    return 0;
}

