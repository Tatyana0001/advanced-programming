// Task 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<class T>
class unique_ptr
{
private:
    T* ptr;
public:
    unique_ptr(T* arr) : ptr(arr) {}
    T& operator*() { return *ptr; }
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    T release() {
        T* ptr2 = ptr;
        ptr = nullptr;
        return ptr2;
    }
    ~unique_ptr() {
        delete ptr;
        std::cout << "destructor called\n";
    }
};


int main() {
    int* arr = new int[100];
    unique_ptr<int> my_ptr(arr);
    return 0;
} 