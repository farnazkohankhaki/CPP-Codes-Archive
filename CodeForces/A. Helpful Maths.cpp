#include <iostream>

using namespace std;

string s;
int num[3];

int main()
{
    cin >> s;
    
    for (int i = 0; i < s.size(); i += 2)
        num[s[i] - '0' - 1]++;
    string t = "";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < num[i]; j++)
            t += (char)(i + (int)'0' + 1);
    for (int i = 0; i < t.size() - 1; i++)
        cout << t[i] << '+';
    cout << t[t.size() - 1] << endl;
    
    return 0;
}