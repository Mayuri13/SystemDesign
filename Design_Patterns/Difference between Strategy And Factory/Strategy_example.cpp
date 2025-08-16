#include <bits/stdc++.h>
using namespace std;

// Abstract Behavioral class
class speakBehavior {
public:
    virtual void speak() = 0;
};

// Concrete Class ->Bark Behaviour
class Bark : public speakBehavior {
public:
    void speak(){
        cout<<"Dog is Barking..."<<endl;
    }
};

// Concrete Class -> Chirp Behaviour
class Chirp : public speakBehavior {
public:
    void speak(){
        cout<<"Bird is Chirping..."<<endl;
    }
};

// Base Class
class Animal {
    speakBehavior* sBehaviour;
public:
    Animal(speakBehavior* sb){
        this->sBehaviour = sb;
    }
    void speak(){
        sBehaviour->speak();
    }
    void setBehaviour(speakBehavior* sb) {
        this->sBehaviour = sb;
    }
};

int main(){
    Animal* myAnimal = new Animal(new Bark());
    myAnimal->speak();

    myAnimal->setBehaviour(new Chirp());
    myAnimal->speak();
    return 0;
}