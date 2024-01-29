#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;
class Product
{
private:
    string product_name;
    int product_price;

public:
    Product()
    {
        this->product_name = "";
        this->product_price = 0;
    }
    Product(int sr, string name, int price)
    {
        this->product_name = name;
        this->product_price = price;
    }
    void change_product_price(int price)
    {
        this->product_price = price;
    }

    int getProduct_price() const
    {
        return product_price;
    }

    string getProduct_name() const
    {
        return product_name;
    }
};

#endif // PRODUCT_H
