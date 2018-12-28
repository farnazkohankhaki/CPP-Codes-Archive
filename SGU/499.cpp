#include <iostream>
#include <algorithm>

using namespace std;


long long arr[100008], r[1000008], s[1000008];

int main()
{
    long long max=0, n;
    cin>>n;
    for(long long j=0; j<n; j++)
    {
        cin>>arr[j];
        s[arr[j]]++;
        if(arr[j]>max)
            max=arr[j];
    }
    for(long long i=1; i<=max; i++)
        for(long long j=i; j<=max; j+=i)
            if(s[j]>0)
                r[i]++;
    for(long long i=max; i>0; i--)
        if(r[i]>1)
        {
            cout<<i<<endl; 
            break;
        }   
    system("pause");
    return 0;
}
    
        
