#include "iostream"
#include "Comb_Sort.h"
#include "Work_With_Files.h"
#include "menu.h"
enum { START = 1, UNIT = 2, EXIT = 3 };

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int quanity = 0; //переменная количества элементов массива
    double* arr; //создаем массив
    arr = new double[quanity]; //выделяем память
    double* sorted_arr; //создаем массив для отсортировки
    sorted_arr = new double[quanity]; //выделяем память
    int start_select = 0; // выбор начать или нет
    string file_name = ""; //переменная для названия файла
    
    about_us(); //краткая информация о задании и участниках группы

    while (start_select != EXIT) { //зацикленное меню. работает до выбора пользователем варианта "выход"

        start_or_exit(); //начать или нет
        start_select = check_three_selections(); //проверка для ввода только чисел

        switch (start_select) { //выбор пользователя 
        case (START): {  //если выбрал вариант "заполнить самому"
                
                file_name = check_filename();//ввод имени файла
                quanity = get_quanity(file_name); //подсчет количества элементов в файле
                arr = matrix_from_file(file_name, quanity); //заполенение 
                cout << "----------------------------------------" << endl;
                cout << "Количество элементов в массиве: " << quanity << endl;
                cout << "----------------------------------------" << endl;
                cout << "Исходный массив: " << endl;
                for (int i = 0; i < quanity; i++) {
                    cout << arr[i] << " ";
                }
                sorted_arr = comb_sort(arr, quanity); //сортируем массив
                cout << "Отсортированный массив: " << endl;
                for (int i = 0; i < quanity; i++) {
                    cout << sorted_arr[i] << " ";
                }
                save_result(quanity, sorted_arr); //возможность сохранить
                break;
        }
        case(UNIT): {
            unit_test(); //автоматическое заполнение массива с файла
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