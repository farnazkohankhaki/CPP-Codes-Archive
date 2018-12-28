#include <iostream>

using namespace std;

int n, m;

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '-')
				cout << '-';
			else if ((i + j) % 2)
				cout << 'W';
			else
				cout << 'B';
		}
		cout << endl;
	}
	
	return 0;
}