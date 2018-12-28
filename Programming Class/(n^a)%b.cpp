#include <iostream>

using namespace std;

int n, a, b = 736;

int main()
{
	cin >> n >> a;
	int k = 1;
	for (int i = 0; i < a; i++)
	{
		k *= n;
		k %= b;
	}
	cout << k << endl;
	return 0;
}