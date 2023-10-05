#include "Check_Func.h"

enum want_save { yes = 1, nope };
enum  FirstSelect { start = 1, unit, back };

int check_get_int() { //������� ��� �������� ����� �����
	int input = 0;

	while (!(cin >> input)) {
		cin.clear();
		while ((cin.get() != '\n'));//cin.ignore
		cout << "����������, ������� �����: ";
	}
	while (cin.get() != '\n');
	return input;
}

int check_two_selections() { //�������� ����� � ����� �������� (��������� ��� ���)
	int select;
	cout << "��� �����: ";
	select = check_get_int(); //�������� �� ���� �����
	while ((select != yes) && (select != nope)) {
		cout << "������ �������� ���. ���������� ��� ���" << endl;
		cout << "��� �����: ";
		select = check_get_int();
	}
	return select;
}

int check_three_selections() { //�������� ����� � ����� �������� (��� ������ ���������)
	int first;
	cout << "��� �����: ";
	first = check_get_int(); //�������� �� ���� �����
	while ((first != start) && (first != unit) && (first != back)) {
		cout << "������ �������� ���. ���������� ��� ���" << endl;
		cout << "��� �����: ";
		first = check_get_int();
	}
	return first;
}