#include <iostream>
using namespace std;
#include "Menu.cpp"
#include <stack>
#include <string>
#include "order.h"
class Hotel
{
private:
    string name;
    stack<Order> stack;
    int invoiceN = 10000000;
    Menu menu;
    Categories *categoriesList = menu.get_CategoriesList();

public:
    Hotel()
    {
        name = "-";
    }
    Hotel(string name)
    {
        this->name = name;
    }

    int GenerateBill(ProductsList *cart)
    {
        Node<Product> *temp = cart->getHead();

        double bill = 0;

        while (temp != nullptr)
        {
            bill += temp->getData().getProduct_price();

            temp = temp->getNextPtr();
        }

        return bill;
    }

    void Billing_History()
    {
        while (!stack.empty())
        {
            Order obj = stack.top();
            cout << "Costumer Name : " << obj.getCustomerName() << endl;
            cout << "Invoice Number : " << obj.getInvoiceNumber() << endl;
            cout << "Items Purchased  \n";
            ProductsList *products = obj.GetPurchasedItems();
            products->print();
            cout << "----------------------------------------------" << endl;
            cout << "Total Bill\t\t" << obj.getBill();
        }
    }

    void Take_order()
    {
        if (menu.get_CategoriesList()->getSize() == 0)
        {
            cout << "Menu is Empty. Please add Categories and items in menu " << endl;
            pressToContinue();
            return;
        }
        ProductsList *cart;
        ProductsList *temp;
        menu.Display_menu();
        cout << "------------------------------" << endl;
        while (true)
        {
            cout << "What do you want to order ? " << endl;
            cout << "\nSelect Category: ";
            Node<ProductsList *> *curr = categoriesList->getHead();

            for (int i = 1; i <= categoriesList->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }
            int c;
            cin >> c;
            temp = categoriesList->get_Category(c);
        }

        temp->print();
        cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
        // product selection code will be here

        cout << "\nCostumer Name ";
        string name;
        getline(cin, name);

        // cart->addProduct(product to be added in cart);
        double bill = GenerateBill(cart);

        Order new_order(name, invoiceN++, bill, cart);
        stack.push(new_order);
    }

    void menuManager()
    {
        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "............ Menu Management ...........\n\n";

            cout << "1. See Menu \n2. Add Category \n3. Delete Category \n4. Add New Items in Menu \n5. Delete Items from Menu \n6. Go Back" << endl;
            cout << "\nEnter the corresponding number ";
            char input;
            cin >> input;

            switch (input)
            {
            case '1':
                menu.Display_menu();
                break;
            case '2':
                menu.add_Category();
                break;
            case '3':
                menu.delete_Category();
                break;
            case '4':
                menu.AddItem();
                break;
            case '5':
                menu.deleteItem();
                break;
            case '6':
                return;
            default:
                break;
            }
        }
    }

    void MainMenu()
    {
        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "........................................\n\n";

            cout << "1. Manage Menu \n2. Take Orders \n3. Billing History \n4. Total Sales \n5. Exit" << endl;
            cout << "\nEnter the corresponding number ";

            char input;

            cin >> input;
            switch (input)
            {
            case '1':
                menuManager();
                break;
            case '2':
                Take_order();
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
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
};