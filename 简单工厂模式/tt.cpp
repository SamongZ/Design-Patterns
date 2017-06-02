#include <iostream>
using namespace std;

// 运算基类
class Operation
{
public:
    Operation(const double n1, const double n2) : num1(n1), num2(n2) { }
    virtual const double getResult() = 0;
protected:
    double num1;
    double num2;
    double result;
};
// 加法
class Additon : public Operation
{
public:
    Additon(const double n1, const double n2) : Operation(n1, n2) { }
    const double getResult() override
    {
        result = num1 + num2;
        return result;
    }
};
// 减法
class Subtraction : public Operation
{
public:
    Subtraction(const double n1, const double n2) : Operation(n1, n2) { }
    const double getResult() override
    {
        result = num1 - num2;
        return result;
    }
};
// 乘法
class Multiplication : public Operation
{
public:
    Multiplication(const double n1, const double n2) : Operation(n1, n2) { }
    const double getResult() override
    {
        result = num1 * num2;
        return result;
    }
};
// 除法
class Division : public Operation
{
public:
    Division(const double n1, const double n2) : Operation(n1, n2) { }
    const double getResult() override
    {
        if (num2 == 0)
            throw "除数不能为0";
        result = num1 / num2;
        return result;
    }
};
// 简单工厂，可以产生加减乘除四种运算类，在内部进行判断
class OperationFactory
{
public:
    Operation* createOperation(const double n1, const double n2, const char symbol)
    {
        switch (symbol)
            {
            case '+' :
                return new Additon(n1, n2);
                break;
            case '-' :
                return new Subtraction(n1, n2);
                break;
            case '*' :
                return new Multiplication(n1, n2);
                break;
            case '/' :
                return new Division(n1, n2);
                break;
            }
    }
};

int main()
{
    double n1, n2;
    char sym;
    cout << "请输入第一个数：" << endl;
    cin >> n1;
    cout << "请输入运算符：" << endl;
    cin >> sym;
    cout << "请输入第二个数：" << endl;
    cin >> n2;
    OperationFactory fac;
    Operation *oper = fac.createOperation(n1, n2, sym);
    cout << n1 << " " << sym << " " << n2
         << " = " << oper -> getResult() << endl;
    return 0;
}
