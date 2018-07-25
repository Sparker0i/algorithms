#include <iostream>
#include <string>

using std::cout;
using std::string;

void power_set(string str , int index , string curr)
{
    int n = str.length();

    if (index == n)
    {
        cout << curr << "\n";
        return;
    }

    power_set(str , index + 1 , curr + str[index]);
    power_set(str , index + 1 , curr);
}

int main()
{
    string str = "abcd";
    power_set(str , 0 , "");
    return 0;
}