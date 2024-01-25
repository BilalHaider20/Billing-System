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
    Order(string customerName, int invoiceNumber, double bill, ProductsList *PurchasedItems)
    {
        this->customerName = customerName;
        this->invoiceNumber = invoiceNumber;
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
};
