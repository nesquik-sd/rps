#include "iostream"
#include "Comb_Sort.h"
#include "Work_With_Files.h"
#include "menu.h"
enum { START = 1, UNIT = 2, EXIT = 3 };

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int quanity = 0; //���������� ���������� ��������� �������
    double* arr; //������� ������
    arr = new double[quanity]; //�������� ������
    double* sorted_arr; //������� ������ ��� ������������
    sorted_arr = new double[quanity]; //�������� ������
    int start_select = 0; // ����� ������ ��� ���
    string file_name = ""; //���������� ��� �������� �����
    
    about_us(); //������� ���������� � ������� � ���������� ������

    while (start_select != EXIT) { //����������� ����. �������� �� ������ ������������� �������� "�����"

        start_or_exit(); //������ ��� ���
        start_select = check_three_selections(); //�������� ��� ����� ������ �����

        switch (start_select) { //����� ������������ 
        case (START): {  //���� ������ ������� "��������� ������"
                
                file_name = check_filename();//���� ����� �����
                quanity = get_quanity(file_name); //������� ���������� ��������� � �����
                arr = matrix_from_file(file_name, quanity); //����������� 
                cout << "----------------------------------------" << endl;
                cout << "���������� ��������� � �������: " << quanity << endl;
                cout << "----------------------------------------" << endl;
                cout << "�������� ������: " << endl;
                for (int i = 0; i < quanity; i++) {
                    cout << arr[i] << " ";
                }
                sorted_arr = comb_sort(arr, quanity); //��������� ������
                cout << "��������������� ������: " << endl;
                for (int i = 0; i < quanity; i++) {
                    cout << sorted_arr[i] << " ";
                }
                save_result(quanity, sorted_arr); //����������� ���������
                break;
        }
        case(UNIT): {
            unit_test(); //�������������� ���������� ������� � �����
            break;

        }
        case(EXIT): {
            
            break;
        }
         

        }
     delete[] arr;
     delete[] sorted_arr;
    }

   
   
    
    return 0;
}