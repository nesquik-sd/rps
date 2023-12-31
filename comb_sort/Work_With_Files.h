#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Check_Func.h"
using namespace std;
using namespace filesystem;

bool Bool_Check_Filename(string filename); //булевая проверка на существование файла
string Get_Correct_Filename(); //проверка имени файла и считывание.
int Get_Count_Of_Elements(string file_name); //подсчет количества элементов в файле
vector <double> Get_Vector_From_File(string file_name, int count_of_elements); //заполнение массива с файла
void Save_Results(vector <double> sorted_vec); //сохранение результата в файл