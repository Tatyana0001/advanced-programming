// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <set>
#include <vector>

template<class T>
void print_container(std::string str, T& a) {
    std::cout << str << "\n";
    for (auto const& n : a) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container("set", test_set); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container("list", test_list); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container("vector", test_vector); 
    
    return 0;
}
