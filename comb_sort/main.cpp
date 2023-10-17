#include "iostream"
#include "Menu_Items.h"
#include "Menu.h"
#include "Comb_Sort.h"
#include "Work_With_Files.h"
#include "Filling_Methods.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    
    About_Project(); //������� ���������� � ������� � ���������� ������

    int user_select = 0; // ���������� ��� ������ �������� �������������

    while (user_select != EXIT) { //����������� ����. �������� �� ������ ������������� �������� "�����"

        Choose_Action(); //����� �������� (������� ����, ������� � ����� �������������, �����)
        user_select = Check_Choise(EXIT); //�������� ����� ������ �����

        switch (user_select) { //��������, ����������� ������ �� ������

            case (CHOOSE_FILE): {  //������������ ����� ��� ������� ���� ��� ���������
                Choose_File();
                break;
            }

            case(FILL_AUTO_FILE): { //���������� �� ������� ���������� �����
                Fill_Auto_File();
                break;
            }

            case(FILL_AUTO_RANDOM): { //���������� ������� ���������� ������� ���������� �������
                Fill_Auto_Random();
            }

            case(EXIT): { //������ ������
                break;
            }
        }
        system("cls");
    }
    return 0;
}