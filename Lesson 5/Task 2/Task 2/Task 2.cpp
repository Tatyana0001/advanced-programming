// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template<class T>
class table {
private:
    T** tab;
    int rows, cols;
public:
    table(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        tab = new T * [rows];
        for (int i = 0; i < rows; i++) {
            tab[i] = new T[cols];
        }
    }
    table(const table&) = delete;
    table& operator=(const table&) = delete;
    T* operator[](int i) {
        return tab[i];
    }
    const T* operator[](int i) const{
        return tab[i];
    }
    T size() const {
        return rows * cols;
    }
    ~table() {
        for (int i = 0; i < rows; i++) {
            delete[] tab[i];
        }
        delete[] tab;
    }
};

int main()
{
    table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}