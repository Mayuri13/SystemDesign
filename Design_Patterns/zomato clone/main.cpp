#include <iostream>
#include "zomatoApp.h"
using namespace std;

int main() {
    // Create ZomatoApp Object
    ZomatoApp* Zomato = new ZomatoApp();

    // Simulate a user coming in (Happy Flow)
    User* user = new User("Mayuri", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    cout << "Please share your location to know the restaurants available near you😊!"<<endl;
    string usersLocation;
    cin>>usersLocation;


    // User searches for restaurants by location
    vector<Restaurant*> restaurantList = Zomato->searchRestaurant(usersLocation);

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "🥗 Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - Id:" << restaurant->getId() <<" "<< restaurant->getName() << endl;
    }

    cout<<"Please select the restaurant by entering the restaurant id"<<endl;
    int resId;
    cin>>resId;

    // User selects a restaurant
    Zomato->selectRestaurant(user, restaurantList[resId-1]);

    cout << "Selected restaurant: " << restaurantList[resId-1]->getName() << endl;
    cout << "Select from the menu🍟"<<endl;
    restaurantList[resId-1]->displayItems();

    // User adds items to the cart
    Zomato->addToCart(user, "Chole Bhature");
    Zomato->addToCart(user, "Samosa");

    Zomato->printUserCart(user);

    // User checkout the cart
    Order* order = Zomato->checkoutNow(user, "Delivery", new UpiPayment("1234567890"));
    
    // User pay for the cart. If payment is success, notification is sent.
    Zomato->payForOrder(user, order);

    // Cleanup Code.
    delete Zomato;
    delete user;
    
    return 0;
}