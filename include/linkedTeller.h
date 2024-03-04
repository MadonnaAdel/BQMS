#ifndef LINKEDTELLER_H
#define LINKEDTELLER_H

#include"Teller.h"

class linkedTeller
{
public:
    linkedTeller()
    {
        headTellers = tailTeller = nullptr;
    }

    void addTeller()
    {
        Teller* newTeller = new Teller();

        if (headTellers == nullptr)
        {
            headTellers = tailTeller = newTeller;
        }
        else
        {
            tailTeller->Next = newTeller;
            newTeller->Prev = tailTeller;
            tailTeller = newTeller;
        }
        Length++;
    }

    int removeTeller()
    {
        if (headTellers == nullptr)
            return 0;

        Teller* temp = tailTeller;
        if (temp != nullptr)
        {
            tailTeller->Prev = nullptr;
            tailTeller = temp;
            if (tailTeller != nullptr)
            {
                tailTeller->Next = nullptr;
            }
        }
        else
        {
            delete tailTeller;
            headTellers = tailTeller = nullptr;
        }
        Length--;
        return 1;
    }


    static int getLength()
    {
        return Length;
    }

    void setHead(Teller *head)
    {
        headTellers=head;
    }
    void setTail(Teller *tail)
    {
        tailTeller=tail;
    }

    Teller * getHead()
    {
        return headTellers;
    }

    Teller * getTail()
    {
        return tailTeller;
    }


    int getFreeTeller(Teller*& freeTeller)
    {
        Teller* temp = headTellers;
        while (temp != nullptr)
        {
            if (temp->getStatus())
            {
                freeTeller = temp;
                return 1;
            }
            else
            {
                temp = temp->Next;
            }
        }
        return 0;
    }

private:

    Teller* headTellers;
    Teller* tailTeller;
    static int Length ;

};
int linkedTeller::Length=0;
#endif // LINKEDTELLER_H
