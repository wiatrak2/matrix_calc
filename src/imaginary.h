#ifndef imaginary_h
#define imaginary_h
#include <iostream>

template <typename T>
class imaginary
{
public:
    
    T rz;
    T im;
    
    imaginary ( )
    : rz { 0 },
    im { 0 }
    { }
    
    imaginary (T rz)
    : rz { rz },
    im { 0 }
    { }
    
    imaginary (T rz, T im)
    : rz { rz },
    im { im }
    { }
    
    imaginary (const imaginary<T> & i)
    : rz {i.rz},
    im {i.im}
    { }
    
    void operator += (const imaginary <T> & i)
    {
        imaginary <T> res = *this + i;
        *this = std::move(res);
    }
    
    void operator -= (const imaginary <T> & i)
    {
        imaginary <T> res = *this - i;
        *this = std::move(res);
    }
    
    void operator *= (const imaginary <T> & i)
    {
        imaginary <T> res = *this * i;
        *this = std::move(res);
    }
    
};

template <typename T>
T abs (const imaginary <T> & im)
{
    return im.rz * im.rz + im.im * im.im;
}

template <typename T>
imaginary <T> operator + (const imaginary <T> & im1, const imaginary <T> & im2)
{
    return imaginary <T> ( im1.rz + im2.rz, im1.im + im2.im );
}

template <typename T>
imaginary <T> operator - (const imaginary <T> & im1, const imaginary <T> & im2)
{
    return imaginary <T> ( im1.rz - im2.rz, im1.im - im2.im );
}

template <typename T>
imaginary <T> operator * (const imaginary <T> & im1, const imaginary <T> & im2)
{
    return imaginary <T> ( im1.rz * im2.rz - im1.im * im2.im, im1.im * im2.rz + im1.rz * im2.im );
}

template <typename T>
imaginary <T> operator / (const imaginary <T> & im1, const imaginary <T> & im2)
{
    return imaginary <T> ( (im1.rz * im2.rz + im1.im * im2.im) / (im2.rz * im2.rz + im2.im * im2.im), (im1.im * im2.rz - im1.rz * im2.im) / (im2.rz * im2.rz + im2.im * im2.im));
}

template <typename T>
bool operator == (const imaginary <T> & im1, const imaginary <T> & im2 )
{
    return (im1.rz == im2.rz) && (im1.im == im2.im);
}

template <typename T>
bool operator != (const imaginary <T> & im1, const imaginary <T> & im2 )
{
    return !(im1 == im2);
}

template <typename T>
bool operator == (const imaginary <T> & im, T val )
{
    return (im.rz == val) && (im.im == 0);
}

template <typename T>
bool operator != (const imaginary <T> & im, T val )
{
    return !(im == val);
}

template <typename T>
bool operator == (const imaginary <T> & im, int val )
{
    return (im.rz == val) && (im.im == 0);
}

template <typename T>
bool operator != (const imaginary <T> & im, int val )
{
    return !(im == val);
}

template <typename T>
std::ostream& operator << ( std::ostream& stream, const imaginary <T> & im1 )
{
    stream << im1.rz << " + " << im1.im;
    return stream;
}


#endif
