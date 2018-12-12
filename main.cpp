/******************************************************************************
 * This class have the objective to store a number and convert it for any kind
 * of handable for the user. 
 ******************************************************************************
 * Copyright (c) 2018 Gabriel Grechuk da Silva Oliveira
 * 
 * Under the MIT License. Checkout the LICENSE.txt file.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

#include "matrix_class/matrix.h"

using namespace std;


int main(int argc, char *argv[])
{
    int size = 1;


    // Verificando a integridade das entradas.
    if(argc == 1)
    {
        cout << "You must enter the dimensions of the matrix." << endl
             << "Ex: \"Matrix\" 3 for 3x3 matrix." << endl;
        return -1;
    }


    size = atoi(argv[1]);
    matrix<double> Mat(size, size);


    if(argc > 2)
    {
        // TODO.
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << "Line " << i + 1 << ": " << endl;
            for(int j = 0; j < size; j++)
            {
                cout << "Enter the element " << j + 1 << ": ";
                cin >> Mat(i, j);
            }
            cout << endl;
        }
    }


    Mat.print();
    cout << endl;

    cout << "The determinant of the matrix is: " << Mat.getDet() << endl; 
    return 0;
}
