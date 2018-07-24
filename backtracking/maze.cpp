#include <iostream>

using std::cout;

bool isSafe(int N , int *A , int x , int y)
{
    if (x >= 0 && y >= 0 && y < N && *((A + x * N) + y) == 1)
        return true;
    return false;
}

bool solveMazeUtil(int N , int *A , int x , int y , int *sol)
{
    if (x == N - 1 && y == N - 1)
    {
        *((sol + x * N) + y) = 1;
        return true;
    }

    if (isSafe(N , A , x , y))
    {
        *((sol + x * N) + y) = 1;

        if (solveMazeUtil(N , A , x + 1 , y , sol))
            return true;

        if (solveMazeUtil(N , A , x , y + 1 , sol))
            return true;

        *((sol + x * N) + y) = 0;
        return false;
    }
    return false;
}

void printSolution(int N , int *sol)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << *((sol + i * N) + j) << " ";
        cout << "\n";
    }
}

bool solveMaze(int N , int *A)
{
    int sol[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            sol[i][j] = 0;
    }

    if (!solveMazeUtil(N , A , 0 , 0 , *sol))
    {
        cout << "Solution is Not possible\n";
        return false;
    }
    printSolution(N , *sol);
    return true;
}

int main()
{
    int N = 4;
    int A[N][N] = {
        {1 , 0 , 0 , 0},
        {1 , 1 , 0 , 1},
        {0 , 1 , 0 , 0},
        {1 , 1 , 1 , 1}
    };
    solveMaze(N , (*A));
    return 0;
}