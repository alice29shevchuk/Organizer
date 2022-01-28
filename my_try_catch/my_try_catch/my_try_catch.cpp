#include <iostream>
#include<exception>
using namespace std;
class MyException : public std::exception
{
    int value;
public:
    MyException(const char* msg, int value) : std::exception(msg)
    {
        this->value = value;
    }
    int getValue()
    {
        return this->value;
    }
};
class Myclass
{
    int a;
public:
    Myclass(int a)
    {
        if (a > 20)
        {
            throw MyException("Value > 20!!!", a);
        }
        this->a = a;
    }
};
int main()
{
    try
    {
        Myclass mc(33);
        std::cout << "Good!!";
    }
    catch (MyException& ex)
    {
        std::cout << ex.what() << std::endl;
        std::cout << ex.getValue() << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();
    }
}