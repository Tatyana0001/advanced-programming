// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
//#include <utility>
#include<algorithm>

class big_integer {
private:
    std::vector<int> arr;
    friend std::ostream& operator<< (std::ostream&, big_integer&);
public:
    big_integer() = default;
    big_integer(std::string a) {
        for (int i = a.size() - 1; i >= 0; i--) {
            arr.push_back(a[i]-'0');
        }
    }
    big_integer(big_integer&& other) noexcept {
        arr = std::move(other.arr);
    }
    big_integer(big_integer& other) {
        *this = other;
    }
    big_integer& operator=(big_integer& other) {
        arr = other.arr;
        return *this;
    }
    big_integer& operator=(big_integer&& other) noexcept {
        std::swap(arr, other.arr);
        return *this;
    }
    big_integer operator+(const big_integer& other) {
        big_integer res;
        int r1 = std::min(arr.size(), other.arr.size()); 
        res.arr.resize(r1); 
        int k = 0;
        for (int i = 0; i < r1; i++) {
            res.arr[i] = arr[i] + k + other.arr[i];
            k = 0;
            if (res.arr[i] >= 10) {
                res.arr[i] = res.arr[i] - 10;
                k = 1;
            }
        }
        for (int i = r1; i < arr.size(); i++) {
            res.arr.push_back(arr[i]);
        }
        for (int i = r1; i < other.arr.size(); i++) {
            res.arr.push_back(other.arr[i]);
        }
        std::reverse(res.arr.begin(), res.arr.end());
        return res;
    };
    big_integer operator*(const int& x) {
        big_integer mult;
        mult.arr.resize(arr.size());
        int k = 0;
            for(int i=0;i<arr.size();i++){
            mult.arr[i] = (arr[i] * x) + k;
            k = 0;
            if ((mult.arr[i] >= 10) && (i != arr.size() - 1)) {
                k = mult.arr[i] / 10;
                mult.arr[i] = mult.arr[i] % 10;
            }
        }
        std::reverse(mult.arr.begin(), mult.arr.end());
        return mult;
    }
};

std::ostream& operator<< (std::ostream& os, big_integer& a) {
    for (const auto& i : a.arr) {
        os << i;
    }
    return os;
}


int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << "\n"; // 193099
    auto mult = number1 * 7; 
    std::cout << mult << "\n"; // 802025
    return 0;
}