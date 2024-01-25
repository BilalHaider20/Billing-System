#include <iostream>
#include "Node.h"
using namespace std;

class ProductsList
{
private:
    string category;
    Node *head;
    Node *tail;
    int size;

public:
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

    int getSize() const
    {
        return size;
    }

    string getCategory()
    {
        return category;
    }

    void addProduct(Product p)
    {
        Node *N = new Node(p);
        if (size == 0)
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

    bool deleteProduct(string ID)
    {
        if (size == 0)
            return false;
        if (ID == head->getData().getProduct_ID())
        {
            Node *current = head;
            head = nullptr;
            tail = nullptr;
            delete current;
            size--;
            return true;
        }

        Node *current = head;
        Node *previous;
        while (current->getNextPtr() != NULL)
        {
            previous = current;
            current = current->getNextPtr();
            if (ID == (current->getData().getProduct_ID()))
            {
                previous->setNextPtr(current->getNextPtr());
                size--;
                delete current;
                return true;
            }
        }
        return false;
    }

    void print()
    {
        Node *curr = head;
        cout << "-----------------------------------------\n| "
             << category << "\t\t\t\t|\n-----------------------------------------\n";
        cout << "Product ID \tName\t\tPrice" << endl;
        while (curr != nullptr)
        {
            cout << curr->getData().getProduct_ID() << "\t\t" << curr->getData().getProduct_name() << "\t\tRs." << curr->getData().getProduct_price() << endl;
            curr = curr->getNextPtr();
        }
        cout << "\n\n\n";
    }
};