#include <iostream>
#include <string> 
using namespace std;
#ifndef ELECTRONICSPRODUCT_H 
#define ELECTRONICSPRODUCT_H

class ElectronicsProduct 
{
private:
string name;
double price_per_device;
int number_devices_available;
int warranty;
string factory;
string type;
double original_price;
public:
ElectronicsProduct(string name,double price,int no_devices, int warranty,string factory,string type); //An argument constructor that intitializes the private members 
void set_name(string name);// A setter function for the name variable
void set_price(int price);// A setter function for the price_per_device variable
void set_quantity(int no_devices); // A setter function for the number_devices_available variable
void set_warranty(int warranty); // A setter function for the warranty variable
void set_factory (string factory); // A setter function for the factory variable
void set_type(string type); // A setter function for the type variable
string get_name() const; // A getter function for the name variable
double get_price() const; // A getter function for the price_per_device  variable
int get_quantity() const; // A getter function for the number_devices_available variable
int get_warranty() const; // A getter function for the warranty variable
string get_factory() const; // A getter function for the factory variable
string get_type() const;// A getter function for the type variable
bool operator == ( const ElectronicsProduct &other)const;// An overloaded operator that checks if two electronics products are equal 
friend ostream&  operator <<(ostream &os, const ElectronicsProduct &product);// An overloaded operator that displays the private member of the object
void set_orginal_price(double price);// A setter function for the original_price variable
double get_orginal_price()const; // A getter function for the original_price variable
};
#endif 