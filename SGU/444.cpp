#include <iostream>

using namespace std;

const int maxN = 1000000 + 8;

int s[maxN][2] = {{0}};

int main()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	a = a % b;
	while (!s[a][0])
	{
		s[a][0] = 1;
		s[a][1] = cnt;
		a = (a * 10) % b;
		cnt++;
	}
	if (a == 0)
		cout << cnt - 1 << " " << "0" << endl;
	else
		cout << s[a][1] << " " << cnt - s[a][1] << endl;
	return 0;
}