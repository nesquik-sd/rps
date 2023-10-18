#include "Filling_Methods.h"

//самостоятельно выбрать файл, с которого будет заполняться массив
void Choose_File() {
    string file_name = Get_Correct_Filename();//ввод имени файла

    int count_of_elements = Get_Count_Of_Elements(file_name); //подсчет количества элементов в файле

    double* arr = new double[count_of_elements]; //выделяем память
    arr = Get_Arr_From_File(file_name, count_of_elements); //заполенение 

    cout << "----------------------------------------" << endl;
    cout << "Количество элементов в массиве: " << count_of_elements << endl;

    cout << "----------------------------------------" << endl;
    cout << "Исходный массив: " << endl;
    for (int i = 0; i < count_of_elements; i++) {
        cout << arr[i] << " ";
    }

	double* sorted_arr = new double[count_of_elements]; //выделяем память
    sorted_arr = comb_sort(arr, count_of_elements); //сортируем массив

    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < count_of_elements; i++) {
        cout << sorted_arr[i] << " ";
    }

    Save_Results(count_of_elements, sorted_arr); //возможность сохранить
}


//заполнение массива с заданного файла (file_name)
void Fill_Auto_File() {
	string file_name = "unit_test_firts.txt";

	cout << "Данные считываются из файла: " << file_name << endl;

	int count_of_elements = Get_Count_Of_Elements(file_name);
	double* arr = new double[count_of_elements];
	arr = Get_Arr_From_File(file_name, count_of_elements);
	for (int i = 0; i < count_of_elements; i++) {
		arr[i] = rand() % 200 - 100;
	}

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << arr[i] << " ";
	}

	double* sorted_arr = new double[count_of_elements];
	sorted_arr = comb_sort(arr, count_of_elements);

	cout << "\nОтсортированный массив: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << sorted_arr[i] << " ";
	}
	
	Save_Results(count_of_elements, sorted_arr);
}


//заполнение с помощью слуайных чисел
void Fill_Auto_Random() {
	int count_of_elements = 3 + rand() % 20;
	double* arr = new double[count_of_elements];
	for (int i = 0; i < count_of_elements; i++) {
		arr[i] = (rand() % 200 - 100)/10.0;
	}

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << count_of_elements << endl;

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << arr[i] << " ";
	}

	double* sorted_arr = new double[count_of_elements];
	sorted_arr = comb_sort(arr, count_of_elements);

	cout << "\nОтсортированный массив: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << sorted_arr[i] << " ";
	}

	Save_Results(count_of_elements, sorted_arr);
}