#include <iostream>
using namespace std;
#include "Product.cpp"
class Menu
{
    public:
    Product *Fast_food;
    Product* Desi_food;
    Product* Drinks;
    Product* getFast_food_menu()
    {
        return this->Fast_food;
    }
    Product* getDesi_food_menu()
    {
        return this->Desi_food;
    }
    Product* getDrinks_menu()
    {
        return this->Drinks;
    }
    void AddItem(Product new_item,Product* category)
    {
        //coming item with category in which we are going to add

    }
    void Display_menu()
    {
        Product *curr = this->Fast_food;
        cout << "FAST FOOD" << endl;
        while(curr!=NULL)
        {
            cout << curr->product_ID << "\t\t" << curr->product_name << "\t\t" << curr->product_price << endl;
        }
        cout << endl;
        Product *curr = this->Desi_food;
        cout << "DESI FOOD" << endl;
        while(curr!=NULL)
        {
            cout << curr->product_ID << "\t\t" << curr->product_name << "\t\t" << curr->product_price << endl;
        }
        cout << endl;
        Product *curr = this->Fast_food;
        cout << "DRINKS" << endl;
        while(curr!=NULL)
        {
            cout << curr->product_ID << "\t\t" << curr->product_name << "\t\t" << curr->product_price<<endl;
        }
        cout << endl;
    }
};