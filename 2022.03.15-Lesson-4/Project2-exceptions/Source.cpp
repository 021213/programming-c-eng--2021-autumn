#include <iostream>

void nothrow() throw()
{

}

void last() throw(int)
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";
    nothrow();
    throw -1;
    std::cout << "End last\n";

}

void three()
{
    std::cout << "Start three\n";
    last();
    std::cout << "End three\n";
}

void two()
{
    std::cout << "Start two\n";
    try
    {
        three();
    }
    catch (double)
    {
        std::cerr << "two caught double exception\n";
    }
    std::cout << "End two\n";
}

void one() throw(...)
{
    std::cout << "Start one\n";
    try
    {
        two();
    }
    catch (int)
    {
        std::cerr << "one caught int exception\n";
    }
    catch (double)
    {
        std::cerr << "one caught double exception\n";
    }
    std::cout << "End one\n";
}

int main()
{
    std::cout << "Start main\n";
    try
    {
        one();
    }
    catch (int)
    {
        std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}
/*
throw -1; // int
throw ENUM_INVALID_INDEX; // enum
throw "Can not take square root of negative number"; // const char* (C-style string)
throw dX; //double
throw MyException("Fatal Error");
std::exception
*/