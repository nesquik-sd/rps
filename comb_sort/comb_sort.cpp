#include "Comb_Sort.h"
#include "Work_With_Files.h"
double* comb_sort (double* arr, int count_of_elements){ //���������� ���������� ��������� 
	int step = count_of_elements;//��������� ��� = ���������� ��������� � ������� / 1,2, 
	int count_permutation = 0;
	int count_comparisons = 0;
	cout << "\n" << endl;

	while (step != 1) {

		step = int(step / 1.247); //����� ���������� 1 � n-2 ������� (80%), 2 � n-1, 3 � n, ����� ��������� ����� ������� ����� ����� � �����

		if (step < 1) { //��� �� ��������� ������ ���� �� ��� ���, ���� �� �� ������ ������ ������� � � ����� ������� ������ ����� ��������� ������������.
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

	cout << "���������� ������������ - " << count_permutation << endl;
	cout << "���������� ��������� - " << count_comparisons << endl;

	return arr;
}

