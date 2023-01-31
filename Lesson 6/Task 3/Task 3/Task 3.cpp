// Task 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <class T>
class vector {
private:
    T* arr;
    int arr_size = 0;
    int arr_capacity = 1;
public:
    vector() {
        arr = new T [arr_capacity];
    }
    T at(int index) {
        if (index < 0) {
            throw std::runtime_error("Элемента с таким индексом не существует!");
        }else if (index > arr_size - 1) {
            throw std::runtime_error("Элемента с таким индексом не существует!");
        }
        else { return arr[index]; }
    }
    vector(const vector& other) {
        arr_size = other.arr_size;
        arr = new int[arr_size];
        for (int j = 0; j < arr_size; j++) {
            arr[j] = other.arr[j];
        }
    }
    vector& operator=(const vector& other) {
        if (&other != this) {
            delete[] arr;
            arr_size = other.arr_size;
            arr = new int[arr_size];
            for (int i = 0; i < arr_size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    void push_back(T value) {
        if (arr_size == arr_capacity) {
            arr_capacity *= 2;
            T* arr2 = arr;
            arr = new T[arr_capacity];
            for (int i = 0; i < arr_size; i++) {
                arr[i] = arr2[i];
            } delete[] arr2;
        }
        arr[arr_size] = value;
        arr_size++;
    }
    int size() {
        return arr_size;
    }
    int capacity() {
        return arr_capacity;
    }
    ~vector() {
        delete[] arr;
    }
};

int main()
{
    try {
        setlocale(LC_ALL, "Russian");
        vector<int> v;
        v.push_back(7);
        std::cout << "v[0]: " << v.at(0) << "\n";
        std::cout << "Размер: " << v.size() << "\n";
        std::cout << "Вместимость: " << v.capacity() << "\n";
        v.push_back(13);
        std::cout << "v[1]: " << v.at(1) << "\n";
        std::cout << "Размер: " << v.size() << "\n";
        std::cout << "Вместимость: " << v.capacity() << "\n";
        v.push_back(1);
        v.push_back(3);
        v.push_back(9);
        v.push_back(8);
        v.push_back(22);
        std::cout << "v[3]: " << v.at(3) << "\n";
        std::cout << "v[" << v.size() << "]: " << v.at(v.size()-1) << "\n";
        std::cout << "Размер: " << v.size() << "\n";
        std::cout << "Вместимость: " << v.capacity() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
