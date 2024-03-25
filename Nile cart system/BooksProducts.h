#include <iostream>
#include <string>
#ifndef BOOKSPRODUCTS_H
#define BOOKSPRODUCTS_H
using namespace std;

class BooksProducts 
{
private:
string title;
double price; 
string author;
string genre;
int quantity_available; 
double original_price;
public:
BooksProducts(string title,double price,string author,string genre,int quantity_available); //An argument constructor that intitializes the private members 
void set_title(string title); // A setter function for the title variable
void set_price(double price); // A setter function for the price variable
void set_author(string author); // A setter function for the author variable
void set_genre (string genre); // A setter function for the genre variable
void set_quantity(int quantity_available); // A setter function for the quantity_available variable
string get_name() const; // A getter function for the name variable
double get_price() const; // A getter function for the price variable
string get_author() const; // A getter function for the author variable
string get_genre() const; // A getter function for the genre variable
int get_quantity() const; // A getter function for the quantity_available variable
friend ostream&  operator <<(ostream &os, const BooksProducts &product); // An overloaded operator that displays the class private members
bool operator == (const BooksProducts &other)const; // An overloaded operator that checks whether two objects are equal via their private members
void set_orginal_price(double price); // A setter function for the origninal_price variable
double get_orginal_price()const; // A getter function for the origninal_price variable
};
#endif