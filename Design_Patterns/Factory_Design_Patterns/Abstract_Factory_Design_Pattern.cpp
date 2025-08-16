#include <bits/stdc++.h>
using namespace std;

/*---------------------------------- Product 1 ---------------------------------- */
// Burger Base Class
class Burger {
public:
    virtual void prepare() = 0;
};

// Concrete Class -> Basic Burger 
class Basic_Burger : public Burger {
public:
    void prepare() {
        cout<<"Basic Burger is getting prepared..."<<endl;
    }
};

// Concrete Class -> Standard Burger 
class Standard_Burger : public Burger {
public:
    void prepare() {
        cout<<"Standard Burger is getting prepared..."<<endl;
    }
};

// Concrete Class -> Premium Burger 
class Premium_Burger : public Burger {
public:
    void prepare() {
        cout<<"Premium Burger is getting prepared..."<<endl;
    }
};

// Concrete Class -> Basic Wheat Burger 
class Basic_Wheat_Burger : public Burger {
public:
    void prepare() {
        cout<<"Basic Wheat Burger is getting prepared..."<<endl;
    }
};

// Concrete Class -> Standard Wheat Burger 
class Standard_Wheat_Burger : public Burger {
public:
    void prepare() {
        cout<<"Standard Wheat Burger is getting prepared..."<<endl;
    }
};

// Concrete Class -> Premium Wheat Burger 
class Premium_Wheat_Burger : public Burger {
public:
    void prepare() {
        cout<<"Premium Wheat Burger is getting prepared..."<<endl;
    }
};


/*---------------------------------- Product 2 ----------------------------------*/
// Garlic Bread Base Class
class GBread {
public:
    virtual void prepare() = 0;
};

// Concrete Class -> Basic Burger 
class Basic_GBread : public GBread {
public:
    void prepare() {
        cout<<"Basic Garlic Bread is getting prepared..."<<endl;
    }
};

// Concrete Class -> Standard Burger 
class Cheese_GBread : public GBread {
public:
    void prepare() {
        cout<<"Cheese Garlic Bread is getting prepared..."<<endl;
    }
};

// Concrete Class -> Premium Burger 
class Basic_Wheat_GBread : public GBread {
public:
    void prepare() {
        cout<<"Basic Wheat Garlic Breadis getting prepared..."<<endl;
    }
};

// Concrete Class -> Basic Wheat Burger 
class Cheese_Wheat_GBread : public GBread {
public:
    void prepare() {
        cout<<"Cheese Wheat Garlic Bread is getting prepared..."<<endl;
    }
};


// Burger Factory, which will take the type of the burger and will create the object of that burger type
class Burger_Factory {
public:
    virtual Burger* createBurger(string type) = 0;
    virtual GBread* createGBread(string type) = 0;
};

// Concrete class of burger factory
class SinghBurger : public Burger_Factory {
public:

    // Creating the desired burger that user is wishing to take
    Burger* createBurger(string type){
        if(type == "Basic")
            return new Basic_Burger();
        else if(type == "Standard")
            return new Standard_Burger();
        return new Premium_Burger();
    }

    // Creating the desired burger that user is wishing to take
    GBread* createGBread(string type){
        if(type == "Basic")
            return new Basic_GBread();
        else if(type == "Cheese")
            return new Cheese_GBread();
        else{
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

// Concrete Class of Burger Factory
class KingBurger : public Burger_Factory {
public:

    // Creating the desired burger that user is wishing to take
    Burger* createBurger(string type){
        if(type == "Basic")
            return new Basic_Wheat_Burger();
        else if(type == "Standard")
            return new Standard_Wheat_Burger();
        return new Premium_Wheat_Burger();
    }

    GBread* createGBread(string type){
        if(type == "Basic")
            return new Basic_Wheat_GBread();
        else if(type == "Cheese")
            return new Cheese_Wheat_GBread();
        else{
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

int main(){
    string burgerType = "Standard";
    string gBreadType = "Cheese";

    Burger_Factory* myFactory1 = new SinghBurger();
    Burger* burger1 = myFactory1->createBurger(burgerType);
    burger1->prepare();
    GBread* gBread1 = myFactory1->createGBread(gBreadType);
    gBread1->prepare();

    Burger_Factory* myFactory2 = new KingBurger();
    Burger* burger2 = myFactory2->createBurger(burgerType);
    burger2->prepare();
    GBread* gBread2 = myFactory2->createGBread(gBreadType);
    gBread2->prepare();
    return 0;
}