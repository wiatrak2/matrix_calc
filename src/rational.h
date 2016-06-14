#ifndef rational_h
#define rational_h 1
#include <iomanip>
#include <iostream>

class rational
{
public:
    int num;
    int denum;
    rational ( );
    rational ( int i );
    rational (int num, int denum);
    void normalize ( );
    static int gcd ( int n1, int n2 );
    
    void operator += ( const rational& r );
    void operator += (int n);
    void operator -= ( const rational& r );
    void operator -= (int n);
    void operator *= ( const rational& r );
    
    struct cmp
    {
        bool operator ( ) ( const rational& r1, const rational & r2 ) const;
    };
    
    bool operator < (const rational& r) const;
    bool operator > (const rational& r) const;

};

rational abs (const rational& r);

rational operator - ( const rational& r );

rational operator + ( const rational& r1, const rational& r2 );
rational operator - ( const rational& r1, const rational& r2 );
rational operator * ( const rational& r1, const rational& r2 );
rational operator / ( const rational& r1, const rational& r2 );

bool operator == ( const rational& r1, int i);
bool operator == ( const rational& r1, const rational& r2 );
bool operator != ( const rational& r1, const rational& r2 );



std::ostream& operator << ( std::ostream& stream, const rational& r );



#endif
