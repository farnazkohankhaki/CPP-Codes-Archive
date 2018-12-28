#include <iostream>
#include <cmath>

using namespace std;

int n, a, g;

int main()
{
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (abs(a + x - g) <= 500)
		{
			a += x;
			cout << "A";
		}
		else
		{
			g += y;
			cout << "G";
		}
	}
	cout << endl;
	return 0;
}