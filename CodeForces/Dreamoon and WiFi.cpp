#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

string s1, s2;

int mb = 0, p = 0, q = 0;

int c (int x, int y)
{
	int ans = 1;
	for (int i = 2; i <= x; i++)
		ans *= i;
	for (int i = 2; i <= y; i++)
		ans /= i;
	for (int i = 2; i <= x - y; i++)
		ans /= i;
	return ans;
}

double output()
{
	int a = abs (mb - p);
	if (q < a)
		return 0;
	int x = a + (q - a) / 2;
	double ans = c (q, x) / pow (2, q);
	
	return ans;
}

int main()
{
	cin >> s1 >> s2;
	
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] == '+')
			mb++;
		else
			mb--;
	
	for (int i = 0; i < s2.size(); i++)
		if (s2[i] == '+')
			p++;
		else if (s2[i] == '-')
			p--;
		else
			q++;
	
	cout << fixed << setprecision (9) << output() << endl;
	
	return 0;
}