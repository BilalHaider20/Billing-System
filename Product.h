#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;
class Product
{
private:
    int sr = 0;
    string product_name;
    int product_price;

public:
    Product()
    {
        this->product_name = "";
        this->product_price = 0;
    }
    Product(string name, int price)
    {
        sr++;
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

    int getSr() const
    {
        return sr;
    }

    string getProduct_name() const
    {
        return product_name;
    }
};

#endif // PRODUCT_H
