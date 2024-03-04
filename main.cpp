#include <iostream>
#include <vector>
#include <windows.h>
#include "Customer.h"
#include "Teller.h"
#include "Bank.h"
#include "linkedTeller.h"
using namespace std;
void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int main()
{
    int TellerSize, numCustomer, arravTime, servTime,hours;
    string isAddTeller="yes";
    SetColor(12);
    cout<<"\t \t \t \t \t \tWellcome in BQMS"<<endl;

    SetColor(7);
    cout << "Enter the number of Hours Work: ";
    cin >> hours;
    cout << "Enter the number of tellers: ";
    cin >> TellerSize;
    Bank bank(TellerSize);

    cout << "Enter the number of customers: ";
    cin >> numCustomer;

    for (int i = 0; i < numCustomer; i++)
    {
        cout << "Enter arrival and service time for customer " << i + 1 << ": ";
        cin >> arravTime >> servTime;
        bank.addCustomer(Customer(arravTime, servTime));
    }

    cout<<"\n Well Now there are "<<bank.getQueue().length()<<" in your queue let's begin to service them"<<endl;

    while(isAddTeller=="yes")
    {
        cout<<"Do you won't add teller ? (yes or no)"<<endl;
        cin>>isAddTeller;

        if(isAddTeller=="yes")
        {
            bank.addNewTeller();
            SetColor(2);
            cout<<"teller added..."<<endl;
        }
        else
        {
            break;
        }
        SetColor(7);
    }



    SetColor(7);
    for (int i = 0; i < numCustomer; i++)
    {
        bank.startService();
        int lenght= bank.getQueue().length();
        cout<<"\n Now there are "<<lenght--<<" in your queue"<<endl;
    }

    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    CustomerQueue customerQueue = bank.getQueue();

    vector<Customer> allCustomers;
    int result = customerQueue.displayAllCustomers(allCustomers);

    if (result)
    {
        SetColor(12);
        cout <<"\n Customers in the queue:\n"<<endl;
        for (auto& customer : allCustomers)
        {
            SetColor(7);
            cout  <<"Customer ID: "<<"\t arraivl Time:"<< "\t service time:"<<"\t witing time"<<"\t depurtual Time:"<<endl;
            cout  <<customer.getId()<<"\t\t"
                  <<customer.getArravTime()<<"\t\t"
                  <<customer.getServTime()<<"\t\t"
                  <<customer.getWiteTim()<<"\t\t"
                  <<customer.getDepTime()<< "\n";
        }
    }


    cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    linkedTeller tellers=bank.getLinkedTeller();

    if (linkedTeller::getLength()>0)
    {
        Teller * head=tellers.getHead();
        SetColor(12);

        cout << "Tellers in the bank:\n"<<endl;
        while (head!=NULL)
        {
            SetColor(7);

            double utilization=head->getTotalService()/hours;

            cout << "teller Id" << "\t teller status"
                 <<"\t service time" <<"\t Customer Number servied"
                 <<"\t utilization rate"<< endl;
            cout << head->getNum()<<"\t\t" <<
                 head->getStatus() <<"\t\t" <<
                 head->getTotalService()<<"\t\t" <<
                 head->getCounterCust()<<"\t\t\t\t"<<
                 utilization<< endl;
                 head=head->Next;
        }
    }

    return 0;
}

