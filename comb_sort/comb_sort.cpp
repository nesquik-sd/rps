#include "Comb_Sort.h"
#include "Work_With_Files.h"
double* comb_sort (double* arr, int count_of_elements){ //реализаци€ сортировки расческой 
	int step = count_of_elements;//начальный шаг = количеству элементов в массиве / 1,2, 
	int count_permutation = 0;
	int count_comparisons = 0;
	cout << "\n" << endl;

	while (step != 1) {

		step = int(step / 1.247); //чтобы сравнивать 1 и n-2 элемент (80%), 2 и n-1, 3 и n, чтобы отправить самые большие числа сразу в конец

		if (step < 1) { //“ак мы уменьшаем размер шага до тех пор, пока он не станет меньше единицы Ч к этому моменту массив будет полностью отсортирован.
			step = 1;
		}

		for (int i = 0; i < (count_of_elements - step); i++) {
			count_comparisons++;

			if (arr[i] > arr[i + step]) {
				swap(arr[i], arr[i + step]);
				count_permutation++;
			}

		}
			
	}

	cout << " оличество перестановок - " << count_permutation << endl;
	cout << " оличество сравнений - " << count_comparisons << endl;

	return arr;
}

