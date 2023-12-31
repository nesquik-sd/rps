#include "Check_Func.h"

/// <summary>
/// функция для проверки ввода целых чисел
/// </summary>
/// <returns>ввод</returns>
int Check_Get_Int() { 
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));
		cout << "Пожалуйста, введите число: ";
	}

	while (cin.get() != '\n');
	return input;
}

/// <summary>
/// проверка для корректности выбра
/// </summary>
/// <param name="count_of_action"></param>
/// <returns>проверенный выбор</returns>
int Check_Choise(int count_of_action) {
	cout << "Ваш выбор: "; 
	int choice = Check_Get_Int(); //проверка на ввод числа

	while ((choice == 0) || (choice > count_of_action)) {
		cout << "Такого варианта нет. Попробуйте еще раз" << endl;
		cout << "Ваш выбор: ";
		choice = Check_Get_Int();
	}

	return choice;
}