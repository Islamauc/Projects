#include<iostream>
#include <string>
#include "Order.cpp"
using namespace std;
class discounts_analysis
{
private:
    vector<Order> analysis;
public:
    discounts_analysis(){}
    void add_Order(Order& x)
    {
        analysis.push_back(x);
    }
    void display(){
    for (int i=0;i<analysis.size();i++)
    {
        analysis[i].display_dicounts();
    }
    }
};
int main()
{
    ElectronicsProduct x1("Iphone",100,4,7,"USA","Phone");
    ElectronicsProduct x2("Laptop",150,8,4,"USA","Mac");
    ElectronicsProduct x3("Iphone",100,4,7,"USA","Phone");
    BooksProducts y1("C++",4000,"John","Science",50);
    BooksProducts y2("python",3000,"Paul","Computer science",40);
    FoodProducts z1("Banana",400,"14/9/2023",45,"Fruit");
    FoodProducts z2("Carrot",150,"5/7/2023",32,"Vegetable");
    ProductManager<ElectronicsProduct> E;
    ProductManager<BooksProducts> B;
    ProductManager<FoodProducts> F;
    E + x1;
    E + x2;
    B + y1;
    B + y2;
    F + z1;
    F + z2;
    cout << E <<endl;
    cout << B <<endl;
    cout << F <<endl;
    E.sort_products("name");
    cout << E <<endl;
    E.sort_products("quantity");
    cout << E <<endl;
    E.sort_products("price");
    cout << E <<endl;

    B.sort_products("name");
    cout << B <<endl;
    B.sort_products("quantity");
    cout << B <<endl;
    B.sort_products("price");
    cout << B <<endl;
    
    F.sort_products("name");
    cout << F <<endl;
    F.sort_products("quantity");
    cout << F <<endl;
    F.sort_products("price");
    cout << F <<endl;

    cout << E.get_maximum_warranty() <<endl;
    cout << E.get_minumum_warranty() <<endl;
    cout << E.get_average_warranty() <<endl;
    
    E - x2;
    B - y2;
    F - z2;
    cout << E <<endl;
    cout << B <<endl;
    cout << F <<endl;

    ShoppingCart <ElectronicsProduct> Cart1(&E);
    ShoppingCart <FoodProducts> Cart2(&F);
    ShoppingCart <BooksProducts> Cart3(&B);
    Cart1.add_product(x1);
    Cart2.add_product(z1);
    Cart3.add_product(y1);

    Order first("845464713",&Cart1,&Cart2,&Cart3,0.0);
    first.compute_total_price();
    first.display_price();
    
    Discount d1(x1.get_name(),"percentage",99,"Not Applied");
    first.set_price(0);
    first.add_discount(d1);
    first.apply_discounts();
    first.compute_total_price();
    first.display_price();

    ProductManager<ElectronicsProduct> p1;
    ProductManager<BooksProducts> p2;
    ProductManager<FoodProducts> p3;
    p1+x2;
    p1+x1;
    p2+y2;
    p2+y1;
    p3+z2;
    p3+z1;
    p1+x3;
    cout << p1 <<endl;
    cout << p2 <<endl;
    cout << p3 <<endl;
    ShoppingCart <ElectronicsProduct> Cart4(&p1);
    ShoppingCart <FoodProducts> Cart5(&p3);
    ShoppingCart <BooksProducts> Cart6(&p2);
    Cart4.add_product(x2);
    Cart4.add_product(x1);
    Cart5.add_product(z1);
    Cart5.add_product(z2);
    Cart6.add_product(y2);
    Cart6.add_product(y1);
    Cart4.add_product(x3);
    cout << p1 <<endl;
    cout << p2 <<endl;
    cout << p3 <<endl;
    Order Second("54564564",&Cart4,&Cart5,&Cart6,0.0);
    vector<ElectronicsProduct>* E_vector=Cart4.get_cart();
    vector<FoodProducts>* F_vector=Cart5.get_cart();
    vector<BooksProducts>* B_vector=Cart6.get_cart();
    
    Discount d2(x2.get_name(),"Fixed amount",8,"Not Applied");
    Second.set_price(0);
    Second.add_discount(d2);
    Second.apply_discounts();
    Second.compute_total_price();
    Second.display_price();
    (*E_vector)[0].set_price(x2.get_price());

    Discount d3(x1.get_name(),"BOGO",0,"Not Applied");
    Second.set_price(0);
    Second.add_discount(d3);
    Second.apply_discounts();
    Second.compute_total_price();
    Second.display_price();

    (*E_vector)[0].set_price(x2.get_price());
    (*E_vector)[1].set_price(x1.get_price());
    (*E_vector)[2].set_price(x3.get_price());

    Discount d4("total_price_coupon","Coupons",0,"NileCart25");
    Second.set_price(0);
    Second.add_discount(d4);
    Second.apply_discounts();
    Second.compute_total_price();
    Second.display_price();

    discounts_analysis a;
    a.add_Order(first);
    a.add_Order(Second);
    a.display();
    return 0;    
}