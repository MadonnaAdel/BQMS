#ifndef BANK_H
#define BANK_H
#include <cstdlib>
#include "Customer.h"
#include "Teller.h"
#include "linkedTeller.h"
#include "CustomerQueue.h"
using namespace std;

class Bank
{
public:

    Bank(int sizeTellers):tellers(),Queue()
    {
        while(sizeTellers--)
        {
            tellers.addTeller();
        }
    }


    void startService()
    {
        Teller* currentFree;
        Customer currentCust;
        if(tellers.getFreeTeller(currentFree))
        {
            if(!Queue.isEmpty())
            {
                if(Queue.deQueue(currentCust));
                serviceFreeTeller(currentCust,currentFree);
            }
        }
        else
        {
            if(!Queue.isEmpty())
            {
                if(Queue.deQueue(currentCust));
                srviceBusyTeller(currentCust);
            }

        }
    }


    void addNewTeller()
    {
        tellers.addTeller();
    }


    CustomerQueue &getQueue()
    {
        return ReportQueue;
    }

    void addCustomer(Customer customer)
    {
        Queue.enQueue(customer);
    }


    linkedTeller &getLinkedTeller()
    {
        return tellers;
    }


private:
    linkedTeller tellers;
    CustomerQueue Queue;
    CustomerQueue ReportQueue;


    void serviceFreeTeller(Customer &chosiedCust, Teller *&freeTeller)
    {
        chosiedCust.setWiteTim(0);
        int depTime=chosiedCust.getArravTime()+chosiedCust.getServTime();
        chosiedCust.setDepTim(depTime);
        freeTeller->setStatus(false);
        freeTeller->setCustCount(1);
        freeTeller->setLeavingTime(depTime);
        freeTeller->setTotalservic(depTime);
        ReportQueue.enQueue(chosiedCust);
    }



    void srviceBusyTeller(Customer &chosiedCust)
    {
        Teller *currentFree = tellers.getHead();
        Teller *temp = tellers.getHead();
        if (temp != nullptr)
            temp = temp->Next;

        while (temp != nullptr)
        {
            if (currentFree->getLeavingTime() > temp->getLeavingTime())
            {
                currentFree = temp;
            }
            temp = temp->Next;
        }
        if (chosiedCust.getArravTime() > currentFree->getLeavingTime())
        {
            chosiedCust.setWiteTim(0);
            int depTime = chosiedCust.getArravTime() + chosiedCust.getServTime();
            chosiedCust.setDepTim(depTime);
            currentFree->setLeavingTime(depTime);
            currentFree->setCustCount(1);
            currentFree->setTotalservic(depTime);
            ReportQueue.enQueue(chosiedCust);
        }

        else
        {
            chosiedCust.setWiteTim(currentFree->getLeavingTime() - chosiedCust.getArravTime());
            int depTime=chosiedCust.getArravTime() + chosiedCust.getServTime() + chosiedCust.getWiteTim();
            chosiedCust.setDepTim(depTime);
            currentFree->setLeavingTime(depTime);
            currentFree->setCustCount(1);
            currentFree->setTotalservic(depTime);
            ReportQueue.enQueue(chosiedCust);
        }
    }


};

#endif // BANK_H
