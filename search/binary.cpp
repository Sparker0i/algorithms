#include <iostream>

using std::cin;
using std::cout;

int binary_search(int A[] , int L , int R , int K)
{
    if (R >= L)
    {
        int mid = L + ((R - L)/ 2);
        if (A[mid] == K)
            return mid + 1;
        else if (K > A[mid])
            return binary_search(A , mid + 1 , R , K);
        else
            return binary_search(A , L , mid - 1 , K);
    }
    else
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
    int pos = binary_search(A , 0 , N - 1 , K);
    if (pos == -1)
        cout << "Not Found\n";
    else
        cout << "Found at position " << pos << "\n";
    return 0;
}