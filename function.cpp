#include <iostream>
#include<iomanip>
#include "header.h"
using namespace std;

ostream& operator << (ostream &file, const Performance dot)
{
    cout << "Перегрузка операции <<\n";
    file << "Количество антрактов |";
    file << "Длительность |";
    file << " Рейтинг  |";
    file << "Нижний диапазон цен на билеты |";
    file << "Верхний диапазон цен на билеты |" << endl;
    file << setw(22) << left << dot.intermission_count;
    file << setw(14) << left << dot.duration;
    file << setw(11) << left << setprecision(4) << dot.top;
    file << setw(31) << left << dot.low_limit;
    file << setw(23) << left << dot.upper_limit << endl;
    return file;
}

istream& operator >> (istream &file, Performance &dot)
{
    file.clear();
    cout << "Перегрузка операции >>\n";
    unsigned int a;
    float b;
    int c, c1;
    char ch;
    cout << "Введите данные о спектакле:" << endl;
    cout << "Количество антрактов ";
    file >> a;
    if (!((a > 0) && (a < 10)))// если а не попала в диапазон от 0 до 10
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//очистка потока file
        return file;
    }
    dot.Set_intermission_count(a);
    cout << "Длительность (в минутах) ";
    file >> a;
    if (!((a > 0) && (a < 200)))// если а не попала в диапазон от 0 до 100
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//очистка потока file
        return file;
    }
    dot.Set_duration(a);

    cout << "Рейтинг ";
    file >> b;
    if (!((b > 0) && (b < 10)))// если b не попала в диапазон от 0 до 10
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//очистка потока file
        return file;
    }
    dot.Set_top(b);

    cout << "Нижний диапазон цен на билеты ";
    file >> c;
    if (!((c > 0) && (c < 10000)))// если c не попала в диапазон от 0 до 10000
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//очистка потока file
        return file;
    }
    dot.Set_low_limit(c);

    cout << "Верхний диапазон цен на билеты ";
    file >> c1;
    if (!((c1 > c) && (c < 100000)))// если а не попала в диапазон от 0 до 100000
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//очистка потока file
        return file;
    }
    dot.Set_upper_limit(c1);
    return file;
}

void Performance::ShowProgramm()
{
    cout << "А зори здесь тихие," << endl << "Действующие лица:" << endl << "    Роберт Рождественский" << "    Екатерина Слуцкая"
                    << endl << "    Щербаков Алексей" << endl << "    Бурьянова Алёна" << endl << "    Сёмочкина Анна" << endl;
}
void Performance::ShowPerformance()
    {
        cout << "Вы посмотрели спектакль" << endl;
    }
void Performance::assess(double grade, Performance & dot)
    {
        cout << "Установка значения рейтинга\n";
        dot.top = (dot.top * 10 + grade) / 11;
    }
void Performance::ThirdCall()
    {
        cout << "Раздаётся 3-ий сигнал к началу\n";
    }
void Performance::SecondCall()
    {
        ThirdCall();
        cout << "Раздаётся 2-ой сигнал к началу\n";
    }
void Performance::FirstCall()
    {
        SecondCall();
        cout << "Раздаётся 1-ий сигнал к началу\n";
    }
unsigned int Performance::Get_duration()
    {
        cout << "Вызов геттера для поля duration\n";
        return duration;
    }
unsigned int Performance::Get_intermission_count()
    {
        cout << "Вызов геттера для поля intermission_count\n";
        return intermission_count;
    }
float Performance::Get_top()
    {
        cout << "Вызов геттера для поля top\n";
        return top;
    }
int Performance::Get_upper_limit()
    {
        cout << "Вызов геттера для поля low_upper\n";
        return upper_limit;
    }
int Performance::Get_low_limit()
    {
        cout << "Вызов геттера для поля low_limit\n";
        return low_limit;
    }
void Performance::Set_duration(unsigned int duration)
    {
        cout << "Вызов сеттера для поля duration\n";
        this -> duration = duration;
    }
void Performance::Set_intermission_count(unsigned int intermission_count)
    {
        cout << "Вызов сеттера для поля intermission_count\n";
        this -> intermission_count = intermission_count;
    }
void Performance::Set_top(float top)
    {
        cout << "Вызов сеттера для поля top\n";
        this -> top = top;
    }
void Performance::Set_upper_limit(int upper_limit)
    {
        cout << "Вызов сеттера для поля upper_limit\n";
        this -> upper_limit = upper_limit;
    }
void Performance::Set_low_limit(int low_limit)
    {
        cout << "Вызов сеттера для поля low_limit\n";
        this -> low_limit = low_limit;
    }
Performance::Performance(const Performance &old)
{
    cout << "Запуск конструктора копирования\n";
    this -> intermission_count = old.intermission_count;
    this -> duration = old.duration;
    this -> top = old.top;
    this -> low_limit = old.low_limit;
    this -> upper_limit = old.upper_limit;
}

Performance::Performance(int low_limit, int upper_limit)
{
    cout << "Запуск конструктора с параметрами\n";
    this -> low_limit = low_limit;
    this -> upper_limit = upper_limit;
}
Performance::~Performance()
{
    cout << "Запуск деструктора без параметров\n";
}
Performance::Performance()
{
    cout << "Запуск конструктора без параметров\n";
}
Performance & Performance::operator %= (const Performance &p)
{
    cout << "Перегрузка оператора присвоения\n";
    this ->intermission_count %= p.intermission_count;
    this ->duration %= p.duration;
    this ->top = p.top;
    this ->low_limit %= p.low_limit;
    this ->upper_limit %= p.upper_limit;
    return *this;
}
Performance & Performance::operator /= (const Performance &p)
    {
        cout << "Перегрузка оператора присвоения\n";
        this ->intermission_count /= p.intermission_count;
        this ->duration /= p.duration;
        this ->top /= p.top;
        this ->low_limit /= p.low_limit;
        this ->upper_limit /= p.upper_limit;
        return *this;
    }

Performance & Performance::operator *= (const Performance &p)
    {
        cout << "Перегрузка оператора присвоения\n";
        this ->intermission_count *= p.intermission_count;
        this ->duration *= p.duration;
        this ->top *= p.top;
        this ->low_limit *= p.low_limit;
        this ->upper_limit *= p.upper_limit;
        return *this;
    }

Performance & Performance::operator -= (const Performance &p)
    {
        cout << "Перегрузка оператора присвоения\n";
        this ->intermission_count -= p.intermission_count;
        this ->duration -= p.duration;
        this ->top -= p.top;
        this ->low_limit -= p.low_limit;
        this ->upper_limit -= p.upper_limit;
        return *this;
    }

Performance & Performance::operator += (const Performance &p)
    {
        cout << "Перегрузка оператора присвоения\n";
        this ->intermission_count += p.intermission_count;
        this ->duration += p.duration;
        this ->top += p.top;
        this ->low_limit += p.low_limit;
        this ->upper_limit += p.upper_limit;
        return *this;
    }
Performance & Performance::operator = (const Performance &p)
    {
        cout << "Перегрузка оператора присвоения\n";
        this ->intermission_count = p.intermission_count;
        this ->duration = p.duration;
        this ->top = p.top;
        this ->low_limit = p.low_limit;
        this ->upper_limit = p.upper_limit;
        return *this;
    }
bool Performance::operator != (const Performance &p)
    {
        cout << "Перегрузка оператора сравнения\n";
        int ifelse = (this->intermission_count == p.intermission_count) * (this->duration == p.duration) * (this ->top == p.top)
                                                * (this -> low_limit == p.low_limit) * (this -> upper_limit == p.upper_limit);
        if (ifelse)
            return true;
        return false;
    }
bool Performance::operator <= (const Performance &p)
    {
        cout << "Перегрузка операции сравнения\n";
        int ifelse = (this->intermission_count <= p.intermission_count) + (this->duration <= p.duration) + (this ->top <= p.top)
                                                + (this -> low_limit <= p.low_limit) + (this -> upper_limit <= p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }

bool Performance::operator >= (const Performance &p)
    {
        cout << "Перегрузка операции сравнения\n";
        int ifelse = (this->intermission_count >= p.intermission_count) + (this->duration >= p.duration) + (this ->top >= p.top)
                                                + (this -> low_limit >= p.low_limit) + (this -> upper_limit >= p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }
bool Performance::operator == (const Performance &p)
    {
        cout << "Перегрузка операции сравнения\n";
        int ifelse = (this->intermission_count == p.intermission_count) + (this->duration == p.duration) + (this ->top == p.top)
                                                + (this -> low_limit == p.low_limit) + (this -> upper_limit == p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }
void Performance::operator >= (unsigned int a)
    {
        cout << "Перегрузка операции сравнения\n";
        this -> duration -= a;
        this -> intermission_count -= a;
    }
void Performance::operator <= (unsigned int a)
    {
        cout << "Перегрузка операции сравнения\n";
        duration += a;
        intermission_count += a;
    }
Performance::operator float() const
    {
        cout << "Перегрузка операции приведения типа\n";
        return this -> duration / ((this->low_limit + this->upper_limit)/2);
    }
