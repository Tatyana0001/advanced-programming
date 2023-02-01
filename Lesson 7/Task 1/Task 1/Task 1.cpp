// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
}

int main()
{
    std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    auto it = v.begin();
    while (it != v.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
    sort(v);
    std::cout << "[OUT]: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
