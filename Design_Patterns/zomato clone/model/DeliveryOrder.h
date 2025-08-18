#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H
#include "./Order.h"
#include <bits/stdc++.h>
using namespace std;

class DeliveryOrder : public Order{
    string userAddress;
public:
    DeliveryOrder(){
        userAddress = "";
    }

    string getType(){
        return "Delivery";
    }

    void setUserAddress(string address){
        this->userAddress = address;
    }

    string getUserAddress(){
        return userAddress;
    }
};

#endif