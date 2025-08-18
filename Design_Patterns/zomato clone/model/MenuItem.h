#ifndef MENU_H
#define MENU_H
#include <bits/stdc++.h>
using namespace std;

class MenuItem {
    static int menuCode;
    int id;
    string name;
    int price;

public:
    MenuItem(string name, int price){
        menuCode++;
        id = menuCode;
        this->name = name;
        this->price = price;
    }

    void setName(string name){
        this->name = name;
    }

    string getName(){
        return name;
    }

    void setPrice(int price){
        this->price = price;
    }

    int getPrice(){
        return price;
    }

    int getId(){
        return id;
    }

};

int MenuItem::menuCode = 0;

#endif