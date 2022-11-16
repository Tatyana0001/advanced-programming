// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> v = { 4, 7, 9, 14, 12 };
    std::cout << "Входные данные: ";
    for (int n : v) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    std::cout << "Выходные данные: ";
    std::for_each(v.begin(), v.end(), [](int n) {
        if (n % 2 == 1) { n *= 3; }
        std::cout << n << " "; });
    std::cout << "\n";
    return 0;
}


