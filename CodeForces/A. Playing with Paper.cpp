#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, cnt = 0;
    cin >> a >> b;
    
    while(b != 0)
    {
        cnt += a / b;
        a = a % b;
        swap(a, b);
    }
    
    cout << cnt << endl;
    
    return 0;
}