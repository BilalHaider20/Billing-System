#include <iostream>
using namespace std;
#include "Product.cpp"
#include "productsList.cpp"

class Menu
{
private:
    ProductsList *Fast_food = new ProductsList("Fast Food");
    ProductsList *Desi_food = new ProductsList("Desi Food");
    ProductsList *Drinks = new ProductsList("Drinks");

public:
    void AddItem()
    {
        string name;
        string id;
        double price;
        char c;

        ProductsList *temp;

        cout << "Add Products.\n";
        while (true)
        {
            cout << "Select Category: ";
            cout << "1. Fast Food \n2. Desi Food \n3. Drinks \n";
            cin >> c;
            switch (c)
            {
            case '1':
                temp = Fast_food;
                break;
            case '2':
                temp = Desi_food;
                break;
            case '3':
                temp = Drinks;
                break;

            default:
                break;
            }

            cout << "\nProduct Name: ";
            cin >> name;
            cout << "\nProduct ID: ";
            cin >> id;
            cout << "\nProduct Price: ";
            cin >> price;

            temp->addProduct(Product(id, name, price));

            cout << "\nItem Added Successfuly!\n";

            cout << "Want to add another product? (y/n) ";
            cin >> c;
            switch (c)
            {
            case 'y':
            case 'Y':
                break;
            case 'n':
            case 'N':
                return;
            default:
                break;
            }
        }
    }

    void Display_menu()
    {
        Fast_food->print();
        Desi_food->print();
        Drinks->print();
    }
};