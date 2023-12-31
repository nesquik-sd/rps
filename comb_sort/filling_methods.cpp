#include "Filling_Methods.h"
#include <vector>

/// <summary>
/// самостоятельно выбрать файл, с которого будет заполняться массив
/// </summary>
/// <returns>заполненный вектор</returns>
vector <double> Choose_File() {
    string file_name = Get_Correct_Filename();//ввод имени файла

    int count_of_elements = Get_Count_Of_Elements(file_name); //подсчет количества элементов в файле
	vector <double> vect = Get_Vector_From_File(file_name, count_of_elements); //заполнение вектора с файла

    cout << "----------------------------------------" << endl;
    cout << "Количество элементов в массиве: " << count_of_elements << endl;
	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = vect.begin(); it != vect.end(); ++it) { //вывод исходного вектора
		cout << *it << " ";
	}

	return vect;

}


/// <summary>
/// заполнение массива с заданного файла (file_name)
/// </summary>
/// <returns>заполненный вектор</returns>
vector <double> Fill_Auto_File() {
	string file_name = "unit_test_firts.txt"; //заранее выбранный файл для сортировки

	cout << "Данные считываются из файла: " << file_name << endl;

	int count_of_elements = Get_Count_Of_Elements(file_name); //подсчет количества элементов в файле

	vector <double> vect(count_of_elements);
	vect = Get_Vector_From_File(file_name, count_of_elements); //заполнение вектора с файла

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = vect.begin(); it != vect.end(); ++it) {
		cout << *it << " ";
	}

	return vect;

}


/// <summary>
/// заполнение с помощью слуайных чисел
/// </summary>
/// <returns>заполненный вектор</returns>
vector <double>  Fill_Auto_Random() {
	cout << "Введите количество элементов - ";
	int count_of_elements = Check_Get_Int(); //количество элементов ввод

	vector <double> vect (count_of_elements);

	for (int i = 0; i < vect.size(); i++) {
		vect[i] = (rand() % 200 - 100)/10.0; 
	}

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = vect.begin(); it != vect.end(); ++it) {
		cout << *it << " ";
	}

	return vect;
}