// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class smart_array {
private:
	int size=0, size2=0;
	int elem=0;
	int* arr;
	int i = 0;
public:
	smart_array(int a) {
		this->size = a;
		arr = new int[size];
	}
	void add_element(int a) {
		this->elem = a;
		if (i < size) {
			arr[i] = elem;
			i++;
		}
		else {
			throw std::runtime_error("The number of elements is greater than the number of array elements");
		}
	}
	int get_element(int a) {
		this->size2 = a;
		if (size2 < size && size2 >= 0) {
			return arr[size2];
		}
		else {
			throw std::runtime_error("There is no element with such an index in this array");
		}
	}
	~smart_array() {
		delete[] arr;
	}
};


int main()
{

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
