// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template <class T>
T sqr(T a) {
    return a * a;
}

template <>
std::vector<int> sqr (std::vector <int> a) {
    for (int &n : a) {
        n = n * n;
    }
    return a;
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
    std::vector<int> c = sqr(b);
    std::cout << "[OUT]: ";
    for (int n : c) {
        std::cout << n << " ";
    }
}

