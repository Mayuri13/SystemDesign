#include <bits/stdc++.h>
using namespace std;

// Singleton Class
class Singleton {
    static Singleton* instance;
    Singleton(){
        cout<<"Singleton Object created"<<endl;
    }
    public:
        static Singleton* getInstance(){
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<(s1 == s2)<<endl;
    return 0;
}