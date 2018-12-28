// Print Prime Numbers

#include <iostream>

using namespace std;

const int maxM = 10000+8;

bool mark[maxM];

void prime (int m)
{
	for (int i = 2; i <= m; i++)
		if (mark[i] == false)
		{
			cout << i <<" ";
			for (int j = 2; j <= m/i; j++)
				mark[i*j] = true;
		}
	cout << endl;
}

int main()
{
	int m;
	cin >> m;
	prime (m);
	cout << cnt << endl;
	return 0;
}