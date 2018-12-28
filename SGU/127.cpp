#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=8000+5;
int main()
{
	int sum=3, k, n, m=1, f, arr[MAX_N];
	cin>>k>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr,arr+n);
	f=arr[0]/1000;
	for(int i=0; i<n; i++)
	{
		if( m>k || arr[i]/1000!=f)
		{
			m=2;
			sum++;
			f=arr[i]/1000;
		}
		else
			m++;
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}
