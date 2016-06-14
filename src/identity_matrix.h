#ifndef identity_matrix_h
#define identity_matrix_h
#include "square_matrix.h"
template <typename T>
class identity_matrix : public square_matrix <T>
{
public:
    identity_matrix (int size)
    {
        for (int i = 0 ; i < size ; ++ i)
        {
            square_matrix<T>::column = size;
            square_matrix<T>::row = size;
            std::vector <T> tmp;
            for (int j = 0 ; j < size ; ++ j)
            {
                if (j == i)
                    tmp.push_back(1);
                else
                    tmp.push_back(0);
            }
            square_matrix<T>::mtx.push_back(std::move(tmp));
        }
    }
};

#endif
