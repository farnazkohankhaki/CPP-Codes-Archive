#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	float x, y, z, r, a, t;
	cin >> x >> y >> z;
	cout<<setprecision(7);
	r = (y-x)*60;
    t = r*r;
	if(r<z || r==z)
		cout << 1 << endl;
	if(r>z && r<2*z)
		cout << ( r*(2*z-r) + (z+r)*(r-z) )/t << endl;
	if(r >= 2*z)
		cout << ( (3*z*z) + (2*z*(r-2*z)) )/t << endl;
    return 0;
}
