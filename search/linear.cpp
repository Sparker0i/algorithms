#include <iostream>

using std::cin;
using std::cout;

int linear_search(int A[] , int N , int k)
{
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == k)
            return i + 1;
    }
    cout << "\n";
    return -1;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int K;
    cin >> K;
    int pos = linear_search(A , N , K);
    /*if (pos == -1)
        cout << "Not Found\n";
    else
        */cout << "Found at position " << pos << "\n";
    return 0;
}