#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    string a;
    for(int i=0; i<n; i++)
    {
        a = "";
        cin >> a;
        if( a.size() < 11 )
            cout << a << endl;
        else
            cout << a[0] << a.size()-2 << a[a.size()-1] << endl;
    }
    return 0;
}
        
