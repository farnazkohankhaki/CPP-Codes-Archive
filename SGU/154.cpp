#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long q, n, tmp, cnt = 0;
	bool r = 0;
	cin >> q;
	n = q * 4 - 1;
	while (cnt < q)
	{
		cnt = 0;
		n++;
		for (int i = 1; i <= 15; i++)
			cnt += n / pow ((double)5, (double)i);
		if (cnt == q)
		{
			r = 1;
			break;
		}
	}
	if (q != 0)
	{
		if (r)
			cout << n << endl;
		else
			cout << "NO" << endl;
	}
	else
		cout << 1 << endl;
	return 0;
}