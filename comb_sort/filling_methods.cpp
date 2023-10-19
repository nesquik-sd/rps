#include "Filling_Methods.h"
#include <vector>

//самостоятельно выбрать файл, с которого будет заполняться массив
vector <double> Choose_File() {
    string file_name = Get_Correct_Filename();//ввод имени 

    int count_of_elements = Get_Count_Of_Elements(file_name); //подсчет количества элементов в файле
	vector <double> arr = Get_Arr_From_File(file_name, count_of_elements);

    cout << "----------------------------------------" << endl;
    cout << "Количество элементов в массиве: " << count_of_elements << endl;
	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = arr.begin(); it != arr.end(); ++it) {
		cout << *it << " ";
	}

	return arr;

}


//заполнение массива с заданного файла (file_name)
vector <double> Fill_Auto_File() {
	string file_name = "unit_test_firts.txt";

	cout << "Данные считываются из файла: " << file_name << endl;

	int count_of_elements = Get_Count_Of_Elements(file_name);

	vector <double> arr(count_of_elements);
	arr = Get_Arr_From_File(file_name, count_of_elements);

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = arr.begin(); it != arr.end(); ++it) {
		cout << *it << " ";
	}

	return arr;

}


//заполнение с помощью слуайных чисел
vector <double>  Fill_Auto_Random() {
	cout << "Введите количество элементов - ";//заполнение массива рандомного размера рандомными числами
	int count_of_elements = Check_Get_Int();
	vector <double> arr (count_of_elements);
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = (rand() % 200 - 100)/10.0;
	}

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (vector<double>::iterator it = arr.begin(); it != arr.end(); ++it) {
		cout << *it << " ";
	}

	return arr;
}


