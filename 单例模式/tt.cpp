#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* getSingleton();
private:
    Singleton() { }
    static Singleton *singleton;
};

Singleton* Singleton::singleton = nullptr;
Singleton* Singleton::getSingleton() {
    if (singleton == nullptr)
        singleton = new Singleton();
    return singleton;
}

int main()
{
    Singleton *p1 = Singleton::getSingleton();
    Singleton *p2 = Singleton::getSingleton();
    if (p1 == p2)
        cout << "p1 and p2 are same" << endl;
    else
        cout << "p1 and p2 are different" << endl;
    return 0;
}
