#include <iostream>
#include <string> 
#include <vector>
#include "ProductManager.h"
#ifndef PRODUCTMANAGER_CPP 
#define PRODUCTMANAGER_CPP
using namespace std;
template <typename t>
void swap (const t &x, const t &y)
{
    t temp;
    temp = x;
    x = y;
    y = temp;
}

template <typename T>
vector <T> ProductManager <T> :: sort_products (string sort_by)
{int min_index;
    if (sort_by == "Name" || sort_by == "name" )
    { 
        for (int i=0;i<products.size()-1;i++)
        {
            min_index =i;
            for (int j=i+1;j<products.size();j++)
            {
                if(products[j].get_name() < products[min_index].get_name())
                {
                    min_index=j;
                }
            }
            swap(products[min_index],products[i]);
        }
        return products;
    }
    else if (sort_by == "Quantity" || sort_by == "quantity")
    {
        for (int i=0;i<products.size()-1;i++)
        {
            min_index =i;
            for (int j=i+1;j<products.size();j++)
            {
                if(products[j].get_quantity() < products[min_index].get_quantity())
                {
                    min_index=j;
                }
            }
            swap(products[min_index],products[i]);
        }
        return products;
    }    
    else if (sort_by == "Price" || sort_by == "price")
    {
      for (int i=0;i<products.size()-1;i++)
        {
            min_index =i;
            for (int j=i+1;j<products.size();j++)
            {
                if(products[j].get_price() < products[min_index].get_price())
                {
                    min_index=j;
                }
            }
            swap(products[min_index],products[i]);
        }
        return products;
    }
    return products;
}
template <typename T>
void ProductManager <T> :: operator + ( const T &other)
{
    products.push_back(other);
    quantity++;

}
template <typename T>
void ProductManager <T> :: operator - (const T &other)
{
    int x=0;
    vector<T> temp_product;
while (!products.empty())
    {  
        if (products[products.size()-1] == other && x<1 ) {
                products.pop_back();
                x++;
            }
            else {
            temp_product.push_back(products[products.size()-1]);
            products.pop_back();
            }
        }
        while (!temp_product.empty())
        {
            products.push_back(temp_product[temp_product.size()-1]);
            temp_product.pop_back();
        }
     quantity--;      

    
}
template <typename U>
ostream& operator << (ostream& os,  ProductManager<U>& product)
{
    for (size_t i = 0; i < product.products.size(); i++) {
       os <<  product.products[i];
        if (i < product.products.size()) {
                os << ", ";
            }
        }
        os << "The quantity of the products is: " << product.get_quantity() <<endl;
        
        return os;
}
template<>
int ProductManager <ElectronicsProduct>::get_maximum_warranty()
{
int max_warranty=0;
    for (int i=0;i<products.size();++i)
    {
    if (products[i].get_warranty() > max_warranty)
    max_warranty = products[i].get_warranty();
    }
    return max_warranty;
}
template<>
int ProductManager <ElectronicsProduct>::get_minumum_warranty()
{
int min_warranty=products[0].get_warranty();
    for (int i=0;i<products.size();i++)
    {
    if (products[i].get_warranty() < min_warranty)
    min_warranty = products[i].get_warranty();
    }
    return min_warranty;
}
template<>
double ProductManager <ElectronicsProduct>::get_average_warranty()
{
double sum =0,avg_warranty;
    for (int i=0;i<products.size();i++)
    {
        sum += products[i].get_warranty();
    }
    avg_warranty = (sum/products.size());
    return avg_warranty;
}
template <typename T>
bool ProductManager<T> :: product_exists(const T& product)
{
    for(int i=0;i<products.size();i++)
    {
    if(products[i]==product)
        return true;
    }
    return false;
    }

template<typename T>
void ProductManager<T>::set_quantity (int quantity)
{
    this->quantity = quantity; 
}
template<typename T>
int ProductManager<T>::get_quantity ()
{
    return quantity; 
}
#endif


// It was a failed attempt to overload the operator -
/*
        }*///products.erase(remove(products.begin(), products.end(), other));
//quantity--;