#include <iostream>

using namespace std;

typedef long long ll;

const string s[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

ll n;

int main ()
{
	cin >> n;
	
	ll l = 5;
	
	while (l < n)
	{
		n -= l;
		l *= 2;
	}
	
	l /= 5;
	
	int i;
	for (i = 0; n > l ; i++)
	{
		n -= l;
	}
	
	cout << s[i] << endl;
	
	return 0;
}