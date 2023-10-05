#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Check_Func.h"
using namespace std;
using namespace filesystem;

bool bool_check_filename(string filename); //булевая проверка на существование файла
string check_filename(); //проверка имени файла и считывание.
int get_quanity(string file_name); //подсчет количества элементов в файле
double* matrix_from_file(string file_name, int quanity); //заполнение массива с файла
void save_result(int quanity, double* matrix); //сохранение результата в файл