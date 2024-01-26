#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;
class Product
{
private:
    string product_ID;
    string product_name;
    int product_price;

public:
    Product()
    {
        this->product_ID = "";
        this->product_name = "";
        this->product_price = 0;
    }
    Product(string ID, string name, int price)
    {
        this->product_ID = ID;
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

    string getProduct_ID() const
    {
        return product_ID;
    }

    string getProduct_name() const
    {
        return product_name;
    }
};

#endif // PRODUCT_H
