#include <iostream>
using namespace std;

// Product
class Animal {
public:
    virtual void speak() = 0;
};

// Concrete Products
class Dog : public Animal {
public:
    void speak() override { cout << "Woof!" << endl; }
};
class Bird : public Animal {
public:
    void speak() override { cout << "Chirp!" << endl; }
};

// Factory
class AnimalFactory {
public:
    static Animal* createAnimal(string type) {
        if(type == "Dog") return new Dog();
        if(type == "Bird") return new Bird();
        return nullptr;
    }
};

int main() {
    Animal* a1 = AnimalFactory::createAnimal("Dog");   // Factory decides
    a1->speak();  // Woof!

    Animal* a2 = AnimalFactory::createAnimal("Bird");  
    a2->speak();  // Chirp!
}
