#include "Check_Func.h"

//������� ��� �������� ����� ����� �����
int check_get_int() { 
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));
		cout << "����������, ������� �����: ";
	}

	while (cin.get() != '\n');
	return input;
}

//�������� ��� ������������ �����
int Check_Choise(int count_of_action) {
	cout << "��� �����: "; 
	int choice = check_get_int(); //�������� �� ���� �����

	while ((choice == 0) || (choice > count_of_action)) {
		cout << "������ �������� ���. ���������� ��� ���" << endl;
		cout << "��� �����: ";
		choice = check_get_int();
	}

	return choice;
}