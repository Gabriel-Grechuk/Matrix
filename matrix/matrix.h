
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
using std::ostream;


template <class type>
class matrix
{
private:
    type *Matrix;
    int i;
    int j;
    int size;
    int lenght;


    // Guarda o estado de erro.
    int error; 

    // Auxiliar functions to get the matrix.
    // Adapted from:
    // https://www.geeksforgeeks.org/determinant-of-a-matrix/
    void getCofactor(int size, type mat[], type temp[], int p, int q, int n);
    type determinantOfMatrix(int size, type mat[], int n);

public:
    // Construtores e destrutor.
    matrix(int line, int colun);
    matrix(int line, int colun, type v);
    matrix(int line, int colun, type M[]);
    matrix(const matrix &M);
    ~matrix();



    // Getters
    int get_i(void);
    int get_j(void);
    type get(int line, int colun);
    int getError(void);



    // Seters.
    void set(type M[]);
    void set(int line, int colun, type v);
    void fill(type v);



    // Operators.
    void operator= (const matrix &M);
    type& operator()(int line, int colun);
    type getDet(void);         // Yeah I will consider this one as a operator. :v



    // Formated Output
    void print(void);
};

#include "matrix.cpp"

#endif  // _MATRIX_h_
