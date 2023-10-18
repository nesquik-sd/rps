#include "Work_With_Files.h"

enum want_save { YES = 1, NOPE };

/// <summary>
/// �������� ����� ����� �� ������������� ����� 
/// </summary>
/// <param name="filename">��� �����</param>
/// <returns>����</returns>
bool Bool_Check_Filename(string filename) { 
	ifstream file(filename.c_str());

	if (!file.is_open()) {
		file.close();
		return false;
	}

	else {
		file.close();
		return true;
	}
}

/// <summary>
/// �������� �� ������������� + ����������
/// </summary>
/// <returns>��� �����</returns>
string Get_Correct_Filename() { 
	string file_name = "";

	bool open_success = false;
	while (!open_success) { //�������� �� ������� ����� � �����

		open_success = false;

		cout << "������� ��� ����� ��� ��������: " << endl;
		getline(cin, file_name);
		
		if (Bool_Check_Filename(file_name)) {
			cout << "\n���� ������� ������" << endl;

			open_success = true;
		}

		else {
			cout << "\n�� ������� ������� ����. ���������� ��� ���" << endl;
		}
	}

	return file_name;
}

/// <summary>
/// ������� ���������� ��������� � �����
/// </summary>
/// <param name="file_name"></param>
/// <returns>���������� ���������</returns>
int Get_Count_Of_Elements(string file_name) { 
	ifstream file(file_name);
	int count = 0;
	int temp = 0;

	while (file >> temp) {
		count++;
	}

	return count;
}

//����������� � �����
double* Get_Arr_From_File(string file_name, int count_of_elements) { //����������� � �����
	ifstream file(file_name);
	double* arr;
	arr = new double[count_of_elements];

	for (int i = 0; i < count_of_elements; i++) {
		file >> arr[i];
	}

	return arr;
}

//������� ��� ���������� � ����
void Save_Results(int count_of_elements, double* arr) { 
	int choose_to_save = 0;
	bool save_success = false;

	cout << "\n\n----------------------------------------" << endl;
	cout << "������ ���������?" << endl;
	cout << "\t1 - ��" << endl;
	cout << "\t2 - ���" << endl;
	choose_to_save = Check_Choise(2);

	switch (choose_to_save) {

		case YES: {

			do {
				save_success = true;
				int choose_to_rewrite = 0;

				cout << "������� ���� ��� ��������: ";
				string file_path = " ";
				getline(cin, file_path);

				if (ifstream(file_path)) {
					cout << "����� ���� ��� ����������." << endl;
					cout << "\t1 - ������������ ������ � ���� �����.\n\t2 - ��������� ����." << endl;

					choose_to_rewrite = Check_Choise(2);

					save_success = false;
				}
		

				if ((choose_to_rewrite == YES) || (save_success == true) && (count_of_elements != 0)) {
					ofstream file(file_path);

					for (int i = 0; i < count_of_elements; i++) {
						file << arr[i] << " ";
					}

					file.close();
					save_success = true;
				}

			} while (!save_success);

			cout << "������ � ���� ������� ���������" << endl;
			delete[] arr;
			break;
		}

		case NOPE: {
			cout << "�� �� ����� ��������� ������ � ����" << endl;

			save_success = true;
			delete[] arr;
			break;
		}
	}
}
