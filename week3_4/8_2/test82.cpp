#include "iostream"

template<typename T> T CalcAbs(T val);

int main(int argc, char * argv[])
{
    std::cout << CalcAbs(-5.4) << "\n";
    std::cout << CalcAbs(0) << "\n";
    std::cout << CalcAbs(-8) << "\n";
    std::cout << CalcAbs(42) << "\n";
    std::cout << CalcAbs(42.8) << "\n";

    return 0;
}

template<typename T> T CalcAbs(T val) {
    T result;

    if (val < 0)
    {
        result = -val;
    }
    else
    {
        result = val;
    }
    return result;
}

