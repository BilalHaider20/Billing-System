#include <iostream>
#include <conio.h>
#include "categories.h"
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

class Menu
{
private:
    string MENU = "menu_data";
    Categories *categoriesList = new Categories;

public:
    void saveData()
    {
        ofstream outputFile(MENU);

        if (!outputFile.is_open())
        {
            cerr << "\nError opening file!" << endl;
            return;
        }

        for (int i = 1; i <= categoriesList->getSize(); i++)
        {
            ProductsList *temp = categoriesList->get_Category(i);
            for (int j = 1; j <= temp->getSize(); j++)
            {
                string categ = temp->getCategory();
                string name = temp->getProduct(j).getProduct_name();
                for (int m = 0; m < categ.size(); m++)
                {
                    if (categ[m] == ' ')
                        categ[m] = '_';
                }
                for (int n = 0; n < name.size(); n++)
                {
                    if (name[n] == ' ')
                        name[n] = '_';
                }
                outputFile << categ << " " << name << " " << temp->getProduct(j).getProduct_price() << " " << endl;
            }
        }
        outputFile.close();
    }

    void loadData()
    {
        string categName;
        string prodName;
        double prodPrice;
        ifstream inputFile(MENU);
        categoriesList->emptyMenu();

        if (!inputFile.is_open())
        {
            cerr << "\nError opening file for reading." << endl;
            return;
        }

        while (inputFile >> categName >> prodName >> prodPrice)
        {
            for (char &c : categName)
            {
                if (c == '_')
                    c = ' ';
                c = toupper(c);
            }
            for (char &c : prodName)
            {
                if (c == '_')
                    c = ' ';
            }

            if (!categoriesList->categoryExists(categName))
            {
                categoriesList->addCategory(categName);
            }

            ProductsList *temp = categoriesList->get_Category(categName);

            temp->addProduct(prodName, prodPrice);
        }

        inputFile.close();
        inputFile.clear();
    }

    void add_Category()
    {
        string category;
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << ".............. Add Category .............\n\n";
        cout << "category Name: ";
        cin.ignore();
        getline(cin, category);
        for (char &c : category)
        {
            c = toupper(c);
        }
        categoriesList->addCategory(category);
        cout << "\nCategory " << category << " Added Successfully\n";
        pressToContinue();
        saveData();
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
        cout << "\nCategory " << categoriesList->get_Category(c)->getCategory() << " Deleted Successfuly!\n";
        categoriesList->deleteCategory(c);
        saveData();
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
            temp->addProduct(name, price);

            cout << "\n"
                 << name << " Added Successfuly!\n";
            saveData();
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
            if (ind > categoriesList->getSize() || ind < 1)
            {
                cout << "\nInvalid Input Entered\n";
                pressToContinue();
                return;
            }
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

            if (ind > temp->getSize())
            {
                cout << "\nInvalid Input Entered!\n";
                pressToContinue();
                return;
            }
            else
            {
                cout << "\n"
                     << temp->getProduct(ind).getProduct_name() << " Deleted Successfuly!\n";
                temp->deleteProduct(ind);
                saveData();
            }
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