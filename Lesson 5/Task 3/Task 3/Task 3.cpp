// Task 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>

class functor {
private:
    int sum = 0;
    int count = 0;
public:
    void operator()(int i) {
        if (i % 3 == 0) {
            sum += i;
            count++;
        }
    }
    void get_sum() {
        std::cout << "[OUT]: get_sum() = " << sum << "\n";
    }
    void get_count() {
        std::cout << "[OUT]: get_count() = " << count << "\n";
    }
};

int main()
{
    std::vector <int> arr{ 4,1,3,6,25,54 };
    std::cout << "[IN]: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    functor f;
    f = std::for_each(arr.begin(), arr.end(), f);
    f.get_sum();
    f.get_count();
    return 0;
}

