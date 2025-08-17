#ifndef CONSOLE_NOTIFIER_H
#define CONSOLE_NOTIFIER_H
#include "./interfaces/IObserver.h"
#include <bits/stdc++.h>
using namespace std;

class consoleNotifier : public IObserver{
public:
    void updateMsg(string msg){
        cout<<"[Notification] "<<msg<<endl;
    }
};

#endif