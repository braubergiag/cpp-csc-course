#include <cstdlib>
#include <limits>
#include <iostream>


void swap_min(int *m[], unsigned rows, unsigned cols)
{
    /* ... */
    int current_min = std::numeric_limits<int>::max();
    int current_min_row_idx{};
     for (auto i{0}; i < rows; ++i){
        for (auto j{0}; j < cols;++j){
            if (m[i][j] < current_min) {
                current_min = m[i][j];
                current_min_row_idx = i;
            }
        }
    }
    int * first_row = m[0];
    m[0] = m[current_min_row_idx];
    m[current_min_row_idx] = first_row;

}

void fill2dArray(int *m[], unsigned rows, unsigned cols){

    for (auto i{0}; i < rows; ++i){
        for (auto j{0}; j < cols;++j){
            m[i][j] = i + j;
        }
    }
    m[2][2] = -10;
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

int ** create2dArray(unsigned rows, unsigned cols){
    int ** m = new int * [rows];
    for (auto i{0}; i < rows; ++i){
        m[i] = new int[cols];
    }

    return m;
}
void delete2dArray(int *m[], unsigned rows, unsigned cols){
    for (size_t i = 0; i <  rows; i++)
    {
        delete[] m[i];
    }

    delete[] m;
    
}


int main(){

    size_t nrows{3}, ncols{4};
    auto m = create2dArray(nrows,ncols);
    fill2dArray(m,nrows,ncols);
    print2dArray(m,nrows,ncols);

    swap_min(m,nrows,ncols);

    print2dArray(m,nrows,ncols);
    delete2dArray(m,nrows,ncols);

    
}