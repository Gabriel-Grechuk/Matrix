// Opa, vamo brinca agr

#include <cstdlib>
#include <iostream>
#include <string>

#include "matrix/matrix.h"

using namespace std;


int main(int argc, char *argv[])
{
    int size = 1;


    // Verificando a integridade das entradas.
    if(argc == 1)
    {
        cout << "É preciso entrar os tamanho da matriz." << endl;
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
            cout << "Linha " << i + 1 << ": " << endl;
            for(int j = 0; j < size; j++)
            {
                cout << "Entre o elemento " << j + 1 << ": ";
                cin >> Mat(i, j);
            }
            cout << endl;
        }
    }


    Mat.print();
    cout << endl;

    cout << "Determinante da matriz é: " << Mat.getDet() << endl; 
    return 0;
}
