#include <iostream>
#include <string>
#ifndef FOODPRODUCTS_H
#define FOODPRODUCTS_H
using namespace std;
class FoodProducts
{
private:
string name;
double pricePerKilo; 
string expiryDate; 
double Quantity; 
string type;
double original_price;
public:
FoodProducts(string name,double pricePerKilo,  string expiryDate, double Quantity, string type); //An argument constructor that intitializes the private members 
void set_name(string name);// A setter function for the name variable
void set_price(double pricePerKilo);// A setter function for the pricePerKilo variable
void set_expiryDate(string expiryDate);// A setter function for the expiryDate variable
void set_quantity (double Quantity);// A setter function for the Quantity variable
void set_type(string type);// A setter function for the type variable
string get_name() const; // A getter function for the name variable
double get_price() const;// A getter function for the pricePerKilo variable
string get_expiryDate() const; // A getter function for the expiryDate variable
double get_quantity() const; // // A getter function for the quantity variable
string get_type() const; //// A getter function for the type variable
friend ostream&  operator <<(ostream &os, const FoodProducts &product);//An overloaded operator that displays the private members
bool operator == (const FoodProducts &other) const;// An overloaded operator that checks whether two objects are equal via their private members
void set_orginal_price(double price);// A setter function for the original_price variable
double get_orginal_price() const; // A getter function for the original_price variable
};
#endif