#ifndef ORDER_PICK_UP
#define ORDER_PICK_UP
#include "./Order.h"
#include <bits/stdc++.h>
using namespace std;

class OrderPickUp : public Order{
    string restaurantAddress;
public:
    OrderPickUp(){
        restaurantAddress = "";
    }

    string getType(){
        return "Pickup";
    }

    void setRestaurantAddress(string address){
        this->restaurantAddress = address;
    }

    string getRestaurantAddress(){
        return restaurantAddress;
    }
};

#endif