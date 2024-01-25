#include <iostream>
using namespace std;
#include "Product.cpp"
class Menu
{
    private:

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
        if(category==NULL)
        {
            // point head and tail
        }

    }
    void Display_menu()
    {
        Product *curr = this->Fast_food;
        cout << "FAST FOOD" << endl;
        while(curr!=NULL)
        {
            cout << curr->getProduct_ID() << "\t\t" << curr->getProduct_name() << "\t\t" << curr->getProduct_price() << endl;
        }
        cout << endl;
        curr = this->Desi_food;
        cout << "DESI FOOD" << endl;
        while(curr!=NULL)
        {
            cout << curr->getProduct_ID() << "\t\t" << curr->getProduct_name() << "\t\t" << curr->getProduct_price() << endl;
        }
        cout << endl;
        curr = this->Fast_food;
        cout << "DRINKS" << endl;
        while(curr!=NULL)
        {
            cout << curr->getProduct_ID() << "\t\t" << curr->getProduct_name() << "\t\t" << curr->getProduct_price() << endl;
        }
        cout << endl;
    }
};