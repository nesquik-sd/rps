#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Check_Func.h"
using namespace std;
using namespace filesystem;

bool Bool_Check_Filename(string filename); //������� �������� �� ������������� �����
string Get_Correct_Filename(); //�������� ����� ����� � ����������.
int Get_Count_Of_Elements(string file_name); //������� ���������� ��������� � �����
double* Get_Arr_From_File(string file_name, int quanity); //���������� ������� � �����
void Save_Results(int quanity, double* matrix); //���������� ���������� � ����