#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("words.txt");

const int maxN = 100 + 8;

int tri[maxN];

int main ()
{
	int ans = 0, sum = 0;
	for (int i = 0; i < 100; i++)
		tri[i] = i * (i + 1) / 2;
	string s;
	fin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ',')
		{
			for (int j = 0; j < 100; j++)
				if (sum == tri[j])
					ans++;
			sum = 0;
		}
		if (s[i] != '"' && s[i] != ',')
			sum += s[i] - 'A' + 1;
	}
	for (int j = 0; j < 100; j++)
		if (sum == tri[j])
			ans++;
	cout << ans << endl;
	return 0;
}