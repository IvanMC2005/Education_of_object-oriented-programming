#include <iostream>
#include<iomanip>
#include <fstream>
#include <string.h>
#include "header.h"
using namespace std;
/*typedef struct exchange_rate
{
    char first_country[4];
    char second_country[4];
    int current_course;
};*/
int main()
{
    setlocale(LC_ALL, "");
    /*ifstream file;
    file.open("Test.odt");
    exchange_rate * data;
    data = new exchange_rate;
    for (int i{0}; i < 100; i++)
    {
        data = new exchange_rate;
        data->current_course = rand() % 50;
        strcpy(data->first_country, "Rus");
        strcpy(data->second_country, "Ukr");
        file.write((char *)data, sizeof(exchange_rate));
        delete data;
    }
    cout << "Структура\n";
    for (int i{0}; i < 10; i++)
    {
        file.read((char *)data, sizeof(exchange_rate));
            cout << "1 страна " << data->first_country << "       ";
        cout << "2 страна " << data->second_country << "       ";
        cout << "Число - " << data->current_course << endl;
    }
    delete data;*/
    int menu;
    char ch;
    double k;
    Performance test;
    do
    {
        cout << "Выберите действие:" << endl << "1 - Посмотреть" << endl << "2 - Изучить программку " << endl << "3 - Оценить"<< endl << "4 - Позвонить 3 раза к началу" << endl << "5 - Просмотреть данные объекта класса спектакль"
        << endl << "6 - Заполнить объект класса спектакль" << endl << "7 - Проверка привдеения к float" << endl << "8 - Проверка перегрузки операции присвоения" << endl << "9 - Проверка перегрузки операции сравнения  " << endl << "10 - Выход" << endl;
        cin >> menu;
        while(cin.fail())
        {
            cin.clear();
            char ch;
            while((ch=getchar()) != '\n');
            cout << "Выберите действие:" << endl << "1 - Посмотреть" << endl << "2 - Изучить программку " << endl << "3 - Оценить"<< endl << "4 - Позвонить 3 раза к началу" << endl << "5 - Просмотреть данные объекта класса спектакль"
            << endl << "6 - Заполнить объект класса спектакль" << endl << "7 - Проверка привдеения к float" << endl << "8 - Проверка перегрузки операции присвоения" << endl << "9 - Проверка перегрузки операции сравнения  " << endl << "10 - Выход" << endl;
            cin >> menu;
        }
        switch(menu)
        {
            case 1: test.ShowPerformance();break;
            case 2: test.ShowProgramm();break;
            case 3:
            {
                cout << "Введите оценку - ";
                cin >> k;
                while(cin.fail())
                {
                    cin.clear();
                    char ch;
                    while((ch = getchar()) != '\n');
                    cout << "Введите оценку - ";
                    cin >> k;
                }
                test.assess(k, test);
                break;
            }
            case 4:
            {
                test.FirstCall();break;
            }
            case 5:
            {
                cout << test;
                break;
            }
            case 6:
            {
                cin >> test;
                while(cin.fail())
                {
                    cout << "Ошибка ввода\n";
                    cout << "Заполните данные ещё раз\n";
                    cin.clear();
                    cin >> test;
                }
                break;
            }
            case 7:
            {
                cout << test;
                float a = test;
                cout << a << " средняя стоимость" << endl;
                char ch;
                while((ch = getchar()) != '\n');
                break;
            }
            case 8:
            {
                Performance Notmain;
                cout << "                                   Содержимое объекта Notmain\n";
                cout << Notmain;
                cout << endl;
                cout << endl;
                cout << "                                     Содержимое объекта Main\n";
                cout << test;
                cout << endl;
                cout << endl;
                Notmain = test;
                cout << (Notmain == test);
                cout << "                                   Содержимое объекта Notmain\n";
                cout << Notmain;
                cout << endl;
                cout << endl;
                cout << "                                   Содержимое объекта Main\n";
                cout << test;
                break;
            }
            case 9:
            {
                Performance Notmain;
                unsigned int a;
                cout << "                                   Содержимое объекта Main\n";
                cout << test;
                cout << endl;
                cout << endl;
                cout << "На сколько увеличить/уменьшить число антрактов(увеличить/уменьшить длительность)\n";
                cin >> a;
                if (a > 0)
                    test <= a;
                else
                    test >= a;
                cout << "                                   Содержимое объекта Main\n";
                cout << test;
                break;
            }

        }
        system("pause");
        system("cls");
    }
    while (menu != 10);
    return 0;
}
