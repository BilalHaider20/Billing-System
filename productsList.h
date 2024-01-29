#ifndef PRODUCTSLIST_H
#define PRODUCTSLIST_H

#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Product.h"
using namespace std;

class ProductsList
{
private:
    string category;
    Node<Product> *head;
    Node<Product> *tail;
    int size = 0;

public:
    Node<Product> *getHead()
    {
        return head;
    }

    ProductsList()
    {
        category = "-";
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ProductsList(string category)
    {
        this->category = category;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~ProductsList()
    {
        while (head != nullptr)
        {
            Node<Product> *temp = head;
            head = head->getNextPtr();
            delete temp;
        }
    }

    int getSize() const
    {
        return size;
    }

    string getCategory()
    {
        return category;
    }

    Product getProduct(int index)
    {
        if (index == 1)
            return head->getData();

        Node<Product> *curr = head;
        for (int i = 1; i < index; i++)
        {
            curr = curr->getNextPtr();
        }
        return curr->getData();
    }
    Product getProduct(string prod)
    {
        Node<Product> *curr = head;
        while (curr != nullptr)
        {
            if (curr->getData().getProduct_name() == prod)
            {
                return curr->getData();
            }
            curr = curr->getNextPtr();
        }

        return Product();
    }
    void addProduct(string name, int price)
    {
        Node<Product> *N = new Node<Product>(Product(size + 1, name, price));
        if (head == NULL)
        {
            N->setNextPtr(nullptr);
            head = N;
            tail = N;
            size++;
            return;
        }

        tail->setNextPtr(N);
        tail = tail->getNextPtr();
        size++;
        return;
    }

    void addProduct(Product p)
    {
        Node<Product> *N = new Node<Product>(p);
        if (head == NULL)
        {
            N->setNextPtr(nullptr);
            head = N;
            tail = N;
            size++;
            return;
        }

        tail->setNextPtr(N);
        tail = tail->getNextPtr();
        size++;
        return;
    }

    bool deleteProduct(int ind)
    {
        if (size == 0 || ind < 1 || ind > size)
            return false;

        if (ind == 1)
        {
            Node<Product> *current = head;
            head = head->getNextPtr();
            delete current;
            size--;
            if (size == 0)
                tail = nullptr;
            return true;
        }

        Node<Product> *current = head;
        Node<Product> *previous;

        for (int i = 1; i < ind; i++)
        {
            previous = current;
            current = current->getNextPtr();
        }
        previous->setNextPtr(current->getNextPtr());
        if (current == tail)
            tail = previous;
        delete current;
        size--;
        return true;
    }

    void print()
    {
        Node<Product> *curr = head;

        const int srWidth = 6;
        const int nameWidth = 25;
        const int priceWidth = 10;

        cout << "\n-----------------------------------------\n "
             << category << "\n-----------------------------------------\n";
        cout << setw(srWidth) << "Sr." << setw(nameWidth) << "Product Name"
             << "Price\n";
        cout << "-----------------------------------------\n";

        int i = 1;
        while (curr != nullptr)
        {
            cout << left << setw(srWidth) << i
                 << left << setw(nameWidth) << curr->getData().getProduct_name()
                 << left << "Rs. " << curr->getData().getProduct_price() << endl;

            curr = curr->getNextPtr();
            i++;
        }

        cout << "\n\n\n";
    }
};

#endif // PRODUCTSLIST_H
