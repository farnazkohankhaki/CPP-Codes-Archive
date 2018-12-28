#include <iostream>

using namespace std;

int t[10] = {0};

int main()
{
	int n = 0, m = 0;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[i])
			n++;
		else
		{
			t[a[i] - '0']++;
			t[b[i] - '0']++;
		}
	}
	for (int i = 0; i <= 9; i++)
		m += t[i] / 2;
	cout << n << " " << m << endl;
}