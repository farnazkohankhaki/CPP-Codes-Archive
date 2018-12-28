#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=16000+5;
int main()
{
    int n, sum=0, end;
    pair<int,int>a[MAX_N];
    cin>>n;
    for(int i=0; i<n ;i++)
            cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    end= a[0].second;
    for(int i=0; i<n; i++)
    {
            if(a[i].second<end) 
                sum++;    
            if(a[i].second>end) 
                end=a[i].second;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
