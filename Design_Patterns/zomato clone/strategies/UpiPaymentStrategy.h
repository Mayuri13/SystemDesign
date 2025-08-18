#ifndef UPI_PAYMENT_H
#define UPI_PAYMENT_H
#include "./PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class UpiPayment : public PaymentStrategy{
    string UpiId;
public:
    UpiPayment(string upiId){
        this->UpiId = upiId;
    }

    void pay(int amount){
        cout<<"Paid ₹"<<amount<<" using UPI ("<<UpiId<<")"<<endl;
    }
};

#endif