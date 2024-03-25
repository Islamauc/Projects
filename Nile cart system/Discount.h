#include <iostream>
#include <string>
using namespace std;

class Discount
{
private:
string product_name;
string type;
string CouponCode;
double percentage_or_fixedamount;
double deducted_price;
public:
Discount (string product_name,string type, double percentage_or_fixedamount, string CouponCode ); // argument constructor 
string get_type()const; //A getter for the type variable
string get_CouponCode()const; //A getter for the CouponCode variable 
double get_percentage_or_fixedamount()const; //A getter for the percentage_or_fixedamount variable 
string get_product_name() const; //A getter for the product_name variable
void set_type(string type); //A setter for the type variable
void set_CouponCode(string CouponCode);//A setter for the CouponCode variable
void set_percentage_or_fixedamount(double percentage_or_fixedamount); //A setter for the percentage_or_fixedamount variable
void set_product_name(string product_name); //A setter for the product_name variable
template<class T>
friend double operator - ( T & product,  Discount& discount); // Overloading the operator - to apply the discount to the products
void set_deducted_price(double price);// A setter for the deducted_price variable
double get_deducted_price()const;// A getter for the deducted_price variable
};