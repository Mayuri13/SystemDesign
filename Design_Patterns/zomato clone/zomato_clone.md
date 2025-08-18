### main.cpp

- It creates the zomato app by creating 'Zomato' app.
- Create's objects of users who are active in the app.
- User's location is asked, so that restaurantList can be filtered as per the user's location.
- Restaurant is selected and the menuItems of that restaurant is selected by the user.
- Once the items are added in the cart, the user's cart is printed.
- the user will checkout now by choosing:
  - order type -> Delivery / pickup
  - payment strategy type -> Upi Payment / Credit Card
- check for payment succesful or not -> Current implementation just check for the payment strategy is included or not, if yes then payment is successful and its checked in Order.h file, and if its succesfull then notification sent and user's cart is cleared.

### ZomatoApp.h

- All the user's task will be henadled here and it will pass on the tasks to other classes by calling their methods.
- It will call restaurantManager->searchRestaurant(location) inside searchRestaurant method.
- The restaurants selected by the user is added in the Cart using selectRestaurant method.
- Items selected by user are added in the cart by addToCart method using Cart class.
- Checkout will be done by taking inputs as:
  - orderType -> delivery or pickUp
  - paymentStrategy -> Upi or Credit Card
  - orderFactory -> Order now or Order at scheduled time
