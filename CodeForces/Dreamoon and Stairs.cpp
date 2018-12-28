#include <iostream>

using namespace std;

int n, m;

int output()
{
	for (int i = (n + 1) / 2; i <= n; i++)
		if (i % m == 0)
			return i;
	return -1;
}

int main()
{
	cin >> n >> m;
	
	cout << output() << endl;
	
	return 0;
}