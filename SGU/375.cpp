#include <iostream>
#include <vector>

using namespace std;

vector <int> ans;

int main()
{
	long long n, x;
	cin >> n;
	ans.clear();
	while (n % 2 != 0 && n != 1)
	{
		x = (n - 1) / 2;
		if (x % 2 == 1)
		{
			ans.push_back (2);
			n = (n - 1) / 2;
		}
		else
		{
			ans.push_back (1);
			n = (n + 1) / 2;
		}
	}
	if (n == 1)
	{
		cout << ans.size() << endl;
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
	}
	else
		cout << "No solution";
	cout << endl;
	return 0;
}