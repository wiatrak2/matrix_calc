#include "rational.h"

int rational::gcd ( int n1, int n2 )
{
    while ( n1 != 0 )
    {
        int c = n1;
        n1 = n2 % n1;
        n2 = c;
    }
    return n2;
}

void rational::normalize( )
{
    if (denum != 0)
    {
        int tmp_d = rational::gcd (num, denum);
        num /= tmp_d;
        denum /= tmp_d;
    }
    else
    {
        throw std::runtime_error("denum = 0");
    }
    if (denum < 0)
    {
        num = - num;
        denum = - denum;
    }
}

rational::rational ( )
    : num {0},
    denum {1}
    { }

rational::rational ( int i )
    : num {i},
    denum {1}
    { }

rational::rational( int num, int denum )
    : num{ num }, denum{ denum }
    {
        normalize( );
    }


bool rational::cmp::operator ( ) (const rational& r1, const rational& r2) const
{
    rational tmp = r2 - r1;
    return tmp.num > 0;
}

rational abs( const rational& r )
{
    return r.num >= 0 ? r : -r;
}

bool rational::operator < (const rational &r) const
{
    rational tmp = r - *this;
    return tmp.num > 0;
}

bool rational::operator > (const rational &r) const
{
    rational tmp = *this - r;
    return tmp.num > 0;
}

void rational::operator += ( const rational& r)
{
    if(r.denum == this->denum)
    {
        this->num += r.num;
        normalize ( );
    }
    else
    {
        rational tmp = *this + r;
        *this = std::move(tmp);
    }
}

void rational::operator += (int n)
{
    num += n * denum;
}

void rational::operator -= ( const rational& r)
{
    if(r.denum == this->denum)
    {
        this->num -= r.num;
        normalize ( );
    }
    else
    {
        rational tmp = *this - r;
        *this = std::move(tmp);
    }
}

void rational::operator -= (int n)
{
    num -= n * denum;
}

rational operator - ( const rational& r )
{
    return rational(-r.num, r.denum);
}

void rational::operator *= ( const rational& r )
{
    num *= r.num;
    denum *= r.denum;
}

rational operator + ( const rational& r1, const rational& r2 )
{
    return rational (r1.num * r2.denum + r2.num * r1.denum, r1.denum * r2.denum);
}

rational operator - ( const rational& r1, const rational& r2 )
{
    return rational (r1.num * r2.denum - r2.num * r1.denum, r1.denum * r2.denum);
}

rational operator * ( const rational& r1, const rational& r2 )
{
    return rational ( r1.num * r2.num, r1.denum * r2.denum );
}

rational operator / ( const rational& r1, const rational& r2 )
{
    return rational ( r1.num * r2.denum, r1.denum * r2.num );
}

bool operator == ( const rational& r1, int i)
{
    return r1 == rational(i);
}

bool operator == (const rational& r1, const rational& r2)
{
    return r1.num == r2.num && r1.denum == r2.denum;
}

bool operator != (const rational& r1, const rational& r2)
{
    return !(r1 == r2);
}


std::ostream& operator << ( std::ostream& stream, const rational& r )
{
    stream << r.num << "/" << r.denum;
    return stream;
}
