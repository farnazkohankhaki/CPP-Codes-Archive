#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    a = n * (n + 1) * (2 * n + 1) / 6;
    b = n * (n + 1) * n * (n + 1) /4;
    cout << b - a << endl;
    return 0;
}
