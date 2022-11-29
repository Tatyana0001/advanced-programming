// Task 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <algorithm>

void SinCos(double a) {
	a = a * 3.1415926 / 180;
	std::cout << a << ": sin: " << sin(a) << " cos: " << cos(a);
}

void Print(std::vector<double> &angles, std::vector<std::function<void(double)>> functions) {
	for (const auto& angle : angles) {
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}

int main(){
    setlocale(LC_ALL, "Russian");
	std::vector<double> a = { 30,60,90 };
	std::cout << "[Входные данные]:\n";
	std::for_each(a.begin(), a.end(), [](double n) {
		std::cout << n << " * 3.1415926 / 180" << "\n";
		});
	std::cout << "[Выходные данные]:\n";
	std::vector<std::function<void(double)>> fVector;
	fVector.emplace_back(SinCos);
	Print(a, fVector);
	return 0;
}

