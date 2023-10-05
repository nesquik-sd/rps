#include "Work_With_Files.h"

enum want_save { yes = 1, nope };

bool bool_check_filename(string filename) { //проверка имени файла на считывание с файла
	string file_path = filename;
	//error_code ec{};
	//ofstream myFile(file_path, ofstream::app);
	ifstream file(file_path.c_str());
	if (!file.is_open()) {
		//cout << "Файл не существует. Повторите ввод." << endl;
		file.close();
		return false;
	}
	else {
		//myFile.close();
		file.close();
		return true;
	}
}

string check_filename() { //проверка имени файла и считывание. 
	string file_name = "";
	bool open_success = false;
	while (!open_success) { //проверка на наличие файла в папке
		open_success = false;
		cout << "Укажите полный путь к файлу без пробелов: " << endl;
		getline(cin, file_name);
		if (bool_check_filename(file_name)) {
			cout << "\nФайл успешно считан" << endl;
			open_success = true;
			
		}
		else {
			cout << "\nНе удалось открыть файл. Попробуйте еще раз" << endl;
		}
	}
	return file_name;
	
}

int get_quanity(string file_name) { //подсчет количества элементов в файле
	ifstream file(file_name);
	int count = 0;
	int temp = 0;
	while (file >> temp) {
		count++;
	}
	return count;
}

double* matrix_from_file(string file_name, int quanity) { //заполенение с файла
	string file_path = file_name;
	ifstream file(file_name);
	double* arr;
	arr = new double[quanity];

	for (int i = 0; i < quanity; i++) {
		file >> arr[i];
	}
	return arr;
}


void save_result(int quanity, double* matrix) { //функуия для сохранения в файл
	bool success = true;
	int select = 0;
	string file_path = " ";
	int again = 0;
	success = false;
	cout << "\n\n----------------------------------------" << endl;
	cout << "Хотите сохранить?" << endl;
	cout << "\t1 - да" << endl;
	cout << "\t2 - нет" << endl;
	select = check_two_selections();
	switch (select) {
	case yes: {
		do {
			success = true;
			cout << "Введите путь без пробелов: ";

			getline(cin, file_path);
			//getline(cin, file_path);
			if (ifstream(file_path)) {
				cout << "Такой файл уже существует." << endl;
				cout << "\t1 - перезаписать данные в этом файле.\n\t2 - повторить ввод." << endl;
				again = check_two_selections();
				success = false;
			}
			ofstream myFile(file_path, ofstream::app);

			error_code ec{};
			if (!is_regular_file(file_path, ec)) {
				cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
				success = false;
			}

			else if (!myFile) {
				cout << "Запись запрещена. Повторите ввод." << endl;
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
		cout << "Данные в файл успешно сохранены" << endl;
		//delete[] array;
		break;

	}

	case nope: {
		cout << "Вы не стали сохранять данные в файл" << endl;
		success = true;
		break;
	}


	}
}
