#include<iostream>
using namespace std;
const int MAX_N=100+5,MAX_M=100+5;
int arr[MAX_N][MAX_M],is[MAX_N][MAX_M];
int n,m;
int main ()
{
	int v[MAX_N];
	cin>>n>>m;
	for (int i=0; i<n; i++)
	{
		cin>>v[i];
		arr[i][0]=1;
	}
	cout<<endl;
	for(int w=0; w<=m; w++)
		arr[0][w]=0;
	arr[0][v[0]]=1;
	arr[0][0]=1;
	is[0][v[0]]=1;
	for (int j=1; j<n; j++)
	{
		for(int k=1; k<=m; k++)
		{
			if (arr[j-1][k]==1)
			{
				arr[j][k]=1;
				is[j][k]=0;
			}
			else if (arr[j-1][k-v[j]]==1)
			{
				arr[j][k]=1;
				is[j][k]=1;
			}
		}
	}
	int f=0;
	for(int p=m; p>=0; p--)
	{
		  if (arr[n-1][p]==1)
		  {
			f=p;
			cout<<f<<endl;
			break;
		  }
	}
	for (int l=n-1; l>=0; l--)
	{
		cout<<"["<<l<<"]= "<<is[l][f]<<endl;
		if(is[l][f]==1)
			f=f-v[l];
	}
	return 0;
}
