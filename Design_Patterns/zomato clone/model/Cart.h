#ifndef CART_H
#define CART_H
#include "./restaurant.h"
#include "./MenuItem.h"

class Cart {
    Restaurant* r;
    vector<MenuItem*>menuItems;
    int total;

public:
    Cart(){
        total = 0;
    }

    void addItemInCart(MenuItem* menuItem){
        menuItems.push_back(menuItem);
    }

    bool isEmpty(){
        return menuItems.size() == 0;
    }

    int totalCartValue(){
        total = 0;
        for(int i=0; i<menuItems.size(); i++){
            total += menuItems[i]->getPrice();
        }
        return total;
    }

    void setRestaurant(Restaurant* restaurant){
        this->r = restaurant;
    }

    vector<MenuItem*> getItems(){
        return menuItems;
    }

    Restaurant* getRestaurant(){
        return r;
    }

    void clear(){
        menuItems.clear();
        r = nullptr;
    }
};

#endif