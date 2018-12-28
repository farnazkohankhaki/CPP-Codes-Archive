#include <iostream>

using namespace std;

int main ()
{
	int n, m, sum = 0, tmp;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	cout << sum % n << endl;
	return 0;
}