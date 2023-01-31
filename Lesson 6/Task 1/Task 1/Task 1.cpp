// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool sort(const std::pair<char, int >& a, const std::pair< char, int >& b)
{
    return a.second > b.second;
}
int main()
{
    std::array<char,13 > arr = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '!'};
    std::cout << "[IN]: ";
    for (char i : arr) {
        std::cout << i;
    }
    std::cout << "\n";

    std::unordered_map <char, int> map;
    for (char i : arr) {
        map[i]++;
    }

    std::vector<std::pair<char, int>>vec(map.begin(), map.end());
    std::sort(vec.begin(), vec.end(), sort);
    std::cout << "[OUT]: " << std::endl;
    for (auto const& elem : vec)
    {
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
    return 0;
}

