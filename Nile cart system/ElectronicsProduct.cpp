#include <iostream>
#include <string>
#include "ElectronicsProduct.h"
using namespace std;
#ifndef ELECTRONICSPRODUCT_CPP 
#define ELECTRONICSPRODUCT_CPP
ElectronicsProduct :: ElectronicsProduct(string name,double price,int no_devices,int warranty,string factory,string type)
{
this->name= name;
price_per_device=price;
number_devices_available=no_devices;
this->warranty=warranty;
this->factory=factory;
this->type=type;
this->original_price=price;
}
void ElectronicsProduct ::set_name(string name)
{
    this->name= name;
}
void ElectronicsProduct ::set_price(int price)
{
    price_per_device=price;
}
void ElectronicsProduct ::set_quantity(int no_devices)
{
    number_devices_available=no_devices;
}
void ElectronicsProduct ::set_warranty(int warranty)
{
    this->warranty=warranty;
    
}
void ElectronicsProduct ::set_factory (string factory)
{
    this->factory=factory;
    
}
void ElectronicsProduct ::set_type(string type)
{
    this->type=type;
}
string ElectronicsProduct ::get_name() const
{
    return name;
}
double ElectronicsProduct :: get_price() const
{
    return price_per_device;
}
int ElectronicsProduct :: get_quantity() const
{
    return number_devices_available;
}
int ElectronicsProduct ::get_warranty() const
{
    return warranty;
}
string ElectronicsProduct ::get_factory() const
{
    return factory;
}
string ElectronicsProduct ::get_type() const
{
    return type;
}
ostream&  operator <<(ostream &os, ElectronicsProduct &product)
{   
    os << product.get_name() << "," 
       << product.get_price() << ","
       << product.get_quantity() <<","
       << product.get_warranty() <<","
       << product.get_factory() <<","
       << product.get_type() <<endl; 
    return os;
}

bool ElectronicsProduct :: operator == (const ElectronicsProduct &other) const
{
    return (this->name == other.get_name() 
     && this-> number_devices_available==other.get_quantity() 
     && this->warranty==other.get_warranty()
     && this->factory==other.get_factory()
     && this->type==other.get_type()); 
}
void ElectronicsProduct ::set_orginal_price(double price)
{
    this->original_price=price;
}
double ElectronicsProduct ::get_orginal_price() const
{
    return original_price;
}
#endif