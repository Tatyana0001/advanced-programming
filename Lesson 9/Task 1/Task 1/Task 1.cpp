// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template <class T>
std::vector<std::string> move_vectors(T& two, T&& one) {
    two = std::move(one);
    return one, two;
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(two, std::move(one));
    return 0;
}