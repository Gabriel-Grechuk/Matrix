
/******************************************************************************
 * .h File for a class that can handle and manage a matrix.
 ******************************************************************************
 * Copyright (c) 2018 Gabriel Grechuk da Silva Oliveira
 * 
 * Under the MIT License. Checkout the LICENSE.txt file.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

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
