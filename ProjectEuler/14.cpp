#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 1000 * 10 + 1000;

int l[MAXN], n;

void find(int x)
{
	long long y = x;
	int cnt = 0;
	while (y != 1)
	{
		if (y < x)
		{
			cnt += l[y];
			break;
		}
		cnt++;
		if (y % 2 == 0)
			y /= 2;
		else
			y = 3 * y + 1;
	}
	l[x] = cnt;
}
		   
int main()
{
	cin >> n;
	for (int i = 2; i < n; i++)
		find(i);
	cout << max_element(l, l + n) - l << endl;
	return 0;
}