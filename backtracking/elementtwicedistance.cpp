#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void all_combinations_util(vector<int> arr , int elem , int n)
{
    if (elem > n)
    {
        for (int i = 0; i < arr.size(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }

    for (int i = 0; i < 2 * n; ++i)
    {
        if (arr[i] == -1 && (i + elem + 1) < 2 * n && arr[i + elem + 1] == -1)
        {
            arr[i] = elem;
            arr[i + elem + 1] = elem;

            all_combinations_util(arr , elem + 1 , n);

            arr[i] = -1;
            arr[i + elem + 1] = -1;
        }
    }
}

void print_combinations(int n)
{
    vector<int> arr(2 * n , -1);
    int elem = 1;
    all_combinations_util(arr , elem , n);
}

int main()
{
    int n = 3;
    print_combinations(n);
    return 0;
}