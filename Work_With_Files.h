#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Check_Func.h"
using namespace std;
using namespace filesystem;

bool bool_check_filename(string filename); //������� �������� �� ������������� �����
string check_filename(); //�������� ����� ����� � ����������.
int get_quanity(string file_name); //������� ���������� ��������� � �����
double* matrix_from_file(string file_name, int quanity); //���������� ������� � �����
void save_result(int quanity, double* matrix); //���������� ���������� � ����