#include <iostream>
#include <string>
using namespace std;

// 公共类
class Person
{
public:
    Person() { }
    virtual ~Person() { }
    virtual void show() { }
};
// 男人类
class Man : public Person
{
public:
    Man(string s) : name(s) { }
    ~Man() { }
    void show()
    {
        cout << name << "的装扮：" << endl;
    }
private:
    string name;
};
// 女人类
class Woman : public Person
{
public:
    Woman(string s) : name(s) { }
    ~Woman() { }
    void show()
    {
        cout << name << "的装扮：" << endl;
    }
private:
    string name;
};
// 装饰类
class Decorator : public Person
{
public:
    Decorator(Person *p) : per(p) { }
    ~Decorator() { }
    void show()
    {
        per -> show();
    }
protected:
    Person *per;
};
// 具体的装饰类
class DecoratorA : public Decorator
{
public:
    DecoratorA(Person *p) : Decorator(p) { }
    ~DecoratorA() { }
    void show()
    {
        per -> show();
        cout << "穿运动装" << endl;
    }
};
class DecoratorB : public Decorator
{
public:
    DecoratorB(Person *p) : Decorator(p) { }
    ~DecoratorB() { }
    void show()
    {
        per -> show();
        cout << "戴帽子" << endl;
    }
};

int main()
{
    Person *p = new Man("小明");
    DecoratorA *da = new DecoratorA(p);
    DecoratorB *db = new DecoratorB(da);
    db -> show();
    delete db;
    delete da;
    delete p;
    return 0;
}
