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

        Choose_Action(); //выбор начать или закончить прогу
        user_select = Check_Choise(EXIT); //проверка ввода только чисел

        switch (user_select) { 

            case (START): {  //если пользователь выбрал "начать"

                Choose_What_Sort(); //варианты что сортировать (выбрать файл самому, по дефольтному файлу, рандом)
                int user_select_how_fill = Check_Choise(BACK);
                
                switch (user_select_how_fill) {

                    case (SORTING_CHOOSED_FILE): { //выбрать файл для сортировки
                        vector <double> sorted_vector = Comb_Sort(Choose_File());
                        Save_Results(sorted_vector);
                        break;
                    }

                    case(SORTING_DEFAULT_FILE): { //сортировка по заранее выбранному файл
                        vector <double> sorted_vector = Comb_Sort(Fill_Auto_File());
                        Save_Results(sorted_vector);
                        break;
                    }

                    case(SORING_RANDOM): { //сортировка по вектору заполненному рандомными чслами
                        vector <double> sorted_vector = Comb_Sort(Fill_Auto_Random());
                        Save_Results(sorted_vector);
                        break;
                    }

                    case (BACK): { //выход в главное меню
                        break;
                    }
                }   
            }

            case(EXIT): { //кнопка выхода
                break;
            }
        }
        system("cls");
    }
    return 0;
}