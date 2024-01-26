#include <iostream>
#include <conio.h>
#include "productsList.h"

using namespace std;
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

        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << ".............. Add Products .............\n\n";
            cout << "\nSelect Category: ";
            cout << "\n1. Fast Food \n2. Desi Food \n3. Drinks \n";
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
            cout << "Product ID: ";
            cin >> id;
            cout << "Product Price: ";
            cin >> price;

            temp->addProduct(Product(id, name, price));

            cout << "\nItem Added Successfuly!\n";
            cout << "\nWant to add another product? (y/n) ";
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

    void deleteItem()
    {

        ProductsList *temp;
        char c;

        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "............ Delete Products ...........\n\n";
            cout << "\nSelect Category: ";
            cout << "\n1. Fast Food \n2. Desi Food \n3. Drinks \n";
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

            string id;
            cout << "\nProduct id: ";
            cin >> id;

            if (!temp->deleteProduct(id))
                cout << "\nItem Not Found!\n";
            else
                cout << "\nItem Deleted Successfuly!\n";

            cout << "\nWant to delete another product? (y/n) ";
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
    ProductsList *GetFast_Food()
    {
        return this->Fast_food;
    }

    ProductsList *GetDesi_Food()
    {
        return this->Desi_food;
    }

    ProductsList *GetDrinks()
    {
        return this->Drinks;
    }

    void pressToContinue()
    {
        cout << "\n\nPress to continue...\n\n";
        getch();
        char c;
        cin.get(c);
    }

    void Display_menu()
    {
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << ".................. Menu .................\n\n";
        Fast_food->print();
        Desi_food->print();
        Drinks->print();

        pressToContinue();
    }
};