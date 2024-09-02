#include <iostream>
#include<iomanip>
#include "header.h"
using namespace std;

ostream& operator << (ostream &file, const Performance dot)
{
    cout << "���������� �������� <<\n";
    file << "���������� ��������� |";
    file << "������������ |";
    file << " �������  |";
    file << "������ �������� ��� �� ������ |";
    file << "������� �������� ��� �� ������ |" << endl;
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
    cout << "���������� �������� >>\n";
    unsigned int a;
    float b;
    int c, c1;
    char ch;
    cout << "������� ������ � ���������:" << endl;
    cout << "���������� ��������� ";
    file >> a;
    if (!((a > 0) && (a < 10)))// ���� � �� ������ � �������� �� 0 �� 10
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//������� ������ file
        return file;
    }
    dot.Set_intermission_count(a);
    cout << "������������ (� �������) ";
    file >> a;
    if (!((a > 0) && (a < 200)))// ���� � �� ������ � �������� �� 0 �� 100
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//������� ������ file
        return file;
    }
    dot.Set_duration(a);

    cout << "������� ";
    file >> b;
    if (!((b > 0) && (b < 10)))// ���� b �� ������ � �������� �� 0 �� 10
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//������� ������ file
        return file;
    }
    dot.Set_top(b);

    cout << "������ �������� ��� �� ������ ";
    file >> c;
    if (!((c > 0) && (c < 10000)))// ���� c �� ������ � �������� �� 0 �� 10000
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//������� ������ file
        return file;
    }
    dot.Set_low_limit(c);

    cout << "������� �������� ��� �� ������ ";
    file >> c1;
    if (!((c1 > c) && (c < 100000)))// ���� � �� ������ � �������� �� 0 �� 100000
    {
        file.setstate(ios::failbit);
        while((ch = file.get()) != EOF);//������� ������ file
        return file;
    }
    dot.Set_upper_limit(c1);
    return file;
}

void Performance::ShowProgramm()
{
    cout << "� ���� ����� �����," << endl << "����������� ����:" << endl << "    ������ ��������������" << "    ��������� �������"
                    << endl << "    �������� �������" << endl << "    ��������� ����" << endl << "    Ѹ������� ����" << endl;
}
void Performance::ShowPerformance()
    {
        cout << "�� ���������� ���������" << endl;
    }
void Performance::assess(double grade, Performance & dot)
    {
        cout << "��������� �������� ��������\n";
        dot.top = (dot.top * 10 + grade) / 11;
    }
void Performance::ThirdCall()
    {
        cout << "�������� 3-�� ������ � ������\n";
    }
void Performance::SecondCall()
    {
        ThirdCall();
        cout << "�������� 2-�� ������ � ������\n";
    }
void Performance::FirstCall()
    {
        SecondCall();
        cout << "�������� 1-�� ������ � ������\n";
    }
unsigned int Performance::Get_duration()
    {
        cout << "����� ������� ��� ���� duration\n";
        return duration;
    }
unsigned int Performance::Get_intermission_count()
    {
        cout << "����� ������� ��� ���� intermission_count\n";
        return intermission_count;
    }
float Performance::Get_top()
    {
        cout << "����� ������� ��� ���� top\n";
        return top;
    }
int Performance::Get_upper_limit()
    {
        cout << "����� ������� ��� ���� low_upper\n";
        return upper_limit;
    }
int Performance::Get_low_limit()
    {
        cout << "����� ������� ��� ���� low_limit\n";
        return low_limit;
    }
void Performance::Set_duration(unsigned int duration)
    {
        cout << "����� ������� ��� ���� duration\n";
        this -> duration = duration;
    }
void Performance::Set_intermission_count(unsigned int intermission_count)
    {
        cout << "����� ������� ��� ���� intermission_count\n";
        this -> intermission_count = intermission_count;
    }
void Performance::Set_top(float top)
    {
        cout << "����� ������� ��� ���� top\n";
        this -> top = top;
    }
void Performance::Set_upper_limit(int upper_limit)
    {
        cout << "����� ������� ��� ���� upper_limit\n";
        this -> upper_limit = upper_limit;
    }
void Performance::Set_low_limit(int low_limit)
    {
        cout << "����� ������� ��� ���� low_limit\n";
        this -> low_limit = low_limit;
    }
Performance::Performance(const Performance &old)
{
    cout << "������ ������������ �����������\n";
    this -> intermission_count = old.intermission_count;
    this -> duration = old.duration;
    this -> top = old.top;
    this -> low_limit = old.low_limit;
    this -> upper_limit = old.upper_limit;
}

Performance::Performance(int low_limit, int upper_limit)
{
    cout << "������ ������������ � �����������\n";
    this -> low_limit = low_limit;
    this -> upper_limit = upper_limit;
}
Performance::~Performance()
{
    cout << "������ ����������� ��� ����������\n";
}
Performance::Performance()
{
    cout << "������ ������������ ��� ����������\n";
}
Performance & Performance::operator %= (const Performance &p)
{
    cout << "���������� ��������� ����������\n";
    this ->intermission_count %= p.intermission_count;
    this ->duration %= p.duration;
    this ->top = p.top;
    this ->low_limit %= p.low_limit;
    this ->upper_limit %= p.upper_limit;
    return *this;
}
Performance & Performance::operator /= (const Performance &p)
    {
        cout << "���������� ��������� ����������\n";
        this ->intermission_count /= p.intermission_count;
        this ->duration /= p.duration;
        this ->top /= p.top;
        this ->low_limit /= p.low_limit;
        this ->upper_limit /= p.upper_limit;
        return *this;
    }

Performance & Performance::operator *= (const Performance &p)
    {
        cout << "���������� ��������� ����������\n";
        this ->intermission_count *= p.intermission_count;
        this ->duration *= p.duration;
        this ->top *= p.top;
        this ->low_limit *= p.low_limit;
        this ->upper_limit *= p.upper_limit;
        return *this;
    }

Performance & Performance::operator -= (const Performance &p)
    {
        cout << "���������� ��������� ����������\n";
        this ->intermission_count -= p.intermission_count;
        this ->duration -= p.duration;
        this ->top -= p.top;
        this ->low_limit -= p.low_limit;
        this ->upper_limit -= p.upper_limit;
        return *this;
    }

Performance & Performance::operator += (const Performance &p)
    {
        cout << "���������� ��������� ����������\n";
        this ->intermission_count += p.intermission_count;
        this ->duration += p.duration;
        this ->top += p.top;
        this ->low_limit += p.low_limit;
        this ->upper_limit += p.upper_limit;
        return *this;
    }
Performance & Performance::operator = (const Performance &p)
    {
        cout << "���������� ��������� ����������\n";
        this ->intermission_count = p.intermission_count;
        this ->duration = p.duration;
        this ->top = p.top;
        this ->low_limit = p.low_limit;
        this ->upper_limit = p.upper_limit;
        return *this;
    }
bool Performance::operator != (const Performance &p)
    {
        cout << "���������� ��������� ���������\n";
        int ifelse = (this->intermission_count == p.intermission_count) * (this->duration == p.duration) * (this ->top == p.top)
                                                * (this -> low_limit == p.low_limit) * (this -> upper_limit == p.upper_limit);
        if (ifelse)
            return true;
        return false;
    }
bool Performance::operator <= (const Performance &p)
    {
        cout << "���������� �������� ���������\n";
        int ifelse = (this->intermission_count <= p.intermission_count) + (this->duration <= p.duration) + (this ->top <= p.top)
                                                + (this -> low_limit <= p.low_limit) + (this -> upper_limit <= p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }

bool Performance::operator >= (const Performance &p)
    {
        cout << "���������� �������� ���������\n";
        int ifelse = (this->intermission_count >= p.intermission_count) + (this->duration >= p.duration) + (this ->top >= p.top)
                                                + (this -> low_limit >= p.low_limit) + (this -> upper_limit >= p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }
bool Performance::operator == (const Performance &p)
    {
        cout << "���������� �������� ���������\n";
        int ifelse = (this->intermission_count == p.intermission_count) + (this->duration == p.duration) + (this ->top == p.top)
                                                + (this -> low_limit == p.low_limit) + (this -> upper_limit == p.upper_limit);
        if (ifelse == 5)
            return true;
        return false;
    }
void Performance::operator >= (unsigned int a)
    {
        cout << "���������� �������� ���������\n";
        this -> duration -= a;
        this -> intermission_count -= a;
    }
void Performance::operator <= (unsigned int a)
    {
        cout << "���������� �������� ���������\n";
        duration += a;
        intermission_count += a;
    }
Performance::operator float() const
    {
        cout << "���������� �������� ���������� ����\n";
        return this -> duration / ((this->low_limit + this->upper_limit)/2);
    }
