#include <bits/stdc++.h>
using namespace std;

// Singleton Class
class Singleton {
    static Singleton* instance;
    static mutex mtx;
    Singleton(){
        cout<<"Singleton Object created"<<endl;
    }
    public:
        static Singleton* getInstance(){
            if(instance == nullptr){
                // 2 threads can enter till this place, but only one of them will get entry at line no.16
                lock_guard<mutex> lock(mtx);
                /*
                But once the instance is created and lock is unlocked the 2nd thread will again try to enter 
                line no.20 and Singleton concept will break, so double if(instance == nullptr) check is req.
                */ 
                if(instance == nullptr)
                    instance = new Singleton();
            }
            return instance;
        }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<(s1 == s2)<<endl;
    return 0;
}