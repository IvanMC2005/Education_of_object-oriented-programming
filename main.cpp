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
    cout << "���������\n";
    for (int i{0}; i < 10; i++)
    {
        file.read((char *)data, sizeof(exchange_rate));
            cout << "1 ������ " << data->first_country << "       ";
        cout << "2 ������ " << data->second_country << "       ";
        cout << "����� - " << data->current_course << endl;
    }
    delete data;*/
    int menu;
    char ch;
    double k;
    Performance test;
    do
    {
        cout << "�������� ��������:" << endl << "1 - ����������" << endl << "2 - ������� ���������� " << endl << "3 - �������"<< endl << "4 - ��������� 3 ���� � ������" << endl << "5 - ����������� ������ ������� ������ ���������"
        << endl << "6 - ��������� ������ ������ ���������" << endl << "7 - �������� ���������� � float" << endl << "8 - �������� ���������� �������� ����������" << endl << "9 - �������� ���������� �������� ���������  " << endl << "10 - �����" << endl;
        cin >> menu;
        while(cin.fail())
        {
            cin.clear();
            char ch;
            while((ch=getchar()) != '\n');
            cout << "�������� ��������:" << endl << "1 - ����������" << endl << "2 - ������� ���������� " << endl << "3 - �������"<< endl << "4 - ��������� 3 ���� � ������" << endl << "5 - ����������� ������ ������� ������ ���������"
            << endl << "6 - ��������� ������ ������ ���������" << endl << "7 - �������� ���������� � float" << endl << "8 - �������� ���������� �������� ����������" << endl << "9 - �������� ���������� �������� ���������  " << endl << "10 - �����" << endl;
            cin >> menu;
        }
        switch(menu)
        {
            case 1: test.ShowPerformance();break;
            case 2: test.ShowProgramm();break;
            case 3:
            {
                cout << "������� ������ - ";
                cin >> k;
                while(cin.fail())
                {
                    cin.clear();
                    char ch;
                    while((ch = getchar()) != '\n');
                    cout << "������� ������ - ";
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
                    cout << "������ �����\n";
                    cout << "��������� ������ ��� ���\n";
                    cin.clear();
                    cin >> test;
                }
                break;
            }
            case 7:
            {
                cout << test;
                float a = test;
                cout << a << " ������� ���������" << endl;
                char ch;
                while((ch = getchar()) != '\n');
                break;
            }
            case 8:
            {
                Performance Notmain;
                cout << "                                   ���������� ������� Notmain\n";
                cout << Notmain;
                cout << endl;
                cout << endl;
                cout << "                                     ���������� ������� Main\n";
                cout << test;
                cout << endl;
                cout << endl;
                Notmain = test;
                cout << (Notmain == test);
                cout << "                                   ���������� ������� Notmain\n";
                cout << Notmain;
                cout << endl;
                cout << endl;
                cout << "                                   ���������� ������� Main\n";
                cout << test;
                break;
            }
            case 9:
            {
                Performance Notmain;
                unsigned int a;
                cout << "                                   ���������� ������� Main\n";
                cout << test;
                cout << endl;
                cout << endl;
                cout << "�� ������� ���������/��������� ����� ���������(���������/��������� ������������)\n";
                cin >> a;
                if (a > 0)
                    test <= a;
                else
                    test >= a;
                cout << "                                   ���������� ������� Main\n";
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
