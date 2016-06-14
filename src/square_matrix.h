#ifndef square_matrix_h
#define square_matrix_h 1
#include "matrix.h"

template <typename T>
class square_matrix : public matrix <T>
{
public:
    
    square_matrix (std::initializer_list < std::initializer_list <T> > init)
    : matrix<T>::matrix (init)
    {
        if (matrix<T>::column != matrix<T>::row)
            throw std::runtime_error("not a sqare matrix");
    }
    
    square_matrix ( )
    : matrix<T>::matrix ( )
    { }
    
    square_matrix ( const std::vector< std::vector<T> > & init )
    : matrix<T>::matrix (init)
    {
        if (matrix<T>::column != matrix<T>::row)
            throw std::runtime_error("not a sqare matrix");
    }
    
    square_matrix ( const std::vector< vector <T> > & init )
    : matrix<T>:: matrix (init)
    {
        if (matrix<T>::column != matrix<T>::row)
            throw std::runtime_error("not a sqare matrix");
    }
    
    square_matrix ( const matrix <T> & m )
    : matrix<T>::matrix (m)
    {
        if (matrix<T>::column != matrix<T>::row)
            throw std::runtime_error("not a sqare matrix");
    }
    
    T determinant ( )
    {
        square_matrix <T> tmp = *this;
        T det = 1;
        tmp.matrix<T>::gaussEliminaton ( );
        for (int i = 0 ; i < matrix<T>::column ; ++ i)
            det *= tmp.matrix<T>::mtx[i][i];

        return tmp.matrix<T>::swap_counter % 2 ? -det : det;
    }
};

#endif
