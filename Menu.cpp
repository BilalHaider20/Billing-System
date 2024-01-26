#include <iostream>
#include <conio.h>
#include "categories.h"

using namespace std;
class Menu
{
private:
    Categories *categoriesList = new Categories();

public:
    void add_Category()
    {
        string category;
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << ".............. Add Category .............\n\n";
        cin >> category;
        categoriesList->addCategory(category);
        cout << "\nCategory added successfully\n";
        pressToContinue();
        return;
    }

    void delete_Category()
    {
        string category;
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << "............. Delete Category ............\n\n";
        cout << "\nSelect Category to delete: ";
        Node<ProductsList *> *curr = categoriesList->getHead();

        for (int i = 1; i <= categoriesList->getSize(); i++)
        {
            cout << i << ". " << curr->getData()->getCategory() << endl;
            curr = curr->getNextPtr();
        }
        int c;
        cin >> c;
    }

    Categories *get_CategoriesList()
    {
        return categoriesList;
    }

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
            Node<ProductsList *> *curr = categoriesList->getHead();

            for (int i = 1; i <= categoriesList->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }
            int ind;
            cin >> ind;
            temp = categoriesList->get_Category(ind);

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
            Node<ProductsList *> *curr = categoriesList->getHead();

            for (int i = 1; i <= categoriesList->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }
            int ind;
            cin >> ind;
            temp = categoriesList->get_Category(ind);

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
        categoriesList->Print();

        pressToContinue();
    }
};