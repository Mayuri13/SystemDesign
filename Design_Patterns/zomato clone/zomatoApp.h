#ifndef ZOMATO_H
#define ZOMATO_H
#include <bits/stdc++.h>
#include "model/User.h"
#include "model/restaurant.h"
#include "model/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduleOrderFactory.h"
#include "factories/OrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

using namespace std;

class ZomatoApp {
    RestaurantManager* restaurantManager;
public:
    ZomatoApp(){
        restaurantManager = RestaurantManager::createRestaurantManager();
        InitializeRestaurants();
    }

    void InitializeRestaurants(){
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(new MenuItem("Chole Bhature", 120));
        restaurant1->addMenuItem(new MenuItem("Samosa", 15));

        Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenuItem(new MenuItem("Raj Kachori", 80));
        restaurant2->addMenuItem(new MenuItem("Pav Bhaji", 100));
        restaurant2->addMenuItem(new MenuItem("Dhokla", 50));

        Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(new MenuItem("Masala Dosa", 90));
        restaurant3->addMenuItem(new MenuItem("Idli Vada", 60));
        restaurant3->addMenuItem(new MenuItem("Filter Coffee", 30));

        restaurantManager->addRestaurants(restaurant1);
        restaurantManager->addRestaurants(restaurant2);
        restaurantManager->addRestaurants(restaurant3);
    }

    // User will search restaurant in the app
    vector<Restaurant*> searchRestaurant(string location){
        return restaurantManager->searchRestaurant(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant){
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user, string itemName){
        Restaurant* restaurant = user->getCart()->getRestaurant();

        if(!restaurant){
            cout<<"Please select a restaurant first."<<endl;
            return;
        }
        for(auto item: restaurant->getMenuItems()){
            if(item->getName() == itemName){
                user->getCart()->addItemInCart(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, string orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, string orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduleOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, string orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem*> itemsOrdered = userCart->getItems();
        int totalCost = userCart->totalCartValue();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::createOrderManager()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item->getId() << " : " << item->getName() << " : ₹" << item->getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->totalCartValue() << endl;
    }
};

#endif