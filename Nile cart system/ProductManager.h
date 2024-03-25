#include <iostream>
#include <string> 
#include <vector>
#include "ElectronicsProduct.cpp"
#include "BooksProducts.cpp"
#include "FoodProducts.cpp"
using namespace std;
#ifndef PRODUCTMAMAGER_H 
#define PRODUCTMAMAGER_H

template <typename T>
class ProductManager 
{
private:
vector<T> products;
int quantity;
public:
ProductManager() {quantity=0;} //quantity is intitialized to zero
void operator + ( const T &other); // Overloading the operator + to add a product 
void operator - ( const T &other); // Overloading the operator - to remove a product 
template <typename U>
friend ostream&  operator << (ostream &os,  ProductManager<U> &product);// Overloading the operator << to display the object
vector<T> sort_products (string sort_by); // function that sorts the products according to the name, price or quantity
int get_maximum_warranty(); //A getter for the maximum_warranty variable
int get_minumum_warranty(); //A getter for the minumum_warranty variable
double  get_average_warranty(); //A getter for the average_warranty variable
bool product_exists(const T& product); // function that check if the product exists in the ProductManager object(used in ShoppinCart class) 
void set_quantity (int quantity);//A setter for the quantity variable
int get_quantity(); //A getter for the quantity variable
};
#endif
//#ifndef 
//#define
//#endif 
//#include "ProductManager.cpp"

