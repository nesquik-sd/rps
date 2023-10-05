#include "Check_Func.h"

enum want_save { yes = 1, nope };
enum  FirstSelect { start = 1, unit, back };

int check_get_int() { //функция для проверки ввода чисел
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));//cin.ignore
		cout << "Пожалуйста, введите число: ";
	}
	while (cin.get() != '\n');
	return input;
}

int check_two_selections() { //проверка ввода с двумя выборами (сохранить или нет)
	int select;
	cout << "Ваш выбор: ";
	select = check_get_int(); //проверка на ввод числа
	while ((select != yes) && (select != nope)) {
		cout << "Такого варианта нет. Попробуйте еще раз" << endl;
		cout << "Ваш выбор: ";
		select = check_get_int();
	}
	return select;
}

int check_three_selections() { //проверка ввода с тремя выборами (для начала программы)
	int first;
	cout << "Ваш выбор: ";
	first = check_get_int(); //проверка на ввод числа
	while ((first != start) && (first != unit) && (first != back)) {
		cout << "Такого варианта нет. Попробуйте еще раз" << endl;
		cout << "Ваш выбор: ";
		first = check_get_int();
	}
	return first;
}