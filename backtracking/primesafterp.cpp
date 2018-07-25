#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= n/2; ++i)
        if (!(n % i))
            return false;

    return true;
}

void display(vector<int> set)
{
    for (int i = 0; i < set.size(); ++i)
    {
        cout << set[i] << " ";
    }
    cout << "\n";
}

vector<int> prime_sum(int total , int N , int S , int index , vector<int> set , vector<int> primes)
{
    if (total == S && set.size() == N)
    {
        display(set);
        return set;
    }

    if (total > S || index == primes.size())
        return set;

    set.push_back(primes[index]);
    set = prime_sum(total + primes[index] , N , S , index + 1 , set , primes);
    set.pop_back();
    set = prime_sum(total , N , S , index + 1 , set , primes);
    return set;
}

void calculate_primes(int S , int N , int P)
{
    vector<int> primes;
    vector<int> set;
    for (int i = P + 1; i <= S; ++i)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    if (primes.size() < N)
        return;

    prime_sum(0 , N , S , 0 , set , primes);
}

int main()
{
    int S , N , P;
    cin >> S >> N >> P;
    calculate_primes(S , N , P);
    return 0;
}