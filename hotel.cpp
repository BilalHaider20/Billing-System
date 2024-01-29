#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <fstream>

#include "Menu.cpp"
#include "order.h"
#include "productsList.h"

using namespace std;

class Hotel
{
private:
    string HISTORY = "history";
    string name;
    stack<Order> orderStack;
    int invoiceNumber = 10000000;
    Menu menu;
    double totalSales = 0;
    int totalProductsSold = 0;

public:
    Hotel()
    {
        name = "-";
    }

    Hotel(string name)
    {
        this->name = name;
    }

    void saveHistory()
    {
        string name;
        int invNumber;
        string dateTime;
        double bill;
        int totalItems;
        ofstream outputFile(HISTORY);

        if (!outputFile.is_open())
        {
            cerr << "\nError opening file!" << endl;
            return;
        }
        stack<Order> tempStack = orderStack;
        while (!tempStack.empty())
        {
            Order currentOrder = tempStack.top();
            bill = currentOrder.getBill();
            name = currentOrder.getCustomerName();
            invNumber = currentOrder.getInvoiceNumber();
            totalItems = currentOrder.getTotalItems();
            dateTime = currentOrder.getDateTime();
            string purchasedItems = "";
            ProductsList *prods = currentOrder.GetPurchasedItems();
            for (int i = 1; i <= prods->getSize(); i++)
            {
                for (char &c : prods->getProduct(i).getProduct_name())
                    if (c == ' ')
                        c = '_';
                purchasedItems += (prods->getCategory() + "%" + prods->getProduct(i).getProduct_name() + "*");
            }
            tempStack.pop();
            outputFile << name << " " << invNumber << " " << dateTime << " " << bill << " " << totalItems << " " << totalSales << " " << totalProductsSold << " " << purchasedItems << endl;
        }
        outputFile.close();
    }

    void loadHistory()
    {
        string name;
        int invNumber;
        string dateTime;
        double bill;
        int totalItems;
        string prods;
        ProductsList *productsPurchased = new ProductsList();
        ifstream inputFile(HISTORY);

        if (!inputFile.is_open())
        {
            cerr << "\nError opening file for reading." << endl;
            return;
        }

        while (!orderStack.empty())
        {
            orderStack.pop();
        }

        while (inputFile >> name >> invNumber >> dateTime >> bill >> totalItems >> totalSales >> totalProductsSold >> prods)
        {
            this->totalSales = totalSales;
            this->totalProductsSold = totalProductsSold;

            for (char &c : prods)
                if (c == '*')
                    c = ' ';

            string word = "";
            string catg = "";
            string prod = "";

            for (char &c : prods)
            {
                if (c != ' ')
                    word += c;
                else
                {
                    for (char &c : word)
                        if (c != '%')
                        {
                            catg += c;
                            c = ' ';
                        }
                    for (char &c : word)
                        if (c != ' ' && c != '%')
                            prod += c;
                    productsPurchased->addProduct(menu.get_CategoriesList()->get_Category(catg)->getProduct(prod));
                }
            }
            orderStack.push(Order(name, invNumber, bill, productsPurchased));
        }
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
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << "............ Billing History ...........\n\n";
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
            currentOrder.print2();
            tempStack.pop();
        }
        pressToContinue();
    }

    void TakeOrder()
    {
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << ".............. Place Order .............\n\n";
        if (menu.get_CategoriesList()->getSize() == 0)
        {
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
            menu.Display_menu();

            cout << "========================================================\n\n";

            cout << "Hi " << name << "! What do you want to order? \n(Enter \"x\" when done) " << endl;

            cout << "\n\nSelect Category:\n\n";

            Node<ProductsList *> *curr = menu.get_CategoriesList()->getHead();

            for (int i = 1; i <= menu.get_CategoriesList()->getSize(); i++)
            {
                cout << i << ". " << curr->getData()->getCategory() << endl;
                curr = curr->getNextPtr();
            }

            cout << "\nEnter the corresponding number: ";
            string input;
            cin >> input;

            if (input == "x" || input == "X")
                break;
            int c = stoi(input);
            if (c > menu.get_CategoriesList()->getSize() || c < 1)
            {
                cout << "\nInvalid Input\n";
                pressToContinue();
                continue;
            }

            temp = menu.get_CategoriesList()->get_Category(c);

            while (true)
            {
                system("CLS");
                cout << "\t\tFri-Chicks\n";
                cout << ".............. Place Order .............\n\n";

                temp->print();
                cout << "--------------------------------------------" << endl;
                cout << "Enter the serial number to add to Cart (Enter \"x\" when done): ";
                string input;
                cin >> input;
                if (input == "x" || input == "X")
                    break;
                int c = stoi(input);
                if (c > temp->getSize() || c < 1)
                {
                    cout << "Invalid input!\nPlease enter a correct serial number" << endl;
                    pressToContinue();
                    continue;
                }

                Product p = temp->getProduct(c);
                cart->addProduct(p);
                cout << "\n"
                     << p.getProduct_name() << " Added to Cart Successfully\n";
                pressToContinue();
            }
        }
        if (cart->getSize() == 0)
        {
            cout << "\nYou Haven't Placed Any Order\n";
            delete cart;
            pressToContinue();
            return;
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
        stack<Order> tempStack = orderStack;
        while (!tempStack.empty())
        {
            Order obj = tempStack.top();
            totalSales += obj.getBill();
            totalProductsSold += obj.getTotalItems();
            tempStack.pop();
        }
        system("cls");
        cout << "\t\tFri-Chicks\n";
        cout << "............... Total Sales ..............\n\n";
        cout << "Total Sales: Rs." << totalSales << endl;
        cout << "Total Number of Products Sold: " << totalProductsSold << endl;
        pressToContinue();
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
        menu.loadData();
        loadHistory();
        while (true)
        {
            system("cls");
            cout << "\t\tFri-Chicks\n";
            cout << "........................................\n\n";

            cout << "1. Manage Menu \n2. Take Orders \n3. Billing History \n4. Total Sales \n5. Refresh Data \n6. Exit" << endl;
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
                saveHistory();
                break;
            case '3':
                BillingHistory();
                break;
            case '4':
                Compute_Total_Sales();
                break;
            case '5':
                menu.loadData();
                loadHistory();
                system("cls");
                cout << "\t\tFri-Chicks\n";
                cout << "........................................\n\n";
                cout << "\nData Loaded Successfully.";
                pressToContinue();
                break;
            case '6':
                delete menu.get_CategoriesList();
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
