#ifndef SCHEDULE_ORDER_FACTORY_H
#define SCHEDULE_ORDER_FACTORY_H
#include "../model/Order.h"
#include "../model/restaurant.h"
#include "../model/MenuItem.h"
#include "../model/DeliveryOrder.h"
#include "../model/Cart.h"
#include "../strategies/PaymentStrategy.h"
#include "../model/OrderPickUp.h"
#include "./OrderFactory.h"
#include <bits/stdc++.h>

class ScheduleOrderFactory : public OrderFactory{
    string scheduleTime; 
public:
    ScheduleOrderFactory(string scheduleTime){
        this->scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, vector<MenuItem*> 
        &items, PaymentStrategy* paymentStrategy, int totalCost, string orderType) {

            Order* order = nullptr;
            if(orderType == "Delivery"){
                DeliveryOrder* deliveryOrder = new DeliveryOrder();
                deliveryOrder->setUserAddress(user->getAddress());
                order = deliveryOrder;
            }
            else{
                OrderPickUp* pickupOrder = new OrderPickUp();
                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                order = pickupOrder;
            }
            order->setUser(user);
            order->setRestaurant(restaurant);
            order->setItems(items);
            order->setPaymentStrategy(paymentStrategy);
            order->setScheduled(scheduleTime);
            order->setTotal(totalCost);
            return order;
        }
};

#endif