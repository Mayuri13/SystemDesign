#include <bits/stdc++.h>
using namespace std;

// Strategy Interface for walk
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// Conceret strategies for walk
class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout<<"Walking Normally..."<<endl;
    }
};

// Conceret strategies for walk
class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout<<"Cannot Walk..."<<endl;
    }
};


// Strategy Interface for crawl
class CrawlableRobot{
public: 
    virtual void crawl() = 0;
    virtual ~CrawlableRobot() {}
};

// Concrete strategies for crawl
class NormalCrawl : public CrawlableRobot {
public:
    void crawl() {
        cout<<"Normal Crawl..."<<endl;
    }
};

// Concrete strategies for crawl
class NoCrawl : public CrawlableRobot {
public:
    void crawl() {
        cout<<"Cannot Crawl..."<<endl;
    }
};


// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};


// Robot Base Class
class Robot {
protected:
    WalkableRobot* walkBehaviour;
    CrawlableRobot* crawlBehaviour;
    FlyableRobot* flyBehaviour;

public:
    Robot(WalkableRobot* w, CrawlableRobot* c, FlyableRobot* f){
        this->walkBehaviour = w;
        this->crawlBehaviour = c;
        this->flyBehaviour = f;
    }

    void walk() {
        walkBehaviour->walk();
    }
    void crawl() {
        crawlBehaviour->crawl();
    }
    void fly() {
        flyBehaviour->fly();
    }

    void setWalkBehavior(WalkableRobot* w){
        this->walkBehaviour = w;
    }

    virtual void projection() = 0; //Abstract class for subclasses
};

// Concrete Robot Classes
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, CrawlableRobot* c, FlyableRobot* f) : Robot(w, c, f){};

    void projection() override {
        cout<<"Displaying friendly companion fetaures..."<<endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, CrawlableRobot* c, FlyableRobot* f) : Robot(w, c, f){};

    void projection() override {
        cout<<"Displaying worker efficiency fetaures..."<<endl;
    }
};

int main(){
    Robot* robot1 = new CompanionRobot(new NoWalk(), new NormalCrawl(), new NormalFly());
    robot1->walk();
    robot1->crawl();
    robot1->fly();
    robot1->projection();
    
    // Changing walk behavior in real time
    robot1->setWalkBehavior(new NormalWalk());
    robot1->walk();

    Robot* robot2 = new WorkerRobot(new NormalWalk(), new NoCrawl(), new NoFly());
    robot2->walk();
    robot2->crawl();
    robot2->fly();
    robot2->projection();
    return 0;
}