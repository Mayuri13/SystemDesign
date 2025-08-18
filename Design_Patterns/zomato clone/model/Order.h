#ifndef ORDER_H
#define ORDER_H
#include "./MenuItem.h"
#include "./restaurant.h"
#include "./User.h"
#include "../strategies/PaymentStrategy.h"

class Order{
    static int orderId;
    int id, total;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem*> items;
    PaymentStrategy* paymentStrategy;
    string scheduled;

public:
    Order(){
        total = 0;
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        orderId++;
        id = orderId;
        scheduled = "";
    }

    bool processPayment() {
        if(paymentStrategy){
            paymentStrategy->pay(total);
            return true;
        }
        else{
            cout<<"Please choose a payment mode first"<<endl;
            return false;
        }
    }

    virtual string getType() = 0;

    //Getter and Setters
    int getOrderId() const {
        return id;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const vector<MenuItem*>& its) {
        items = its;
    }

    vector<MenuItem*>& getItems() {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        paymentStrategy = p;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }  
};

int Order::orderId = 0;

#endif