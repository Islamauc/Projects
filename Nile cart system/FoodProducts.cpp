#include <iostream>
#include <string> 
#include "FoodProducts.h"
#ifndef FOODPRODUCTS_CPP
#define FOODPRODUCTS_CPP
using namespace std;


FoodProducts :: FoodProducts(string name,double pricePerKilo,  string expiryDate, double Quantity, string type)
{
    this->name=name;
    this->pricePerKilo=pricePerKilo; 
    this->expiryDate=expiryDate; 
    this->Quantity=Quantity; 
    this->type=type;
    this->original_price=pricePerKilo;
    }
void FoodProducts ::set_name(string name)
{
    this->name=name;
}
void FoodProducts ::set_price(double pricePerKilo)
{
    this->pricePerKilo=pricePerKilo;
}
void FoodProducts ::set_expiryDate(string expiryDate)
{
this->expiryDate=expiryDate;
}
void FoodProducts :: set_quantity (double Quantity)
{
    this->Quantity=Quantity;
}
void FoodProducts :: set_type(string type)
{
    this->type=type;
}
string FoodProducts :: get_name() const
{
    return name;
}
double FoodProducts ::get_price() const
{
    return pricePerKilo;
}
string FoodProducts ::get_expiryDate() const
{
    return expiryDate;
}
double FoodProducts ::get_quantity() const
{
    return Quantity;
}
string FoodProducts ::get_type() const
{
    return type;
}
ostream&  operator <<(ostream &os, const FoodProducts &product)
{
    os << product.get_name() << "," 
       << product.get_price() << ","
       << product.get_quantity() <<","
       << product.get_expiryDate() <<","
       << product.get_type() <<endl; 
    return os;
}

bool FoodProducts :: operator == (const FoodProducts &other) const
{
    return (this->name == other.get_name() 
     && this-> Quantity==other.get_quantity() 
     && this->expiryDate==other.get_expiryDate()
     && this->type==other.get_type()); 
}
void FoodProducts ::set_orginal_price(double price)
{
    this->original_price=price;
}
double FoodProducts ::get_orginal_price() const
{
    return original_price;
}
#endif