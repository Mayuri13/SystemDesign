#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

class PaymentStrategy{
public:
    virtual void pay(int amount) = 0;
};

#endif