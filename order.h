#ifndef ORDER_H
#define ORDER_H

#include <iostream>
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

public:
    Order(string customerName, int inv, double bill, ProductsList *PurchasedItems)
    {
        this->customerName = customerName;
        this->invoiceNumber = inv;
        this->bill = bill;
        this->PurchasedItems = PurchasedItems;
        this->totalItems = PurchasedItems->getSize();
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
        cout << "\nInvoice Number: " << getInvoiceNumber() << endl;
        cout << "Customer Name: " << getCustomerName() << endl;

        cout << "\nItems Purchased:\n";
        ProductsList *purchasedItems = GetPurchasedItems();
        for (int i = 1; i <= purchasedItems->getSize(); ++i)
        {
            Product product = purchasedItems->getProduct(i);
            cout << i << "- " << product.getProduct_name() << "- Rs." << product.getProduct_price() << endl;
        }

        cout << "\nTotal Items: " << getTotalItems() << endl;
        cout << "Total Bill: Rs." << getBill() << endl;
    }
};

#endif // ORDER_H
