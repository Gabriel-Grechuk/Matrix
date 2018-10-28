#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_

#include <iostream>
#include <iomanip>
#include <sstream>

#include "matrix.h"

using std::stringstream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::setw;



/////////////////////////////
// --- Funções Globais --- //
/////////////////////////////

//// Construtores e destrutor /////////////////////////////////////////////////

//============================================================================
// Inicia a matriz nula.

template <class type>
matrix<type>::matrix(int line, int colun)
{
    i = line;
    j = colun;
    size = i * j;
    Matrix = new type[size];

    error = 0;

    fill(0);
}



//============================================================================
// Inicia preenchendo todos os espaços.

template <class type>
matrix<type>::matrix(int line, int colun, type v)
{
    i = line;
    j = colun;
    size = i * j;
    Matrix = new type[size];

    error = 0;

    fill(v);
}



//============================================================================
// Inclui uma atriz para a inicialização.

template <class type>
matrix<type>::matrix(int line, int colun, type M[])
{
    i = line;
    j = colun;
    size = i * j;
    Matrix = new type[size];

    error = 0;

    set(M);
}



//============================================================================
// controi uma matriz, com base em outra como argumento.

template <class type>
matrix<type>::matrix(const matrix &M)
{
    i = M.i;
    j = M.j;
    size = M.size;
    Matrix = new type[size];

    error = M.error;

    set(M.Matrix);
}



//============================================================================
// Deleta a matriz e libera o espaço.

template <class type>
matrix<type>::~matrix()
{
    delete[] Matrix;
}



//// Getters //////////////////////////////////////////////////////////////////

//============================================================================
// Retorna o n° de linhas.

template <class type>
int matrix<type>::get_i(void)
{
    return i;
}



//============================================================================
// Retorna o n° de colnas.

template <class type>
int matrix<type>::get_j(void)
{
    return j;
}



//============================================================================
// Retorna um valor armazenado na matriz. 

template <class type>
type matrix<type>::get(int line, int colun)
{   
    // Verify if the solicited values are in the range of the size.
    if((line <= i && colun <= j) && (line >= 0 && colun >= 0))
        return Matrix[line * j + colun];
    else
        return 0;
}



//============================================================================
// Return the class error level..

template <class type>
int matrix<type>::getError(void)
{
    return error;
}


/////////// Setters ///////////////////////////////////////////////////////////

//============================================================================
// Entra uma matriz para ser utilizada.

template <class type>
void matrix<type>::set(type M[])
{
    for(int line = 0; line <= i; line++)
    {
        for(int colun = 0; colun <= j; colun++)
        {
            Matrix[line * j + colun] = M[line * j + colun];
        }
    }
}



//============================================================================
// Entra um valor para ser utilizado na matriz.

template <class type>
void matrix<type>::set(int line, int colun, type v)
{
    Matrix[line * j + colun] = v;
}



//============================================================================
// Enche a matriz completamente com um determinado valor.

template <class type>
void matrix<type>::fill(type v)
{
    for(int c = 0; c < size; c++)
        Matrix[c] = v;
}



////////// Operators //////////////////////////////////////////////////////////

//============================================================================
// Sobrecarrega o operador =, podendo recever como atribuição, uma outra
// matriz.

template <class type>
void matrix<type>::operator=(const matrix &M)
{
    i = M.i;
    j = M.j;
    size = M.size;

    error = M.error;

    set(M.Matrix);
}



//============================================================================
// O operador () pode ser utilizado como uma substituição para [i][j] Ex:
// No lugar de 
//     Matrix[i][j];
// Deve-se usar
//     Matrix(i, j);

template <class type>
type& matrix<type>::operator()(int line, int colun)
{
    if((line >= 0 && colun >= 0) && (line < i && colun < j))
        return Matrix[line * j + colun];
}



//============================================================================
// Calcula da determinante da matriz armazenada.

template <class type>
type matrix<type>::getDet(void)
{
    // Vamos verificar se a matriz é quadrada.
    if(i != j){error = 1; return (type)0;}

    return determinantOfMatrix(j, Matrix, j);
}



///////// Formated Output. ////////////////////////////////////////////////////

//============================================================================
// Imprime os valores da matriz na tela, de maneira formatada

template <class type>
void matrix<type>::print(void)
{
    stringstream lenght; // This convert the value of a position to a string.
    // and this one, take the max lenght inside the matrix
    int str_lenght = 0;



    for(int c = 0; c < (i * j); c++)
    {
        lenght << Matrix[c];
        if(lenght.str().size() > str_lenght)
            str_lenght = lenght.str().size();
        lenght.str("");
    }



    for(int line = 0; line < i; line++)
    {
        for(int colun = 0; colun < j; colun++)
        {
            cout << "[" << setw(str_lenght) << Matrix[line * j + colun] << "]";
        }
        cout << endl;
    }
}



/////////////////////////////
// ---Funções Privadas --- //
/////////////////////////////

//=============================================================================
// Função para calcular fator.
// Adaptado de https://www.geeksforgeeks.org/determinant-of-a-matrix/

template <class type>
void matrix<type>::getCofactor(int size, type mat[], type temp[], int p, int q, int n)
{
    int i = 0, j = 0; 
  
    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            //  Copying into temporary matrix only those element 
            //  which are not in given row and column 
            if (row != p && col != q) 
            { 
                temp[(i * size) + (j++)] = mat[row * size + col]; 
  
                // Row is filled, so increase row index and 
                // reset col index 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
}



//============================================================================
// Função para calcular a determinante de uma matriz.
// Adaptado de https://www.geeksforgeeks.org/determinant-of-a-matrix/

template <class type>
type matrix<type>::determinantOfMatrix(int size, type mat[], int n)
{
    type D = 0; // Initialize result 
  
    //  Base case : if matrix contains single element 
    if (n == 1) 
        return mat[0]; 
  
    type temp[size * size]; // To store cofactors 
  
    type sign = 1;  // To store sign multiplier 
  
     // Iterate for each element of first row 
    for (int f = 0; f < n; f++) 
    { 
        // Getting Cofactor of mat[0][f] 
        getCofactor(size, mat, temp, 0, f, n); 
        D += sign * mat[f] * determinantOfMatrix(size, temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign;
    } 
  
    return D;
}


#endif // _MATRIX_CPP_
