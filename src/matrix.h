#ifndef matrix_h
#define matrix_h 1
#include "vector.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>


template <typename T>
class matrix
{
protected:
    int swap_counter;

public:

    
    size_t row;
    size_t column;
    
    std::vector < std::vector <T> > mtx;
    
    matrix ( )
    : row { 0 },
    column { 0 },
    swap_counter { 0 }
    {
        mtx = std::vector < std::vector <T> > ();
    }
    
    matrix (std::initializer_list < std::initializer_list <T> > init)
    : row { init.size () },
    column { init.begin()->size() },
    swap_counter { 0 }
    {
        for ( auto i = init.begin () ; i != init.end () ; ++ i )
        {
            std::vector <T> row;
            
            for ( auto j = (*i).begin() ; j != (*i).end() ; ++ j )
                row.push_back(*j);
            
            mtx.push_back(std::move(row));
        }
    }
    
    matrix ( const std::vector< std::vector<T> > & init )
    : row { init.size() },
    column { init.begin()->size() },
    swap_counter { 0 }
    {
        for (int i = 0 ; i < row ; ++ i)
            mtx.push_back(init[i]);
    }
    
    matrix ( const std::vector< vector <T> > & init )
    : row { init.size() },
    column { init[0].vec.size() },
    swap_counter { 0 }
    {
        for ( auto i = 0 ; i < row ; ++ i )
        {
            mtx.push_back(init[i].vec);
        }
    }
    
    matrix ( const matrix <T> & m ) 
    : column {m.column},
    row {m.row},
    swap_counter { m.swap_counter }
    {
        mtx = m.mtx;
    }
    
    std::vector <T> & operator [] (  int i )
    {
        return mtx[i];
    }
    
    const std::vector <T> & operator [] ( int i ) const
    {
        return mtx[i];
    }
    
    void pivot ( int i, int row_begin )
    {
        for (int j = row_begin ; j < row - 1 ; ++ j)
        {
            for (int k = j + 1 ; k < row ; ++ k)
            {
                if ( abs(mtx[j][i]) < abs(mtx[k][i]) )
                {
                    std::swap(mtx[j], mtx[k]);
                    swap_counter ++;
                }
            }
        }
    }
    
    void gaussEliminaton ( )
    {
        for (int i = 0 ; i < row ; ++ i)
        {
            int it = 0;
            pivot ( it, i );
            while(it < column && mtx[i][it] == 0)
            {
                it ++;
                pivot( it, i );
            }
            if (it == column)
                continue;
            
            for (int j = i + 1 ; j < row ; ++ j)
            {
                if(mtx[j][it] != 0)
                {
                    T diff = mtx[j][it] / mtx[i][it];
                    for (int k = it ; k < column ; ++ k)
                        mtx[j][k] -= diff * mtx[i][k];
                }
            }
        }
    }
    
    int rank ( )
    {
        matrix <T> tmp = *this;
        tmp.gaussEliminaton( );
        int sum = 0;
        T zero = 0;
        for (int i = 0 ; i < row ; ++ i)
        {
            if (tmp.rowToVector(i) != zero)
                sum ++;
        }
        return sum;
    }
    
    int eq_res_amount ( vector <T> results )
    {
        matrix <T> tmp = *this;
        int tmp_rk = tmp.rank ( );
        for (int i = 0 ; i < tmp.row ; ++ i)
            tmp[i].push_back(results[i]);
        tmp.column ++;
        int tmp_u_rk = tmp.rank ( );
        if (tmp_rk == tmp_u_rk)
            return tmp_rk == results.vec.size() ? 1 : -1;
        return 0;
    }
    
    void transpose ( )
    {
        std::vector < vector<T> > tmp;
        for (int i = 0 ; i < column ; ++ i)
            tmp.push_back(columnToVector (i) );
        matrix <T> tmp_mtx { std::move( tmp ) };
        *this = std::move( tmp_mtx );
    }
    
    vector <T> rowToVector (int i) const
    {
        return vector <T> (mtx[i]);
    }
    
    vector <T> columnToVector ( int i ) const
    {
        std::vector < T > res;
        for (int j = 0 ; j < row ; ++ j)
            res.push_back(mtx[j][i]);
        return vector <T> ( res );
    }
    
};

template <typename T>
matrix <T> vecToMtx (const vector <T> & v)
{
    std::vector< std::vector <T> > tmp;
    for ( int i = 0 ; i < v.vec.size() ; ++ i )
    {
        std::vector <T> elem;
        elem.push_back(v[i]);
        tmp.push_back(std::move(elem));
    }
    return matrix <T> (std::move(tmp));
}

template <typename T>
matrix <T> operator * ( const vector <T> & v1,  const vector <T> & v2)
{
    matrix <T> res;
    if (v1.vec.size() != v2.vec.size())
        throw std::runtime_error ( "multiply error - vecotrs are not the same length" );
    for (int i = 0 ; i < v1.vec.size() ; ++ i)
        res.mtx.push_back( (v2 * v1[i]).vec );
    return res;
}

template <typename T>
matrix <T> operator * ( const matrix <T> & m1, const matrix <T> & m2 )
{
    if (m1.column != m2.row)
        throw std::runtime_error ( " multiply error - wrong matrix size " );
    
    matrix <T> res;
    for (int i = 0 ; i < m1.row ; ++ i)
    {
        vector <T> row = m1.rowToVector ( i );
        std::vector <T> tmp;
        for (int j = 0 ; j < m2.column ; ++ j)
        {
            vector <T> column = m2.columnToVector ( j );
            tmp.push_back(dot_product(row, column));
        }
        res.mtx.push_back(std::move(tmp));
    }
    return res;
}

template <typename T>
matrix <T> operator + ( const matrix <T> & m1, const matrix <T> & m2 )
{
    if (m1.row != m2.row || m1.column != m2.column)
        throw std::runtime_error (" addition fault - matrixes are not the same size ");
    matrix <T> res = m1;
    for (int i = 0 ; i < res.row ; ++ i)
        for (int j = 0 ; j < res.column ; ++ j )
            res[i][j] += m2[i][j];
    return res;
}

template <typename T>
matrix <T> operator - ( const matrix <T> & m1, const matrix <T> & m2 )
{
    if (m1.row != m2.row || m1.column != m2.column)
        throw std::runtime_error (" addition fault - matrixes are not the same size ");
    matrix <T> res = m1;
    for (int i = 0 ; i < res.row ; ++ i)
        for (int j = 0 ; j < res.column ; ++ j )
            res[i][j] -= m2[i][j];
    return res;
}

template <typename T>
std::ostream& operator << ( std::ostream& stream, const matrix <T> & m )
{
    stream << "\n";
    for (auto i = m.mtx.begin() ; i != m.mtx.end() ; ++ i)
    {
        stream << "||| ";
        for (auto j = (*i).begin() ; j != (*i).end() ; ++ j)
            stream << std::setw ( 8 ) << (*j) ;
        stream << std::setw ( 8 )  <<"|||\n";
    }
   return stream;
}



#endif
