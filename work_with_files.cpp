#include "Work_With_Files.h"

enum want_save { yes = 1, nope };

bool bool_check_filename(string filename) { //�������� ����� ����� �� ���������� � �����
	string file_path = filename;
	//error_code ec{};
	//ofstream myFile(file_path, ofstream::app);
	ifstream file(file_path.c_str());
	if (!file.is_open()) {
		//cout << "���� �� ����������. ��������� ����." << endl;
		file.close();
		return false;
	}
	else {
		//myFile.close();
		file.close();
		return true;
	}
}

string check_filename() { //�������� ����� ����� � ����������. 
	string file_name = "";
	bool open_success = false;
	while (!open_success) { //�������� �� ������� ����� � �����
		open_success = false;
		cout << "������� ������ ���� � ����� ��� ��������: " << endl;
		getline(cin, file_name);
		if (bool_check_filename(file_name)) {
			cout << "\n���� ������� ������" << endl;
			open_success = true;
			
		}
		else {
			cout << "\n�� ������� ������� ����. ���������� ��� ���" << endl;
		}
	}
	return file_name;
	
}

int get_quanity(string file_name) { //������� ���������� ��������� � �����
	ifstream file(file_name);
	int count = 0;
	int temp = 0;
	while (file >> temp) {
		count++;
	}
	return count;
}

double* matrix_from_file(string file_name, int quanity) { //����������� � �����
	string file_path = file_name;
	ifstream file(file_name);
	double* arr;
	arr = new double[quanity];

	for (int i = 0; i < quanity; i++) {
		file >> arr[i];
	}
	return arr;
}


void save_result(int quanity, double* matrix) { //������� ��� ���������� � ����
	bool success = true;
	int select = 0;
	string file_path = " ";
	int again = 0;
	success = false;
	cout << "\n\n----------------------------------------" << endl;
	cout << "������ ���������?" << endl;
	cout << "\t1 - ��" << endl;
	cout << "\t2 - ���" << endl;
	select = check_two_selections();
	switch (select) {
	case yes: {
		do {
			success = true;
			cout << "������� ���� ��� ��������: ";

			getline(cin, file_path);
			//getline(cin, file_path);
			if (ifstream(file_path)) {
				cout << "����� ���� ��� ����������." << endl;
				cout << "\t1 - ������������ ������ � ���� �����.\n\t2 - ��������� ����." << endl;
				again = check_two_selections();
				success = false;
			}
			ofstream myFile(file_path, ofstream::app);

			error_code ec{};
			if (!is_regular_file(file_path, ec)) {
				cout << "����� �������� ������������ ��������. ��������� ����." << endl;
				success = false;
			}

			else if (!myFile) {
				cout << "������ ���������. ��������� ����." << endl;
				myFile.close();
				success = false;
			}


			if ((again == 1) || (success == true) && (quanity != 0)) {
				ofstream file(file_path);
				for (int i = 0; i < quanity; i++) {
					file << matrix[i] << " ";
				}


				file.close();
				myFile.close();
				success = true;
			}
		} while (!success);
		cout << "������ � ���� ������� ���������" << endl;
		//delete[] array;
		break;

	}

	case nope: {
		cout << "�� �� ����� ��������� ������ � ����" << endl;
		success = true;
		break;
	}


	}
}
