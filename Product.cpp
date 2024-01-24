#include <iostream>
using namespace std;
class Product
{
public:
    int product_ID;
    string product_name;
    int product_price;
    Product(int ID, string name, int price)
    {
        this->product_ID = ID;
        this->product_name = name;
        this->product_price = price;
    }
    void change_product_price(int price)
    {
        this->product_price = price;
    }
};