#include <iostream>
#include <string>
#include "Discount.h"
using namespace std;

Discount :: Discount (string product_name,string type, double percentage_or_fixedamount, string CouponCode)
{
    this-> product_name = product_name;
    this->type =type;
    this->CouponCode=CouponCode;
    this->percentage_or_fixedamount=percentage_or_fixedamount;
}
template<class T>
double operator - ( T& product,  Discount& discount)
{
    if (discount.get_type()=="Percentage" || discount.get_type()=="percentage")
    {
    discount.set_deducted_price(product.get_price()*(discount.get_percentage_or_fixedamount()/100));
    product.set_price(product.get_price()*((100-discount.get_percentage_or_fixedamount())/100));
    return product.get_price()*(100-discount.get_percentage_or_fixedamount()/100);
    }
    else if(discount.get_type()=="Fixed amount" || discount.get_type()=="fixed amount")
    {
    discount.set_deducted_price(discount.get_percentage_or_fixedamount());
    product.set_price(product.get_price()-discount.get_percentage_or_fixedamount());
    return product.get_price()-discount.get_percentage_or_fixedamount();
    }
    else if (discount.get_type() =="BOGO")
    {discount.set_deducted_price(product.get_price());
    product.set_price(product.get_price()*0.5);
    return product.get_price()*0.5;
    }
    else if (discount.get_type()=="Coupons" && discount.get_CouponCode()=="NileCart25"
            || discount.get_type() == "coupons"&& discount.get_CouponCode()=="NileCart25") 
            {
    product.set_price(product.get_price()*0.75);
    return product.get_price()*0.75;
            }
    else
    return product.get_price();
}
string Discount::get_type() const
{
    return type;
}
string Discount::get_CouponCode() const
{
    return CouponCode;
}
double Discount::get_percentage_or_fixedamount() const
{
    return percentage_or_fixedamount;
}
void Discount::set_type(string type)
{
    this->type =type;
}
void Discount::set_CouponCode(string CouponCode)
{
    this->CouponCode =CouponCode;
}
void Discount::set_percentage_or_fixedamount(double percentage_or_fixedamount)
{
    this->percentage_or_fixedamount=percentage_or_fixedamount;
}
void Discount::set_product_name(string product_name)
{
this->product_name=product_name;
}
string Discount::get_product_name() const
{
    return product_name;
}
void Discount::set_deducted_price(double price)
{
    this->deducted_price=price;
}
double Discount::get_deducted_price() const
{
    return deducted_price;
}
