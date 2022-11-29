// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;
	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}

	if (std::holds_alternative<int>(result)) {
		std::cout << (std::get<int>(result) * 2) << "\n";
	}
	if (std::holds_alternative<std::string>(result)) {
		std::cout << std::get<std::string>(result) << "\n";
	}
	if (std::holds_alternative<std::vector<int>>(result)) {
		for (int n : std::get<std::vector<int>>(result)) {
			std::cout << n << " ";
		}
		std::cout << "\n";
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	get_variant();
	return 0;
}


