#include <iostream>
#include "rational.h"
#include "imaginary.h"
#include "vector.h"
#include "matrix.h"
#include "square_matrix.h"
#include "identity_matrix.h"
#include "equation_matrix.h"

int main()
{
#if 1
    rational r1 (2, 6);
    rational r2 (1, -3);
    rational r3 (1, 2);
    std::cout << r1 + r2 << " " << r1 << " " << r2 << "\n";
    r1 += r3;
    std::cout << r1 << "\n";
    r2 += 1;
    std::cout << r2 << "\n\n";
#endif
#if 1
    imaginary <rational> im1 (rational(1,2), rational(2, 3));
    imaginary <rational> im2 (rational(1,3), rational(1, 3));
    std::cout << im1 << " " << im2 << "\n\n";
#endif
#if 1
    vector <rational> v1 = {r1, r2, r3};
    vector <rational> v2 = {rational(1), rational(1), rational(1)};
    
    std::cout << v1 << v2 << "\n";
    vector<rational> v3 = v1 + v2;
    std::cout << v3 << "\n";
    v3 -= v1;
    std::cout << v3 << "\n\n";
#endif
#if 1
    matrix <int> m1 = { {1,2,3}, {3,2,1} };
    std::cout << m1 << "\n";
    square_matrix <rational> m2 = { { rational(1), rational(2), rational(4)},
    { rational(2), rational (3), rational (1)},
    { rational (3), rational (3), rational (6)} };
    std::cout << m2 << "\n";
    m2.gaussEliminaton();
    std::cout << m2 << "\n\n";
    std::cout << m2.rank() << "\n" <<m2.determinant() << "\n\n";
#endif
#if 1
    std::cout << v1 << "\n" << v1 * v1 << "\n\n\n";
    
    matrix < int > m3 = { {1, 1, 2}, {1, 2, 2} };
    matrix < int > m4 = { {1, 1, 1}, { 1, 1, 1} };
    
    std::cout << m3 << "\n" << m4 << "\n\n" << m3 + m4 << "\n\n";
    matrix < int > m5 = (m3 + m4);
    m5.transpose();
    std::cout << m5  << "\n\n";
    
    identity_matrix < rational > m6 (3);
    
    std::cout << m6 << "\n\n";
#endif
#if 1
    equation_matrix < rational > m7 = { { rational(7), rational (2)} , { rational(3), rational(4) } };
    
    vector < rational > eq_res = { rational(1), rational(2) };
    
    std::cout << m7 << "\n" << eq_res << "\n\n" << m7.eqation(eq_res) << "\n\n";
#endif
#if 1

    imaginary < rational > im3 (rational (1, 2), rational (1, 4));
    imaginary < rational > im4 (rational (3, 4), rational (4, 5));
    
    matrix< imaginary <rational> > im_mtx { {im1, im2}, {im3, im4} };
    std::cout << im_mtx << "\n\n" ;
    im_mtx.gaussEliminaton();
    std::cout << im_mtx << "\n\n";
#endif
    return 0;
}
