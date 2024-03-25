#include <iostream>
#include <string>
#include "Order.h"
#include "ShoppingCart.cpp"
using namespace std;

Order :: Order(string ID, ShoppingCart<ElectronicsProduct>* Eproducts,
        ShoppingCart<FoodProducts>* Fproducts,
        ShoppingCart<BooksProducts>* Bproducts,
        double total_price)
        {
            this-> ID =ID; 
            this-> Eproducts=Eproducts;
            this-> Fproducts=Fproducts;
            this-> Bproducts=Bproducts;
            this-> total_price=total_price;
        }
void Order::add_discount(const Discount &discount)
{
    discounts.push_back(discount);
}

void Order::set_price(double price)
{
    this->total_price=price;
}
double Order::get_price() const
{
    return total_price;
}
void Order::apply_discounts()
{
    int m=0;
    vector<ElectronicsProduct>* E_vector=Eproducts->get_cart();
    //vector<ElectronicsProduct> E_vector= * temp_vector;
    for(int i=0;i<Eproducts->get_cart()->size();i++)
    {
        for(int j=0;j<discounts.size();j++)
        {
        if((*E_vector)[i].get_name()==discounts[j].get_product_name())
        {
          if (discounts[j].get_type()=="BOGO" )//&& m<1)
            {
                for(int x=0;x<Eproducts->get_cart()->size()-1;x++)
                {   
                    
                    for(int y=x+1;y<Eproducts->get_cart()->size();y++)
                {   //if(m<1)
                //{
                    if((*E_vector)[x]== (*E_vector)[y])
                    {
                        m++;
                        (*E_vector)[i]-discounts[j];         
                    }
                //}
                }
                }
            }
            else
            (*E_vector)[i]-discounts[j];
        }
        }
    }
     vector<BooksProducts>* B_vector=Bproducts->get_cart();
    //vector<ElectronicsProduct> E_vector= * temp_vector;
    for(int i=0;i<Bproducts->get_cart()->size();i++)
    {
        for(int j=0;j<discounts.size();j++)
        {
        if((*B_vector)[i].get_name()==discounts[j].get_product_name())
        {
        if (discounts[j].get_type()=="BOGO")
            {
                for(int x=0;x<Bproducts->get_cart()->size()-1;x++)
                {
                    for(int y=x+1;y<Bproducts->get_cart()->size();y++)
                {
                    if((*B_vector)[x]== (*B_vector)[y])
                    {
                    (*B_vector)[i]-discounts[j];         
                    }                
                }
                }
            }
           else
           (*B_vector)[i]-discounts[j];
        }
        }
    }
    vector<FoodProducts>* F_vector=Fproducts->get_cart();
    //vector<ElectronicsProduct> E_vector= * temp_vector;
    for(int i=0;i<Fproducts->get_cart()->size();i++)
    {
        for(int j=0;j<discounts.size();j++)
        {
        if((*F_vector)[i].get_name()==discounts[j].get_product_name())
        {
            if (discounts[j].get_type()=="BOGO")
            {
                for(int x=0;x<Fproducts->get_cart()->size()-1;x++)
                {
                    for(int y=x+1;y<Fproducts->get_cart()->size();y++)
                {
                    if((*F_vector)[x]== (*F_vector)[y])
                    (*F_vector)[i]-discounts[j];         
                }
                }
            }
            else 
            (*F_vector)[i]-discounts[j];
        }
        }
    }
    for(int i=0;i<discounts.size();i++)
    {
        if(discounts[i].get_product_name() == "total_price_coupon")
        {
            this->total_price= *this-discounts[i];
        }
    }
}
double Order::compute_total_price()
{
    double e_price(0),f_price(0),b_price(0);
    vector<ElectronicsProduct>* E_vector=Eproducts->get_cart();
    for(int i=0;i<Eproducts->get_cart()->size();i++)
    {
        e_price+= (*E_vector)[i].get_price();
    }

    vector<BooksProducts>* B_vector=Bproducts->get_cart();
    for(int i=0;i<Bproducts->get_cart()->size();i++)
    {
        b_price+= (*B_vector)[i].get_price();
    }
    vector<FoodProducts>* F_vector=Fproducts->get_cart();
    for(int i=0;i<Fproducts->get_cart()->size();i++)
    {
        f_price+= (*F_vector)[i].get_price();
    }
    this-> total_price += e_price + b_price + f_price;  
    double temp_price=total_price;
    for(int i=0;i<discounts.size();i++)
    {
        if(discounts[i].get_product_name() == "total_price_coupon")
        {
            *this-discounts[i];
            discounts[i].set_deducted_price(temp_price-total_price);
        }
    }
       return total_price;
}

void Order::display_price() const
{
    cout << "The order ID is:" << ID <<" , "
         << "The total price is: " << total_price << " , "
         << "The prices are: " <<endl; 
         /*vector<ElectronicsProduct>* E_vector=Eproducts->get_cart();
         vector<BooksProducts>* B_vector=Bproducts->get_cart();
         vector<FoodProducts>* F_vector=Fproducts->get_cart();
         for(int i=0;i<Eproducts->get_cart()->size();i++)
         {
            cout << (*E_vector)[i].get_name() << " : " << (*E_vector)[i].get_price() <<endl;
            cout << (*B_vector)[i].get_name() << " : " << (*B_vector)[i].get_price() <<endl;
            cout << (*F_vector)[i].get_name() << " : " << (*F_vector)[i].get_price() <<endl;         
         }
         cout <<endl;    */   // I did not include it in the screenshots, as the device could 
                              // not handle displaying them   
                              // It worked at first, but at after displaying the other requirements 
                              // the machine could not handle it. 
}
void Order::display_dicounts() const
{
    double total_discount=0;
    for(int i=0;i<discounts.size();i++)
    {
        cout << discounts[i].get_product_name() << "'s discounted price is: " << discounts[i].get_deducted_price() <<endl;
        total_discount += discounts[i].get_deducted_price();
    }
    cout << "The total money lost is:  " << total_discount <<endl;
}