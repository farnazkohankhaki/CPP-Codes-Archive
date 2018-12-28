#include <iostream>

using namespace std;

int main()
{
	int s, p, t;
	cin >> s >> p;
	if (p - s == 0)
		cout << "0" << endl;
	if (p - s > 0 && p - s < 300)
		cout << "1" << endl;
	if (p - s >= 300 && p - s < 900)
		cout << "2" << endl;
	if (p - s >= 900 && p - s < 1800)
		cout << "3" << endl;
	if (p - s >= 1800)
		cout << "4" << endl;
	return 0;
}