#include "Check_Func.h"

//�㭪�� ��� �஢�ન ����� 楫�� �ᥫ
int check_get_int() { 
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));
		cout << "��������, ������ �᫮: ";
	}

	while (cin.get() != '\n');
	return input;
}

//�஢�ઠ ��� ���४⭮�� ���
int Check_Choise(int count_of_action) {
	cout << "��� �롮�: "; 
	int choice = check_get_int(); //�஢�ઠ �� ���� �᫠

	while ((choice == 0) || (choice > count_of_action)) {
		cout << "������ ��ਠ�� ���. ���஡�� �� ࠧ" << endl;
		cout << "��� �롮�: ";
		choice = check_get_int();
	}

	return choice;
}