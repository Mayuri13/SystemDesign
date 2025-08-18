#ifndef USER_H
#define USER_H
#include "./Cart.h"
#include <bits/stdc++.h>
using namespace std;

class User{
    static int userId;
    int id;
    string name;
    string address;
    Cart* cart;

public:
    User(string name, string address){
        this->name = name;
        this->address = address;
        userId++;
        id = userId;
        cart = new Cart();
    }

    string getName(){
        return name;
    }

    string getAddress(){
        return address;
    }

    Cart* getCart(){
        return cart;
    }
};

int User::userId = 0;

#endif