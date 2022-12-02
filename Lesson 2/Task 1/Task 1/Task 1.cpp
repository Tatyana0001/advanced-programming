// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct point {
	int m_x;
	int m_y;
	point(int x, int y) {
		this->m_x = x;
		this->m_y = y;
	}
};

void print_point(point& my_point) {
	std::cout << "x: " << my_point.m_x << ", y: " << my_point.m_y << std::endl;
}

int main()
{
	int i;
	for (i = 0; i < 5; i++) {
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

