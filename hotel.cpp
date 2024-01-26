#include <iostream>
#include <stack>
#include <string>
#include <conio.h>

#include "Menu.cpp"
#include "order.h"
#include "productsList.h"

using namespace std;

class Hotel
{
private:
    string name;
    stack<Order> orderStack;
    int invoiceNumber = 10000000;
    Menu menu;

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

    void BillingHistory()
    {
        stack<Order> tempStack = orderStack;

        if (tempStack.empty())
        {
            cout << "No billing history available." << endl;
            pressToContinue();
            return;
        }

        while (!tempStack.empty())
        {
            Order currentOrder = tempStack.top();
            currentOrder.print();
            tempStack.pop();
        }
        pressToContinue();
    }

    void TakeOrder()
    {
        if (menu.get_CategoriesList()->getSize() == 0)
        {
            system("cls");
            cout << "Menu is Empty!\nPlease add Categories and items in the menu." << endl;
            pressToContinue();
            return;
        }

        ProductsList *cart = new ProductsList();
        ProductsList *temp = NULL;

        cout << "\nCustomer Name: ";
        cin.ignore();
        string name;
        getline(cin, name);

        while (true)
        {
            system("cls");
            menu.Display_menu();

            cout << "-----------------------------------------\n\n";

            cout << "Hi " << name << "! What do you want to order? \n(Enter \"x\" when done) " << endl;

            cout << "\nSelect Category: \n";

            Node<ProductsList *> *curr = menu.get_CategoriesList()->getHead();

            for (int i = 1; i <= menu.get_CategoriesList()->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }

            char c;
            cin >> c;

            if (c == 'x')
                break;

            if (c - 48 > menu.get_CategoriesList()->getSize() || c - 48 < 1)
            {
                cout << "\nInvalid Input\n";
                pressToContinue();
                continue;
            }

            temp = menu.get_CategoriesList()->get_Category(c - 48);

            while (true)
            {
                system("CLS");
                temp->print();
                cout << "--------------------------------------------" << endl;
                cout << "Enter the serial number to add to Cart (Enter \"x\" when done): ";
                char input;
                cin >> input;
                if (input == 'x')
                    break;
                if (input - 48 > temp->getSize() || input - 48 < 1)
                {
                    cout << "Invalid input!\nPlease enter a correct serial number" << endl;
                    pressToContinue();
                    continue;
                }

                Product p = temp->getProduct(input - 48);
                cart->addProduct(p);
                cout << "\nAdded to Cart Successfully\n";
                pressToContinue();
            }
        }

        double bill = GenerateBill(cart);
        Order newOrder(name, invoiceNumber++, bill, cart);
        orderStack.push(newOrder);
        newOrder.print();
        pressToContinue();

        delete cart;
        return;
    }

    void Compute_Total_Sales()
    {
        double totalSales = 0;
        int totalProducts = 0;

        stack<Order> tempStack = orderStack;
        while (!tempStack.empty())
        {
            Order obj = tempStack.top();
            totalSales += obj.getBill();
            totalProducts += obj.GetPurchasedItems()->getSize();
            tempStack.pop();
        }

        cout << "Total Sales: Rs." << totalSales << endl;
        cout << "Total Number of Products Sold: " << totalProducts << endl;
    }

    void MenuManager()
    {
        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "............ Menu Management ...........\n\n";

            cout << "1. See Menu \n2. Add Category \n3. Delete Category \n4. Add New Items in Menu \n5. Delete Items from Menu \n6. Go Back" << endl;
            cout << "\nEnter the corresponding number: ";
            char input;
            cin >> input;

            switch (input)
            {
            case '1':
                menu.Display_menu();
                pressToContinue();
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
            cout << "\nEnter the corresponding number: ";

            char input;
            cin >> input;

            switch (input)
            {
            case '1':
                MenuManager();
                break;
            case '2':
                TakeOrder();
                break;
            case '3':
                BillingHistory();
                pressToContinue();
                break;
            case '4':
                Compute_Total_Sales();
                pressToContinue();
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
        cout << "\n\nPress any key to continue...\n\n";
        getch();
    }
};
