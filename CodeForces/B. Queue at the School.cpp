#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50 + 5;

int n, t;
string s;
bool mark[MAX_N];

int main()
{
    cin >> n >> t >> s;
    
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
            mark[j] = false;
        for (int j = 0; j < n - 1; j++)
            if (s[j] == 'B' && s[j + 1] == 'G')
                mark[j] = true;
        for (int j = 0; j < n; j++)
            if (mark[j])
                swap(s[j], s[j + 1]);
    }
    
    cout << s << endl;
    
    return 0;
}