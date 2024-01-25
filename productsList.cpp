#include <iostream>
#include "product.cpp"
using namespace std;

class ProductsList
{
private:
    string category;
    Product product;

public:
    ProductsList()
    {
        category = "";
    }
    ProductsList(string category)
    {
        this->category = category;
    }
    string getCategory()
    {
        return category;
    }
};