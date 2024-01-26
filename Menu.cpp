#include <iostream>
#include <conio.h>
#include "categories.h"
#include <string>
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
        cout << "category Name: ";
        cin.ignore();
        getline(cin, category);
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
        if (categoriesList->getSize() == 0)
        {
            cout << "\nCategory List is empty\n";
            pressToContinue();
            return;
        }
        cout << "\nSelect Category to delete: \n";
        Node<ProductsList *> *curr = categoriesList->getHead();

        for (int i = 1; i <= categoriesList->getSize(); i++)
        {
            cout << i << ". " << curr->getData()->getCategory() << endl;
            curr = curr->getNextPtr();
        }

        int c;
        cin >> c;
        if (c > categoriesList->getSize() || c < 1)
        {
            cout << "\nInvalid Input Entered\n";
            pressToContinue();
            return;
        }
        categoriesList->deleteCategory(c);
        cout << "\nCategory Deleted Successfuly!\n";
        pressToContinue();
    }

    Categories *get_CategoriesList()
    {
        return categoriesList;
    }

    void AddItem()
    {
        string name;
        double price;
        char c;
        ProductsList *temp;

        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << ".............. Add Products .............\n\n";
            if (categoriesList->getSize() == 0)
            {
                cout << "\nCategory List is Empty! \nPlease Add Category First.\n";
                pressToContinue();
                return;
            }
            cout << "\nSelect Category: \n";
            Node<ProductsList *> *curr = categoriesList->getHead();

            for (int i = 1; i <= categoriesList->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }
            int ind;
            cin >> ind;

            if (ind > categoriesList->getSize() || ind < 1)
            {
                cout << "\nInvalid Input Entered\n";
                pressToContinue();
                return;
            }

            temp = categoriesList->get_Category(ind);
            cin.ignore();
            cout << "\nProduct Name: ";
            getline(cin, name);

            cout << "Product Price: ";
            cin >> price;
            int sr = temp->getSize() + 1;
            temp->addProduct(Product(sr, name, price));

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
            if (categoriesList->getSize() == 0)
            {
                cout << "\nList is empty\n";
                pressToContinue();
                return;
            }
            cout << "\nSelect Category: \n";
            Node<ProductsList *> *curr = categoriesList->getHead();

            for (int i = 1; i <= categoriesList->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }
            int ind;
            cin >> ind;
            temp = categoriesList->get_Category(ind);
            if (temp->getSize() == 0)
            {
                cout << "\nList is empty\n";
                pressToContinue();
                return;
            }
            cout << "\nSelect Item to delete: ";
            temp->print();

            cin >> ind;

            if (!temp->deleteProduct(ind))
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
    }

    void Display_menu()
    {
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << ".................. Menu .................\n\n";
        if (categoriesList->getSize() == 0)
        {
            cout << "\nMenu is empty\n";
            return;
        }

        categoriesList->Print();
    }
};