#include <iostream>

using namespace std;

const int MAX_F = 500 + 50, MAX_N = 1000 * 1000 * 1000;

int n, fib[MAX_F];

bool output(int x, int a)
{
    if (x == 0)
        return a == 0;
    
    for (int i = 0; fib[i] <= a; i++)
        if (output(x - 1, a - fib[i]))
        {
            cout << fib[i] << " ";
            return true;
        }
    
    return false;
}

int main()
{
    cin >> n;
    
    fib[1] = 1;
    fib[0] = 0;
    for (int i = 2; fib[i - 1] < MAX_N; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    output(3, n);
    
    return 0;
}