#include <iostream>
#include <vector>

using namespace std;

const int MAXL = 200 + 20, MAXN = 200 * 1000 + 20000, FV = 48, LV = 122;

int n, inDeg[MAXL][MAXL], st[MAXL][MAXL];
string s[MAXN], tour = "";
bool mark[MAXN];
vector <int> v[MAXL][MAXL];

void init()
{
    for (int i = 0; i < n; i++)
    {
        int x = s[i][0], y = s[i][1], z = s[i][2];
        v[x][y].push_back(i);
        inDeg[y][z]++;
    }
    
    return;
}

void eul(int x, int y)
{
    for (; st[x][y] < v[x][y].size(); st[x][y]++)
    {
        int e = v[x][y][st[x][y]];
        if (!mark[e])
        {
            mark[e] = true;
            eul(y, (int)s[e][2]);
        }
    }
    
    tour += (char)y;

    return;
}

void output()
{
    int tmp, stvX = 0, stvY = 0, cnt = 0;
    for (int i = FV; i <= LV; i++)
        for (int j = FV; j <= LV; j++)
        {
            if (inDeg[i][j] + 1 == v[i][j].size())
            {
                stvX = i;
                stvY = j;
            }
            if (v[i][j].size() > 0 && stvX == 0)
            {
                stvX = i;
                stvY = j;
            }
            if (inDeg[i][j] != v[i][j].size())
                cnt++;
            
            int mns = inDeg[i][j] - v[i][j].size();
            if (mns < 0)
                mns *= -1;
            if (mns > 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    
    if (cnt > 2)
    {
        cout << "NO" << endl;
        return;
    }
    
    eul (stvX, stvY);
    tour += (char)stvX;

    for (int i = 0; i < n; i++)
        if (!mark[i])
        {
            cout << "NO" << endl;
            return;
        }
    
    cout << "YES" << endl;
    for (int i = tour.size() - 1; i >= 0; i--)
        cout << tour[i];
    cout << endl;
    
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
  
    init();
    
    output();
    
    return 0;
}