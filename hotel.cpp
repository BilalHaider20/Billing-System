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
        while (!orderStack.empty())
        {
            Order obj = orderStack.top();
            cout << "Customer Name: " << obj.getCustomerName() << endl;
            cout << "Invoice Number: " << obj.getInvoiceNumber() << endl;
            cout << "Items Purchased:\n";
            ProductsList *products = obj.GetPurchasedItems();
            products->print();
            cout << "----------------------------------------------" << endl;
            cout << "Total Bill\t\t" << obj.getBill() << endl;
            orderStack.pop();
        }
    }

    void TakeOrder()
    {
        if (menu.get_CategoriesList()->getSize() == 0)
        {
            cout << "Menu is Empty!\nPlease add Categories and items in the menu." << endl;
            pressToContinue();
            return;
        }

        ProductsList *cart = new ProductsList();
        ProductsList *temp = NULL;

        menu.Display_menu();

        cout << "------------------------------" << endl;
        cout << "\nCustomer Name: ";
        cin.ignore();
        string name;
        getline(cin, name);

        cout << name << ", what do you want to order? " << endl;
        while (true)
        {

            cout << "\nSelect Category: \n";

            Node<ProductsList *> *curr = menu.get_CategoriesList()->getHead();

            for (int i = 1; i <= menu.get_CategoriesList()->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }

            int c;
            cin >> c;

            if (c > menu.get_CategoriesList()->getSize() || c < 1)
                continue;

            temp = menu.get_CategoriesList()->get_Category(c);
            break;
        }
        while (true)
        {
            system("CLS");
            temp->print();
            cout << "--------------------------------------------" << endl;
            cout << "Enter the serial number to add to Cart: ";
            int input;
            cin >> input;
            if (input > temp->getSize() || input < 1)
            {
                cout << "Invalid input!\nPlease enter a correct serial number" << endl;
                pressToContinue();
                continue;
            }

            Product p = temp->getProduct(input);
            cart->addProduct(p);
            double bill = GenerateBill(cart);
            orderStack.push(Order(name, invoiceNumber++, bill, cart));
            delete cart;
        }
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
