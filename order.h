#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <ctime>
#include <chrono>
#include "productsList.h"
using namespace std;

class Order
{
private:
    string customerName;
    int invoiceNumber;
    ProductsList *PurchasedItems;
    double bill;
    int totalItems;
    string dateTime;

public:
    Order(string customerName, int inv, double bill, ProductsList *PurchasedItems)
    {
        this->customerName = customerName;
        this->invoiceNumber = inv;
        this->bill = bill;
        this->PurchasedItems = PurchasedItems;
        this->totalItems = PurchasedItems->getSize();
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        dateTime = ctime(&now);
    }

    string getCustomerName() const
    {
        return customerName;
    }

    int getInvoiceNumber() const
    {
        return invoiceNumber;
    }

    ProductsList *GetPurchasedItems() const
    {
        return PurchasedItems;
    }

    double getBill() const
    {
        return bill;
    }

    int getTotalItems() const
    {
        return totalItems;
    }

    void print()
    {
        cout << "-----------------------------------------\n";
        cout << "Invoice Number: " << getInvoiceNumber() << endl;
        cout << "Customer Name: " << getCustomerName() << endl;
        cout << "Date and Time: " << dateTime;

        cout << "\nItems Purchased:\n";
        ProductsList *purchasedItems = GetPurchasedItems();

        for (int i = 1; i <= purchasedItems->getSize(); ++i)
        {
            Product product = purchasedItems->getProduct(i);
            cout << i << ". " << product.getProduct_name() << "- Rs." << product.getProduct_price() << endl;
        }

        cout << "\nTotal Items Purchased: " << getTotalItems() << endl;
        cout << "Total Bill: Rs." << getBill() << endl;
        cout << "-----------------------------------------\n";
    }

    void print2()
    {
        cout << "-----------------------------------------\n";
        cout << "Invoice Number: " << getInvoiceNumber() << endl;
        cout << "Customer Name: " << getCustomerName() << endl;
        cout << "Date and Time: " << dateTime;

        cout << "\nTotal Items Purchased: " << getTotalItems() << endl;
        cout << "Total Bill: Rs." << getBill() << endl;
        cout << "-----------------------------------------\n";
    }
};

#endif // ORDER_H
