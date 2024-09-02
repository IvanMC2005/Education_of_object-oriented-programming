#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include<iomanip>
using namespace std;
class Performance
{
    friend istream& operator >> (istream &file, Performance &dot);
    friend ostream& operator << (ostream &file, const Performance dot);
    unsigned int intermission_count, duration;
    float top;
    int low_limit, upper_limit;
public:
    operator float() const;
    void operator <= (unsigned int a);
    void operator >= (unsigned int a);
    bool operator == (const Performance &p);
    bool operator >= (const Performance &p);
    bool operator <= (const Performance &p);
    bool operator != (const Performance &p);
    Performance & operator = (const Performance &p);
    Performance & operator += (const Performance &p);
    Performance & operator -= (const Performance &p);
    Performance & operator *= (const Performance &p);
    Performance & operator /= (const Performance &p);
    Performance & operator %= (const Performance &p);
    Performance();
    ~Performance();
    Performance(int low_limit, int upper_limit);
    void Set_low_limit(int low_limit);
    void Set_upper_limit(int upper_limit);
    void Set_top(float top);
    void Set_intermission_count(unsigned int intermission_count);
    void Set_duration(unsigned int duration);
    int Get_low_limit();
    int Get_upper_limit();
    float Get_top();
    unsigned int Get_intermission_count();
    unsigned int Get_duration();
    Performance(const Performance &old);
    void ShowPerformance();
    void ShowProgramm();
    void assess(double grade, Performance & dot);
    void ThirdCall();
    void SecondCall();
    void FirstCall();
};
ostream& operator << (ostream &, const Performance );
istream& operator >> (istream &, Performance &);

#endif // HEADER_H_INCLUDED
