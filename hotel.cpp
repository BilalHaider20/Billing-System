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
        system("CLS");
        cout << "Orders History" << endl;
        while (!orderStack.empty())
        {
            Order obj = orderStack.top();
            cout << "Customer Name: " << obj.getCustomerName() << endl;
            cout << "Invoice Number: " << obj.getInvoiceNumber() << endl;
            cout << "Items Purchased:\n";
            ProductsList *products = obj.GetPurchasedItems();
            products->print();
            cout << "Total Bill\t\t" << obj.getBill() << endl;
            orderStack.pop();
            cout << "===============================================" << endl;
        }
    }

   void TakeOrder()
{
    try
    {
        
        if (menu.get_CategoriesList()->getSize() == 0)
        {
            throw runtime_error("Menu is Empty! Please add Categories and items in the menu.");
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

            int categoryChoice;
            cin >> categoryChoice;

            if (categoryChoice > menu.get_CategoriesList()->getSize() || categoryChoice < 1)
            {
                throw out_of_range("Invalid category choice. Please enter a valid category number.");
            }

            temp = menu.get_CategoriesList()->get_Category(categoryChoice);
            break;
        }

        while (true)
        {
            
            system("CLS");
            temp->print();
            cout << "--------------------------------------------" << endl;

            
            cout << "Enter the serial number to add to Cart: ";
            int productChoice;
            cin >> productChoice;

           
            if (productChoice > temp->getSize() || productChoice < 1)
            {
                throw out_of_range("Invalid input! Please enter a correct serial number.");
            }

            
            Product selectedProduct = temp->getProduct(productChoice);
            cart->addProduct(selectedProduct);

           
            cout << "\nWant to add another product? (y/n) ";
            char addMore;
            cin >> addMore;

            // Handle user response
            if (addMore == 'n' || addMore == 'N')
            {
                break;
            }
            else if (addMore != 'y' && addMore != 'Y')
            {
                throw invalid_argument("Invalid input! Please enter 'y' or 'n'.");
            }
        }

        // Generate bill, create order, and add to order stack
        double bill = GenerateBill(cart);
        Order newOrder(name, invoiceNumber++, bill, cart);
        orderStack.push(newOrder);
        Generate_Invoice(newOrder);
    }
    catch (const exception &ex)
    {
        cerr << "Error: " << ex.what() << endl;
        pressToContinue();
    }
}

    void Generate_Invoice(Order obj)
    {
        system("CLS");
        cout << "\t\t"<<name << endl<<endl;
        cout << "Customer Name: " << obj.getCustomerName() << endl;
        cout << "Invoice Number: " << obj.getInvoiceNumber() << endl;
        cout << "Items Purchased:\n";
        ProductsList *products = obj.GetPurchasedItems();
        products->print();
        cout << "Total Bill\t\t" << obj.getBill() << endl;
        cout << "===============================================" << endl;
        pressToContinue();
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
    cout << "Total Sales: $" << totalSales << endl;
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
