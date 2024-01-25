#include <iostream>
#include "Menu.cpp"
#include <stack>
using namespace std;
#include "CreateOrders.cpp"
class Hotel
{
private:
    string name;

public:
    Menu menu;
    stack<CreateOrders> stack;
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
        Node *temp = cart->getHead();

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
        while(!stack.empty())
        {
            //printing details 
        }
    }
    void Take_order()
    {
        ProductsList *cart;
        //display menu
        menu.Display_menu();
        cout <<" -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
        //product election code will be here

        // cart->addProduct(product to be added in cart);
        double bill = GenerateBill(cart);
        // CreateOrder order = new CreateOrder(cart,bill);
        //stack.push(order);
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