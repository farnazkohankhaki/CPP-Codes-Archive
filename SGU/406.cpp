#include <iostream>
#include <vector>

using namespace std;

const int maxA = 10 + 8;
vector <int> s[maxA], q[maxA], aq[maxA];

int main ()
{
	bool f, t;
	int n, m, tmp, tmp2;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		s[i].clear();
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			cin >> tmp2;
			s[i].push_back (tmp2);
		}
	}
	for (int i = 0; i < m; i++)
	{
		q[i].clear();
		aq[i].clear();
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			cin >> tmp2;
			q[i].push_back (tmp2);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f = 1;
			for (int l = 0; l < q[i].size(); l++)
				if (q[i][l] < 0)
					for (int k = 0; k < s[j].size(); k++)
						if (s[j][k] == -1 * q[i][l])
							f = 0;
			
			for (int l = 0; l < q[i].size(); l++)
				if (q[i][l] > 0)
				{
					t = 0;
					for (int k = 0; k < s[j].size(); k++)
						if (s[j][k] == q[i][l])
							t = 1;
					if (!t)
						f = 0;
				}	
			if (f)
				aq[i].push_back (j);
		}
		cout << aq[i].size() << endl;
		for (int j = 0; j < aq[i].size(); j++)
		{
			cout << s[aq[i][j]].size();
			for (int l = 0; l < s[aq[i][j]].size(); l++)
				cout << " " << s[aq[i][j]][l];
			cout << endl;
		}
	}
	return 0;
}