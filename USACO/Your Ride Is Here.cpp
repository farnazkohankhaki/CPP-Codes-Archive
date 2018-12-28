/*
ID: fkohan1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");

int main()
{
    string a, b;
    fin>>a>>b;
    int ja=1, jb=1;
    for(int i=0; i<a.size(); i++)
        ja*= (a[i]-'A'+1);
    for(int i=0; i<b.size(); i++)
        jb*= (b[i]-'A'+1);
    if( jb%47 == ja%47)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}
