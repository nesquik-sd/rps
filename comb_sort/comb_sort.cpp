#include "Comb_Sort.h"
double* comb_sort (double* arr, int quanity){ //реализация сортировки расческой 
	int step = quanity;//начальный шаг = количеству элементов в массиве / 1,2, 
	int count = 0;
	int comparisons = 0;
	cout << "\n" << endl;

	while (step != 1) {
		step = int(step / 1.247); //чтобы сравнивать 1 и n-2 элемент (80%), 2 и n-1, 3 и n, чтобы отправить самые большие числа сразу в конец
		if (step < 1) { //Так мы уменьшаем размер шага до тех пор, пока он не станет меньше единицы — к этому моменту массив будет полностью отсортирован.
			step = 1;
		}
		for (int i = 0; i < (quanity - step); i++) {

			comparisons++;
			if (arr[i] > arr[i + step]) {
				swap(arr[i], arr[i + step]);
				count++;
			}
		}
		
		
	}
	cout << "\n----------------------------------------" << endl;
	cout << "Количество перестановок - " << count << endl;
	cout << "Количество сравнений - " << comparisons << endl;

	return arr;

}

void unit_test() {
	int quanity = 0;
	double* arr;
	arr = new double[quanity];
	double* sorted_arr;
	sorted_arr = new double[quanity];
	string file_name = "unit_test_firts.txt";

	cout << "Данные считываются из файла: " << file_name << endl;
	quanity = get_quanity(file_name);
	arr = matrix_from_file(file_name, quanity);

	cout << "----------------------------------------" << endl;
	cout << "Количество элементов в массиве: " << quanity << endl;
	cout << "----------------------------------------" << endl;
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < quanity; i++) {
		cout << arr[i] << " ";
	}
	sorted_arr = comb_sort(arr, quanity);

	cout << "\n----------------------------------------" << endl;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < quanity; i++) {
		cout << sorted_arr[i] << " ";
	}

	save_result(quanity, sorted_arr);
}