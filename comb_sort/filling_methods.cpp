#include "Filling_Methods.h"

//�������������� ������� ����, � �������� ����� ����������� ������
void Choose_File() {
    string file_name = Get_Correct_Filename();//���� ����� �����

    int count_of_elements = Get_Count_Of_Elements(file_name); //������� ���������� ��������� � �����

    double* arr = new double[count_of_elements]; //�������� ������
    arr = Get_Arr_From_File(file_name, count_of_elements); //����������� 

    cout << "----------------------------------------" << endl;
    cout << "���������� ��������� � �������: " << count_of_elements << endl;

    cout << "----------------------------------------" << endl;
    cout << "�������� ������: " << endl;
    for (int i = 0; i < count_of_elements; i++) {
        cout << arr[i] << " ";
    }

	double* sorted_arr = new double[count_of_elements]; //�������� ������
    sorted_arr = comb_sort(arr, count_of_elements); //��������� ������

    cout << "��������������� ������: " << endl;
    for (int i = 0; i < count_of_elements; i++) {
        cout << sorted_arr[i] << " ";
    }

    Save_Results(count_of_elements, sorted_arr); //����������� ���������
}


//���������� ������� � ��������� ����� (file_name)
void Fill_Auto_File() {
	string file_name = "unit_test_firts.txt";

	cout << "������ ����������� �� �����: " << file_name << endl;

	int count_of_elements = Get_Count_Of_Elements(file_name);
	double* arr = new double[count_of_elements];
	arr = Get_Arr_From_File(file_name, count_of_elements);
	for (int i = 0; i < count_of_elements; i++) {
		arr[i] = rand() % 200 - 100;
	}

	cout << "----------------------------------------" << endl;
	cout << "���������� ��������� � �������: " << count_of_elements << endl;

	cout << "�������� ������: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << arr[i] << " ";
	}

	double* sorted_arr = new double[count_of_elements];
	sorted_arr = comb_sort(arr, count_of_elements);

	cout << "\n��������������� ������: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << sorted_arr[i] << " ";
	}
	
	Save_Results(count_of_elements, sorted_arr);
}


//���������� � ������� �������� �����
void Fill_Auto_Random() {
	int count_of_elements = 3 + rand() % 20;
	double* arr = new double[count_of_elements];
	for (int i = 0; i < count_of_elements; i++) {
		arr[i] = (rand() % 200 - 100)/10.0;
	}

	cout << "----------------------------------------" << endl;
	cout << "���������� ��������� � �������: " << count_of_elements << endl;

	cout << "�������� ������: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << arr[i] << " ";
	}

	double* sorted_arr = new double[count_of_elements];
	sorted_arr = comb_sort(arr, count_of_elements);

	cout << "\n��������������� ������: " << endl;
	for (int i = 0; i < count_of_elements; i++) {
		cout << sorted_arr[i] << " ";
	}

	Save_Results(count_of_elements, sorted_arr);
}