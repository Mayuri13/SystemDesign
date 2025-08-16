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



// Burger Factory, which will take the type of the burger and will create the object of that burger type
class Burger_Factory {
public:
    virtual Burger* createBurger() = 0;
};

// Concrete class of burger factory
class SinghBurger : public Burger_Factory {
    string type;
public:
    SinghBurger(string type) {
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

// Concrete Class of Burger Factory
class KingBurger : public Burger_Factory {
    string type;
public:
    KingBurger(string type) {
        this->type = type;
    }

    // Creating the desired burger that user is wishing to take
    Burger* createBurger(){
        if(type == "Basic")
            return new Basic_Wheat_Burger();
        else if(type == "Standard")
            return new Standard_Wheat_Burger();
        return new Premium_Wheat_Burger();
    }
};

int main(){
    Burger_Factory* myFactory1 = new SinghBurger("Basic");
    Burger* burger1 = myFactory1->createBurger();
    burger1->prepare();

    Burger_Factory* myFactory2 = new KingBurger("Basic");
    Burger* burger2 = myFactory2->createBurger();
    burger2->prepare();
    return 0;
}