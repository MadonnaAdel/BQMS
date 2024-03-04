#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <random>

using namespace std;
class Customer
{
public:
    Customer(){}
    Customer(int arravTime,int servTime)
    {
        ID=currentId++;
        this->arravTime=arravTime;
        this->servTime=servTime;
    }

    int getArravTime()
    {
        return this->arravTime;
    }
    int getId()
    {
        return this->ID;
    }
    int getServTime()
    {
        return this->servTime;
    }

    void setDepTim(int depTime)
    {
        this->depTime=depTime;
    }
    void setWiteTim(int witeTime)
    {
        this->witeTime += witeTime;
    }
    int getDepTime()
    {
        return this->depTime;
    }
    int getWiteTim()
    {
        return this->witeTime;
    }


protected:

private:
    int ID;
    int arravTime=0;
    int depTime=0;
    int servTime=0;
    int witeTime=0;
    static int currentId;
};
int Customer::currentId = 1;

#endif // CUSTOMER_H
