#include <iostream>
#include <math.h>
using namespace std;
// 计费抽象基类
class CashBase
{
public:
    virtual double acceptCash(double money) = 0;
};
// 正常收费类
class CashNormol : public CashBase
{
public:
    double acceptCash(double money) override
    {
        return money;
    }
};
// 打折类
class CashDiscount : public CashBase
{
public:
    CashDiscount(double dis) : discount(dis) { }
    double acceptCash(double money) override
    {
        return money * discount;
    }
private:
    double discount = 0.0;
};
// 满减类
class CashReturn : public CashBase
{
public:
    CashReturn(double mC, double mR) : moneyCondition(mC), moneyReturn(mR) { }
    double acceptCash(double money) override
    {
        if (money >= moneyCondition)
            return money - floor(money / moneyCondition) * moneyReturn;
        else
            return money;
    }
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
};
// 策略模式与简单工厂模式的结合，在CashContext类内进行判断
class CashContext
{
public:
    CashContext(const char option)
    {
        switch(option)
        {
        case '1':
            cb = new CashNormol;
            break;
        case '2':
            cb = new CashDiscount(0.8);
            break;
        case '3':
            cb = new CashReturn(200, 100);
            break;
        }
    }
    ~CashContext() { delete cb; }
    double getTotalPrice(double money)
    {
        return cb -> acceptCash(money);
    }
private:
    CashBase* cb = nullptr;
};

int main()
{
    unsigned numOfbooks;
    double price;
    char option;
    cout << "请输入书本单价：" << endl;
    cin >> price;
    cout << "请输入购买数量：" << endl;
    cin >> numOfbooks;
    cout << "请选择计价方式：" << endl;
    cout << "1、原价" << endl;
    cout << "2、打8折" << endl;
    cout << "3、满200减100" << endl;
    cin >> option;
    CashContext cc(option);
    cout << cc.getTotalPrice(price * numOfbooks);
    return 0;
}
