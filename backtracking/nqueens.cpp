#include <iostream>

using std::cout;

bool isSafe(int N , int *A , int x , int y)
{
    for (int i = 0; i < N; ++i)
        if (*((A + x * N) + i) == 1)
            return false;
    
    for (int i = 0; i < N; ++i)
        if (*((A + i * N) + y) == 1)
            return false;

    for (int i = x , j = y; i >= 0 && j >= 0; --i , --j)
        if (*((A + i * N) + j) == 1)
            return false;

    for (int i = x , j = y; i < N && j >= 0; ++i , --j)
        if (*((A + i * N) + j) == 1)
            return false;
    
    return true;
}

bool NQueen(int N , int *A , int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i)
    {
        if (isSafe(N , A , i , col))
        {
            *((A + i * N) + col) = 1;
            if (NQueen(N , A , col + 1))
                return true;
            *((A + i * N) + col) = 0;
        }
    }
    return false;
}

void printSolution(int N , int *A)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << *((A + i * N) + j) << " ";
        cout << "\n";
    }
}

int main()
{
    int N = 5;
    int A[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            A[i][j] = 0;
    }
    if (!NQueen(N , *A , 0))
        cout << "Solution Does Not Exist\n";
    else
        printSolution(N , *A);
    return 0;
}