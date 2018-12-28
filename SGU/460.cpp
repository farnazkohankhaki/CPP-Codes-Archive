#include <iostream>

using namespace std;

const int maxN = 10 + 8;
string r[maxN];

int main()
{
	int n;
	string m;
	bool f;
	cin >> n;
	for (int i = 0; i < n; i++)
		r[i].clear();
	for (int i = 0; i < n; i++)
	{
		f = 1;
		cin >> m;
		int x = m.size();
		if (m[x - 1] == 'x' || m[x - 1] == 's' || m[x - 1] == 'o' || (m[x - 2] == 'c' && m[x - 1] == 'h'))
		{
			f = 0;
			r[i] += m;
			r[i] += "es";
		}
		if (m[x - 1] == 'f')
		{
			f = 0;
			for (int j = 0; j < x - 1; j++)
				r[i] += m[j];
			r[i] += "ves";
		}
		if (m[x - 2] == 'f' && m[x - 1] == 'e')
		{
			f = 0;
			for (int j = 0; j < x - 2; j++)
				r[i] += m[j];
			r[i] += "ves";
		}
		if (m[x - 1] == 'y')
		{
			f = 0;
			for (int j = 0; j < x - 1; j++)
				r[i] += m[j];
			r[i] += "ies";
		}
		if (f)
		{
			r[i] += m;
			r[i] += "s";
		}
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << endl;
	return 0;
}
