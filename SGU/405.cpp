#include <iostream>

using namespace std;

const int maxA = 100 + 8;

int s[maxA] = {0};
int main()
{
	int n, m, a, b, c, d;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < n; j++)
		{
			cin >> c >> d;
			if (a > b && c > d)
				s[j] += 2;
			if (a < b && c < d)
				s[j] += 2;
			if (a == b && c == d)
				s[j] += 2;
			if (a - b == c - d)
				s[j] += 3;
			if (a == c)
				s[j]++;
			if (b == d)
				s[j]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}