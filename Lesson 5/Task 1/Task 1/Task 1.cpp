// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template <typename T>
T sqr(T a) {
    return a * a;
}

template <typename T>
void sqr(std::vector <T> &b) {
    for (int n : b) {
        std::cout << n * n << " ";
    }
}



int main()
{
    int a = 4;
    std::vector <int> b = { -1,4,8 };
    std::cout << "[IN]: " << a << "\n";
    std::cout << "[OUT]: " << sqr(a) << "\n";
    std::cout << "[IN]: ";
    for (int n : b) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    std::cout << "[OUT]: ";
    sqr(b);
}

