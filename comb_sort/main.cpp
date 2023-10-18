#include "iostream"
#include "Menu_Items.h"
#include "Menu.h"
#include "Comb_Sort.h"
#include "Work_With_Files.h"
#include "Filling_Methods.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    
    About_Project(); //краткая информация о задании и участниках группы

    int user_select = 0; // переменная для выбора действия пользователем

    while (user_select != EXIT) { //зацикленное меню. работает до выбора пользователем варианта "выход"

        Choose_Action(); //выбор действия (выбрать файл, считать с файла автоматически, выход)
        user_select = Check_Choise(EXIT); //проверка ввода только чисел

        switch (user_select) { //действие, выполняемое исходя из выбора

            case (CHOOSE_FILE): {  //пользователь может сам указать файл для сортирови
                Choose_File();
                break;
            }

            case(FILL_AUTO_FILE): { //сортировка по заранее выбранному файлу
                Fill_Auto_File();
                break;
            }

            case(FILL_AUTO_RANDOM): { //заполнение массива рандомного размера рандомными числами
                Fill_Auto_Random();
            }

            case(EXIT): { //кнопка выхода
                break;
            }
        }
        system("cls");
    }
    return 0;
}