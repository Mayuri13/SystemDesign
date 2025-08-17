#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <bits/stdc++.h>
using namespace std;

// Observer design pattern -> for notifying all observable users
class IObserver {
public:
    virtual void updateMsg(string msg) = 0;
};

#endif