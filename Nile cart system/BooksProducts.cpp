#include <iostream>
#include <string>
#include "BooksProducts.h"
#ifndef BOOKSPRODUCTS_CPP
#define BOOKSPRODUCTS_CPP
using namespace std;

BooksProducts :: BooksProducts(string title,double price,string author,string genre,int quantity_available)
{
  this-> title = title;
  this-> price = price;
  this-> author = author;
  this-> genre = genre;
  this->quantity_available = quantity_available;   
  this->original_price= price;
}
void BooksProducts ::set_title(string title)
{
    this-> title = title;    
}
void BooksProducts ::set_price(double price)
{
    this-> price = price;
}
void BooksProducts ::set_author(string author)
{
    this-> author = author;
}
void BooksProducts ::set_genre (string genre)
{
    this-> genre = genre;
}
void BooksProducts ::set_quantity(int quantity_available)
{
    this->quantity_available = quantity_available;
}
string BooksProducts ::get_name() const
{
    return this-> title; 
}
double BooksProducts ::get_price() const
{
    return this-> price;
}
string BooksProducts ::get_author() const
{
    return this-> author;
}
string BooksProducts ::get_genre() const
{
    return this-> genre;
}
int BooksProducts ::get_quantity() const
{
    return this-> quantity_available;
}
ostream&  operator <<(ostream &os,  BooksProducts &product)
{
    os << product.get_name() << "," 
       << product.get_price() << ","
       << product.get_quantity() <<","
       << product.get_author() <<","
       << product.get_genre() <<endl; 
    return os;
}
bool BooksProducts :: operator == (const BooksProducts &other) const
{
    return (this->title == other.get_name() 
     && this-> quantity_available==other.get_quantity() 
     && this->author==other.get_author()
     && this->genre==other.get_genre()); 
}
void BooksProducts ::set_orginal_price(double price)
{
    this->original_price=price;
}
double BooksProducts ::get_orginal_price() const
{
    return original_price;
}
#endif