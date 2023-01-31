// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>


int main()
{
    int size = 0;
    int elem;
    std::cout << "[IN]: \n";
    std::cin >> size;
    std::list<int> arr;
    for (int i = 0; i < size; i++) {
        std::cin >> elem;
        arr.push_back(elem);
    }
    std::cout << "[OUT]: \n";
    arr.sort();
    arr.unique();
    for (const auto& el : arr) {
        std::cout << el << "\n";
    }
    return 0;
}

    
    
