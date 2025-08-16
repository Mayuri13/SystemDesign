#include <bits/stdc++.h>
using namespace std;

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

// Burger Factory, which will take the type of the burger and will create the object of that burger type
class Burger_Factory {
    string type;
public:
    Burger_Factory(string type) {
        this->type = type;
    }

    // Creating the desired burger that user is wishing to take
    Burger* createBurger(){
        if(type == "Basic")
            return new Basic_Burger();
        else if(type == "Standard")
            return new Standard_Burger();
        return new Premium_Burger();
    }
};

int main(){
    Burger_Factory* myFactory = new Burger_Factory("Basic");
    Burger* burger = myFactory->createBurger();
    burger->prepare();
    return 0;
}