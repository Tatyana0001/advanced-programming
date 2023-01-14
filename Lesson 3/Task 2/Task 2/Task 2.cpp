// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class smart_array {
private:
	int size = 0;
	int* arr;
	int i = 0;
public:
		smart_array(int a) {
		this->size = a;
		arr = new int[size];
	}
	void add_element(int a) {
		if (i < size) {
			arr[i] = a;
			i++;
		}
		else {
			throw std::runtime_error("The number of elements is greater than the number of array elements");
		}
	}
	int get_element(int a) {
		if (a < i && a >= 0) {
			return arr[a];
		}
		else {
			throw std::runtime_error("There is no element with such an index in this array");
		}
	}
	smart_array(const smart_array& other) {
		arr = new int(*other.arr);
	}
	smart_array &operator=(const smart_array& other) {
		if (&other != this) {
			delete[] arr;
			size = other.size;
			arr = new int[size];
			for (int i = 0; i < size; i++) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		
		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}