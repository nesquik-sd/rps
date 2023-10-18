#include "Work_With_Files.h"

enum want_save { YES = 1, NOPE };

/// <summary>
/// Проверка имени файла на существование файла 
/// </summary>
/// <param name="filename">Имя файла</param>
/// <returns>Флаг</returns>
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
/// проверка на существование + считывание
/// </summary>
/// <returns>имя файла</returns>
string Get_Correct_Filename() { 
	string file_name = "";

	bool open_success = false;
	while (!open_success) { //проверка на наличие файла в папке

		open_success = false;

		cout << "Укажите имя файла без пробелов: " << endl;
		getline(cin, file_name);
		
		if (Bool_Check_Filename(file_name)) {
			cout << "\nФайл успешно считан" << endl;

			open_success = true;
		}

		else {
			cout << "\nНе удалось открыть файл. Попробуйте еще раз" << endl;
		}
	}

	return file_name;
}

/// <summary>
/// подсчет количества элементов в файле
/// </summary>
/// <param name="file_name"></param>
/// <returns>количество элементов</returns>
int Get_Count_Of_Elements(string file_name) { 
	ifstream file(file_name);
	int count = 0;
	int temp = 0;

	while (file >> temp) {
		count++;
	}

	return count;
}

//заполенение с файла
double* Get_Arr_From_File(string file_name, int count_of_elements) { //заполенение с файла
	ifstream file(file_name);
	double* arr;
	arr = new double[count_of_elements];

	for (int i = 0; i < count_of_elements; i++) {
		file >> arr[i];
	}

	return arr;
}

//функуия для сохранения в файл
void Save_Results(int count_of_elements, double* arr) { 
	int choose_to_save = 0;
	bool save_success = false;

	cout << "\n\n----------------------------------------" << endl;
	cout << "Хотите сохранить?" << endl;
	cout << "\t1 - да" << endl;
	cout << "\t2 - нет" << endl;
	choose_to_save = Check_Choise(2);

	switch (choose_to_save) {

		case YES: {

			do {
				save_success = true;
				int choose_to_rewrite = 0;

				cout << "Введите путь без пробелов: ";
				string file_path = " ";
				getline(cin, file_path);

				if (ifstream(file_path)) {
					cout << "Такой файл уже существует." << endl;
					cout << "\t1 - перезаписать данные в этом файле.\n\t2 - повторить ввод." << endl;

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

			cout << "Данные в файл успешно сохранены" << endl;
			delete[] arr;
			break;
		}

		case NOPE: {
			cout << "Вы не стали сохранять данные в файл" << endl;

			save_success = true;
			delete[] arr;
			break;
		}
	}
}
