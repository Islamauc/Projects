#include <iostream>
#include <string>
#include <vector>
#include "ElectronicsProduct.cpp"
#include "BooksProducts.cpp"
#include "FoodProducts.cpp"
#include "ShoppingCart.cpp"
#include "Discount.cpp"
using namespace std;

class Order
{
private:
string ID;
ShoppingCart<ElectronicsProduct>* Eproducts;
ShoppingCart<FoodProducts>* Fproducts;
ShoppingCart<BooksProducts>* Bproducts;
double total_price;
vector<Discount> discounts;
public:
Order(string ID, ShoppingCart<ElectronicsProduct>* Eproducts,
        ShoppingCart<FoodProducts>* Fproducts,
        ShoppingCart<BooksProducts>* Bproducts,
        double total_price); //Initializing the vector variables
void add_discount(const Discount &discount); //Adding a discount object
double get_price() const; // A getter for the total_price variable
void set_price(double price); // A setter for the total_price variable
void apply_discounts(); // A function that applies the discounts on the elligible products
double compute_total_price(); // A function that calculates the total_price 
void display_price() const; //A function that displays the price
void display_dicounts() const; //A function that displays the discounts
};