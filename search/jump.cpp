#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::min;

int jump_search(int A[] , int n , int K)
{
    int m = sqrt(n);
    int prev = 0;
    while (A[min(m , n) - 1] < K)
    {
        prev = m;
        m++;
        if (prev >= n)
            return -1;
    }

    while (A[prev] < K)
    {
        prev++;
        if (prev == min(m , n))
            return -1;
    }

    if (A[prev] == K)
        return prev + 1;

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    int k;
    cin >> k;
    
    int pos = jump_search(A , n , k);
    if (pos == -1)
        cout << "Not Found\n";
    else
        cout << "Found at " << pos << "\n";
    return 0;
}