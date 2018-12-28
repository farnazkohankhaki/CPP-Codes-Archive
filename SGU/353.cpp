#include <iostream>

using namespace std;

int main()
{	
	int n, k1, k2, p1, p2, p3, maxs = 0, cnt = 0;
	cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
	n -= p1;
	if (n >= 0)
		maxs += k1;
	while (n > 0 && cnt < k2)
	{
		cnt++;
		maxs++;
		n -= p2;
	}
	while (n > 0)
	{
		n -= p3;
		maxs++;
	}
	cout << maxs << endl;
	return 0;
}
