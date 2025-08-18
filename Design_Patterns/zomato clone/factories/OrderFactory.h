#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H
#include "../model/Order.h"
#include "../model/restaurant.h"
#include "../model/MenuItem.h"
#include "../model/Cart.h"
#include "../strategies/PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, vector<MenuItem*> 
        &items, PaymentStrategy* paymentStrategy, int totalCost, string orderType) = 0;
};

#endif