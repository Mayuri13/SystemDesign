#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "./MenuItem.h"
#include <bits/stdc++.h>
using namespace std;

class Restaurant {
    static int restaurantId;
    int id;
    string name;
    string location;
    vector<MenuItem*>menuItems;

public:
    Restaurant(string name, string location){
        this->name = name;
        this->location = location;
        restaurantId++;
        id = restaurantId;
    }

    void displayItems(){
        for(int i=0; i<menuItems.size(); i++){
            cout<<" - " << menuItems[i]->getName()<<endl;
        }
    }

    void addMenuItem(MenuItem* menuItem){
        menuItems.push_back(menuItem);
    }

    vector<MenuItem*> getMenuItems(){
        return menuItems;
    }

    string getLocation(){
        return location;
    }

    string getName(){
        return name;
    }

    int getId(){
        return id;
    }
};

int Restaurant::restaurantId = 0;

#endif