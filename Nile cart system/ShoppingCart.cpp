#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"
#ifndef SHOPPINGCART_CPP 
#define SHOPPINGCART_CPP
using namespace std;

template<typename T>
ShoppingCart<T> :: ShoppingCart(ProductManager<T>* product)
{
this->products=product;
}
template<typename T>
void ShoppingCart<T> ::add_product(const T& product)
{
    if (products->product_exists(product))
    {
        cart.push_back(product);
        *products-product;
    }
    else 
    cout << "Not Found" <<endl;
}
template<typename T>
void ShoppingCart<T> ::remove_product( const T& other)
{   int x=0;
    vector<T> temp_cart;
while (!cart.empty())
    {
        if (cart[cart.size()-1] == other && x<1) {
                cart.pop_back();
                x++;
            
            }
            else {
            temp_cart.push_back(cart[cart.size()-1]);
            cart.pop_back();
            }
        }
        while (!temp_cart.empty())
        {
            cart.push_back(temp_cart[temp_cart.size()-1]);
            temp_cart.pop_back();
        }
    
//products.erase(remove(products.begin(), products.end(), product));


}
template <typename T>
vector<T>* ShoppingCart<T> :: get_cart() const
{
    
    return &cart;
}
#endif