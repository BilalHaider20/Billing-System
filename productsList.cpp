#include <iostream>
#include "product.cpp"
#include "Node.cpp"
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

    int size() const
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

    void deleteProduct(string ID)
    {
        if (ID == head->getData().getProduct_ID())
        {
            Node *current = head;
            head = nullptr;
            tail = nullptr;
            delete current;
            size--;
            return;
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
                return;
            }
        }
    }

    void print()
    {
        Node *curr = head;
        cout << category << ": " << endl;
        while (curr != NULL)
        {
            cout << curr->getData().getProduct_ID() << "\t\t" << curr->getData().getProduct_name() << "\t\tRs." << curr->getData().getProduct_price() << endl;
        }
    }
};