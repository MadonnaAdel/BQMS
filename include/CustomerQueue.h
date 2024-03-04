#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H
#include "Customer.h"
#include <queue>
#include <vector>

using namespace std;
class CustomerQueue
{
public:
    CustomerQueue(){}

    bool isEmpty()
    {
        return regularQueue.empty();
    }

    void enQueue( Customer& customer)
    {
            regularQueue.push(customer);
            counter++;
    }

    int deQueue(Customer& customer)
    {
        if (!regularQueue.empty())
        {
            customer = regularQueue.front();
            regularQueue.pop();
            counter--;
            counter--;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int displayAllCustomers(vector<Customer>& allCustomers) const
    {
        allCustomers.clear();

        queue<Customer> tempRegularQueue = regularQueue;
        while (!tempRegularQueue.empty())
        {
            Customer cust = tempRegularQueue.front();
            allCustomers.push_back(cust);
            tempRegularQueue.pop();
        }

        return !allCustomers.empty();
    }


    static int length()
    {
        return counter;
    }

private:
    static queue<Customer> regularQueue;
    static int counter;
};
int CustomerQueue::counter=0;
queue<Customer> CustomerQueue::regularQueue;

#endif // CUSTOMERQUEUE_H
