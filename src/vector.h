#ifndef vector_h
#define vector_h 1
#include <vector>
#include <cmath>

template <typename T>
class vector
{
public:
    
    std::vector <T> vec;
    
    vector ( )
    {
        vec = std::vector <T> ();
    }
        
    vector ( std::initializer_list <T> init )
    {
        for (auto i = init.begin() ; i != init.end() ; ++ i)
        {
            vec.push_back(*i);
        }
    }
    
    vector ( const vector <T> & v )
    {
        vec = v.vec;
    }
    
    vector ( const std::vector <T> & v)
    {
        vec = v;
    }
        
    T& operator [] (  int i )
    {
        return vec[i];
    }
    
    const T& operator [] ( int i ) const
    {
        return vec[i];
    }
    
    double length () const
    {
        double res = 0;
        for (int i = 0 ; i < vec.size() ; ++ i)
            res += vec[i]*vec[i];
        return sqrt(res);
    }
    
    void operator += (const vector & v)
    {
        if( vec.size() != v.vec.size())
            throw std::runtime_error("vectors are not the same size");
        for ( int i = 0 ; i < vec.size() ; ++ i )
            vec[i] += v[i];
    }

    void operator -= (const vector & v)
    {
        if( vec.size() != v.vec.size())
            throw std::runtime_error("vectors are not the same size");
        for ( int i = 0 ; i < vec.size() ; ++ i )
            vec[i] -= v[i];
    }
        
};

template <typename T>
T dot_product (const vector <T> & v1, const vector<T> & v2)
{
    if (v1.vec.size() != v2.vec.size())
        throw std::runtime_error("vectors are not the same size");
    T res = 0;
    for ( int i = 0 ; i < v1.vec.size() ; ++ i )
        res += v1[i] * v2[i];
    
    return res;
}

template <typename T>
vector <T> operator + (const vector <T> & v1, const vector <T> & v2)
{
    if (v1.vec.size() != v2.vec.size())
        throw std::runtime_error("vectors are not the same size");
    
    vector <T> res = v1;
    for (int i = 0 ; i < res.vec.size() ; ++ i)
        res[i] += v2[i];

    return res;
}

template <typename T>
vector <T> operator - (const vector <T> & v1, const vector <T> & v2)
{
    if (v1.vec.size() != v2.vec.size())
        throw std::runtime_error("vectors are not the same size");
    
    vector <T> res = v1;
    for (int i = 0 ; i < res.vec.size() ; ++ i)
        res[i] -= v2[i];
    
    return res;
}

template <typename T>
vector <T> operator * (const vector <T> & v, const T& val)
{
    vector <T> res = v;
    for (int i = 0 ; i < res.vec.size () ; ++ i)
        res[i] *= val;
    return res;
}


template <typename T>
bool operator == (const vector <T> & v, const T& val )
{
    for (int i = 0 ; i < v.vec.size() ; ++ i)
        if ( v[i] != val )
            return false;
    return true;
}

template <typename T>
bool operator != (const vector <T> & v, const T& val )
{
    return !(v == val);
}


template <typename T>
std::ostream& operator << ( std::ostream& stream, const vector <T> & v )
{
    stream << "||i ";
    for (int i = 0 ; i < v.vec.size() ; ++ i)
        stream << v[i] << " ";
    stream << "|| ";
    return stream;
}





#endif
