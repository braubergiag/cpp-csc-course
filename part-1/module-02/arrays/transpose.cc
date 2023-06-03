#include <cstdlib>
#include <limits>
#include <iostream>

int ** create2dArray(unsigned rows, unsigned cols){
    int ** m = new int * [rows];
    for (auto i{0}; i < rows; ++i){
        m[i] = new int[cols];
    }

    return m;
}


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    auto t = create2dArray(cols,rows);
     for (auto i{0}; i < rows; ++i){
        for (auto j{0}; j < cols;++j){
            t[j][i] = m[i][j];
        }
    }

    return t;

}

void fill2dArray(int *m[], unsigned rows, unsigned cols){

    for (auto i{0}; i < rows; ++i){
        for (auto j{0}; j < cols;++j){
            m[i][j] = i + j;
        }
    }
}


void print2dArray(int *m[], unsigned rows, unsigned cols){
    for (auto i{0}; i < rows; ++i){
        for (auto j{0}; j < cols;++j){
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
     std::cout << "\n";
}


void delete2dArray(int *m[], unsigned rows, unsigned cols){
    for (size_t i = 0; i <  rows; i++)
    {
        delete[] m[i];
    }

    delete[] m;
    
}


int main(){

    size_t nrows{2}, ncols{5};
    auto m = create2dArray(nrows,ncols);
    fill2dArray(m,nrows,ncols);
    print2dArray(m,nrows,ncols);

    auto t = transpose(m,nrows,ncols);

    print2dArray(t,ncols,nrows);


    
}