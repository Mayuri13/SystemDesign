#ifndef CREDIT_CARD_PAYMENT_H
#define CREDIT_CARD_PAYMENT_H
#include "./PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class CreditCardPayment : public PaymentStrategy{
    string cardNumber;
public:
    CreditCardPayment(string card){
        this->cardNumber = card;
    }

    void pay(int amount){
        cout<<"Paid ₹"<<amount<<" using Credit Card ("<<cardNumber<<")"<<endl;
    }
};

#endif