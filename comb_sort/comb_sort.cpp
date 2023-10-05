#include "Comb_Sort.h"
double* comb_sort (double* arr, int quanity){ //���������� ���������� ��������� 
	int step = quanity;//��������� ��� = ���������� ��������� � ������� / 1,2, 
	int count = 0;
	int comparisons = 0;
	cout << "\n" << endl;

	while (step != 1) {
		step = int(step / 1.247); //����� ���������� 1 � n-2 ������� (80%), 2 � n-1, 3 � n, ����� ��������� ����� ������� ����� ����� � �����
		if (step < 1) { //��� �� ��������� ������ ���� �� ��� ���, ���� �� �� ������ ������ ������� � � ����� ������� ������ ����� ��������� ������������.
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
	cout << "���������� ������������ - " << count << endl;
	cout << "���������� ��������� - " << comparisons << endl;

	return arr;

}

void unit_test() {
	int quanity = 0;
	double* arr;
	arr = new double[quanity];
	double* sorted_arr;
	sorted_arr = new double[quanity];
	string file_name = "unit_test_firts.txt";

	cout << "������ ����������� �� �����: " << file_name << endl;
	quanity = get_quanity(file_name);
	arr = matrix_from_file(file_name, quanity);

	cout << "----------------------------------------" << endl;
	cout << "���������� ��������� � �������: " << quanity << endl;
	cout << "----------------------------------------" << endl;
	cout << "�������� ������: " << endl;
	for (int i = 0; i < quanity; i++) {
		cout << arr[i] << " ";
	}
	sorted_arr = comb_sort(arr, quanity);

	cout << "\n----------------------------------------" << endl;
	cout << "��������������� ������: " << endl;
	for (int i = 0; i < quanity; i++) {
		cout << sorted_arr[i] << " ";
	}

	save_result(quanity, sorted_arr);
}