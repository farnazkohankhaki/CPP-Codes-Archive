#include <iostream>

using namespace std;

bool mark[10];
int n;

void output()
{
	if (n == 1)
	{
		cout << 8 << endl;
		return;
	}
	
	mark[1] = mark[2] = mark[5] = true;
	if ((n + 5) % 6 == 0)
		mark[7] = true;
	if ((n + 2) % 3 == 0)
		mark[3] = mark[6] = true;
	if ((n + 8) % 9 == 0)
		mark[9] = true;
	
	int cnt = 0;
	for (int i = 1; i < 10; i++)
		if (mark[i] && mark[i + 1])
			cnt++;
	
	cout << cnt << endl;
	
	return;
}

int main()
{
	cin >> n;
	output();
	return 0;
}
