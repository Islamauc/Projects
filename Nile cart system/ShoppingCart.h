#include <iostream>
#include <string>
#include <vector>
#include "ProductManager.cpp"
#ifndef SHOPPINGCART_h 
#define SHOPPINGCART_h


using namespace std;

template<typename T>
class ShoppingCart
{
private:
vector<T> cart;
ProductManager<T>* products;
public:
ShoppingCart(ProductManager<T>* product); //intializing the vector of the pointers of the ProductManger objects 
void add_product(const T& product); // function that adds a product to the  cart
void remove_product( const T& product); // function that removes a product from the cart 
vector<T>* get_cart()const; // A getter that returns a pointer to the vector cart 
};
#endif 