#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxN = 1000+8;

bool mark[maxN];
int d[maxN];
vector <int> a[maxN], s;
vector <string> frnd;

void bfs(int t)
{
	s.push_back(t);
	int f = 0;
	d[t] = 0;
	mark[t] = 1;
	while (f!= s.size())
	{
		for (int i = 0; i < a[s[f]].size(); i++)
		{
			if (!mark[a[s[f]][i]])
			{
				s.push_back(a[s[f]][i]);
				d[a[s[f]][i]] = d[s[f]]+1;
				mark[a[s[f]][i]] = true;
			}
		}
		f++;
	}
}

int main()
{
	int m, t = 1;
	cin >> m;
	string s1, s2;
	map <string, int> name;
	name["Goli"] = 1;
	frnd.push_back("Goli");
	for (int i = 0; i < m; i++)
	{
		cin >> s1 >> s2;
		if (name.find(s1) == name.end())
		{	
			t++;
			name[s1] = t;
			frnd.push_back(s1);
		}
		if (name.find(s2) == name.end())
		{	
			t++;
			name[s2] = t;
			frnd.push_back(s2);
		}
		a[name[s1]].push_back(name[s2]);
		a[name[s2]].push_back(name[s1]);
	}
	bfs (1);
	for (int i = 1; i < t; i++)
		cout << frnd[i] << ": " << d[i+1] << endl;
	return 0;
}