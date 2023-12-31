#include "Comb_Sort.h"
#include "Work_With_Files.h"
#include <vector>

/// <summary>
/// реализация сортировки расческой
/// </summary>
/// <param name="vect"></param>
/// <returns>отсортированный вектор</returns>
vector <double> Comb_Sort (vector <double> vect){ 
	int count_of_elements = vect.size();
	int step = count_of_elements;//начальный шаг = количеству элементов в массиве / 1,2, 
	int count_permutation = 0; // количество перестановок
	int count_comparisons = 0; //количество сравнений
	cout << "\n" << endl;

	while (step != 1) {

		step = int(step / 1.247); //чтобы сравнивать 1 и n-2 элемент (80%), 2 и n-1, 3 и n, чтобы отправить самые большие числа сразу в конец

		if (step < 1) { //Так мы уменьшаем размер шага до тех пор, пока он не станет меньше единицы — к этому моменту массив будет полностью отсортирован.
			step = 1;
		}

		for (int i = 0; i < (count_of_elements - step); i++) {
			count_comparisons++;

			if (vect[i] > vect[i + step]) {
				swap(vect[i], vect[i + step]);
				count_permutation++;
			}
		}
	}

	cout << "Количество перестановок - " << count_permutation << endl;
	cout << "Количество сравнений - " << count_comparisons << endl;

	cout << "\nОтсортированный массив: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << vect[i] << " ";
	}

	return vect;
}

