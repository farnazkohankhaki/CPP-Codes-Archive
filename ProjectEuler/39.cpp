#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 100;

int n = 1000, s[MAXN];

int findS(int x)
{
	int r = 0;
	for (int i = 1; i < x - 1; i++)
		for (int j = 1; j < x - i; j++)
		{
			int a = i, b = j, c = x - i - j;
			if (a > b)
				swap (a, b);
			if (b > c)
				swap (b, c);
			if (c * c == a * a + b * b)
				r++;
		}
	return r / 6;
}

int main()
{
	for (int i = 1; i <= n; i++)
		s[i] = findS(i);
	cout << max_element(s + 1, s + 1 + n) - s << endl;
	return 0;
}