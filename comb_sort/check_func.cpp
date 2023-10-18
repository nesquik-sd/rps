#include "Check_Func.h"

//функция для проверки ввода целых чисел
int check_get_int() { 
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));
		cout << "Пожалуйста, введите число: ";
	}

	while (cin.get() != '\n');
	return input;
}

//проверка для корректности выбра
int Check_Choise(int count_of_action) {
	cout << "Ваш выбор: "; 
	int choice = check_get_int(); //проверка на ввод числа

	while ((choice == 0) || (choice > count_of_action)) {
		cout << "Такого варианта нет. Попробуйте еще раз" << endl;
		cout << "Ваш выбор: ";
		choice = check_get_int();
	}

	return choice;
}