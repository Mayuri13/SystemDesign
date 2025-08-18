#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H
#include "../model/Order.h"
#include <bits/stdc++.h>
using namespace std;

class OrderManager {
    static OrderManager* orderManager;
    vector<Order*>orders;
    OrderManager() {

    }

public:
    static OrderManager* createOrderManager() {
        if(orderManager == nullptr){
            orderManager = new OrderManager();
        }
        return orderManager;
    }

    void addOrder(Order* order){
        orders.push_back(order);
    }

    void listOrders() {
        cout<<"📝 ----------- All Orders ------------"<<endl;
        for(auto order: orders){
            cout<< order->getType() <<" order for "<<order->getUser()->getName() << " | Total: ₹"
            <<order->getTotal()<<" | At: "<< order->getScheduled()<<endl;
        }
    }
};

OrderManager* OrderManager::orderManager = nullptr;

#endif