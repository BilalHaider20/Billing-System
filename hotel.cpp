#include <iostream>
#include "Menu.cpp"
#include <stack>
using namespace std;

class Hotel
{
private:
    string name;

public:
    Menu menu;
    stack<ProductsList*> stack;
    Hotel()
    {
        name = "-";
    }
    Hotel(string name)
    {
        this->name = name;
    }

    int GenerateBill(ProductsList *cart,string costumer_name)
    {
        Node *temp = cart->getHead();

        double bill = 0;
        ProductsList* purchase_items = new ProductsList(costumer_name);
        while (temp != nullptr)
        {
            bill += temp->getData().getProduct_price();
            purchase_items->addProduct(temp->getData());
            temp = temp->getNextPtr();
        }
        Add_To_History(purchase_items);
        return bill;
    }
    void Add_To_History(ProductsList* purchased_items)
    {
        stack.push(purchased_items);
    }
    void Billing_History()
    {
        
    }
    void menuManager()
    {
        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "............ Menu Management ...........\n\n";

            cout << "1. See Menu \n2. Add New Items in Menu \n3. Delete Items from Menu \n4. Go Back" << endl;
            cout << "\nEnter the corresponding number ";
            char input;
            cin >> input;

            switch (input)
            {
            case '1':
                menu.Display_menu();
                break;
            case '2':
                menu.AddItem();
                break;
            case '3':
                menu.deleteItem();
                break;
            case '4':
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

            cout << "1. Manage Menu \n2. Generate Bill \n3. Billing History \n4. Total Sales \n5. Exit" << endl;
            cout << "\nEnter the corresponding number ";

            char input;

            cin >> input;
            switch (input)
            {
            case '1':
                menuManager();
                break;
            case '2':
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
};