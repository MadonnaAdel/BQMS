#ifndef TELLER_H
#define TELLER_H
#include <iostream>
#include <random>

class Teller
{
public:
    Teller* Next;
    Teller* Prev;

    Teller()
    {
        Number = ++currentId;
        custCounter = 0;
        status = true;
        Next = Prev = nullptr;
    }

    int getNum()
    {
        return this->Number;
    }

    void setCustCount(int num)
    {
        custCounter+=num;
    }

    void setStatus(bool status)
    {
        this->status = status;
    }

    bool getStatus()
    {
        return this->status;
    }

    void setLeavingTime(int leavingCustTime)
    {
       servCustTime=leavingCustTime;
    }

    void setTotalservic(int servTime)
    {
        totalservic += servTime;
    }
    int getLeavingTime()
    {
        return this->servCustTime;
    }
    int getCounterCust()
    {
        return custCounter;
    }
    int getTotalService()
    {
        return totalservic;
    }
protected:
private:
    int Number;
    int custCounter=0;
    int servCustTime=0;
    int totalservic=0;
    bool status;
    static int currentId;
};
int Teller::currentId = 0;
#endif // TELLER_H
