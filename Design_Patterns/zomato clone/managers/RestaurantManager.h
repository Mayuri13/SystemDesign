#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <bits/stdc++.h>
#include "../model/restaurant.h"
using namespace std;

class RestaurantManager{
    static RestaurantManager* restaurantManager;
    vector<Restaurant*>restaurants;
    RestaurantManager() {

    }
public:
// Singleton Design Pattern for creating restaurant manager
    static RestaurantManager* createRestaurantManager(){
        if(restaurantManager == nullptr){
            restaurantManager = new RestaurantManager();
        }
        return restaurantManager;
    }

    void addRestaurants(Restaurant* restaurant){
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> searchRestaurant(string location){
        vector<Restaurant*> filteredRestaurants;
        transform(location.begin(), location.end(), location.begin(), ::tolower);

        for(int i=0; i<restaurants.size(); i++){
            string r1 = restaurants[i]->getLocation(); 
            transform(r1.begin(), r1.end(), r1.begin(), ::tolower);

            if(r1 == location)
                filteredRestaurants.push_back(restaurants[i]);
        }
        return filteredRestaurants;
    }
};

RestaurantManager* RestaurantManager::restaurantManager = nullptr;

#endif