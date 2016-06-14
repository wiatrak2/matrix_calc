#ifndef equation_matrix_h
#define equation_matrix_h
#include "square_matrix.h"
#include "identity_matrix.h"
template <typename T>
class equation_matrix : public square_matrix <T>
{
    
private:
    T swap_det ( int c, vector <T> vec )
    {
        square_matrix <T> tmp = *this;
        for ( int i = 0 ; i < tmp.row ; ++ i )
            tmp[i][c] = vec[i];
        return tmp.determinant ( );
    }

public:
    equation_matrix ( std::initializer_list < std::initializer_list <T> > init )
    : square_matrix<T>::square_matrix (init)
    {
        if (square_matrix<T>::determinant ( ) == 0)
            throw std::runtime_error("equation matrix fault, matrix dimension = 0");
    }
    
    equation_matrix ( )
    {
        identity_matrix <T> tmp ( 2 );
        *this = std::move(tmp);
    }
    
    equation_matrix ( const std::vector< std::vector<T> > & init )
    : square_matrix<T>::square_matrix (init)
    {
        if (square_matrix<T>::determinant ( ) == 0)
            throw std::runtime_error("equation matrix fault, matrix dimension = 0");
    }
    
    equation_matrix ( const std::vector< vector <T> > & init )
    : square_matrix<T>::square_matrix ( init )
    {
        if (square_matrix<T>::determinant ( ) == 0)
            throw std::runtime_error("equation matrix fault, matrix dimension = 0");
    }
    
    equation_matrix ( const matrix <T> & m )
    : square_matrix<T>::square_matrix ( m )
    {
        if (square_matrix<T>::determinant ( ) == 0)
            throw std::runtime_error("equation matrix fault, matrix dimension = 0");
    }
    
    vector<T> eqation ( vector <T> results )
    {
        vector <T> res;
        equation_matrix <T> tmp = *this;
        T det = tmp.square_matrix<T>::determinant( );
        
        for (int i = 0 ; i < square_matrix<T>::column ; ++ i)
            res.vec.push_back( swap_det(i, results) / det );

        return res;
    }
    
};


#endif
