#include<iostream>
#include<algorithm>
using namespace std;
const int max_n=1000+5,max_w=1000+5;
int w,arr[max_n],temp[max_n][max_w][2]={0},n;
int main()
{
	//Read
	cin>>w>>n;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	//Solve
	for(int i=0; i<=w; i++)
	{
		temp[0][i][1]=0;
		temp[0][i][0]=0;
		if(arr[n]==2)
			temp[1][i][1]=1;
		else
			temp[1][i][0]=1;
	}	
	for (int i=2; i<=n; i++)
		for(int j=0; j<=w; j++)
		{
			if(arr[n-i+1]==1)
			{
				temp[i][j][0]=max(temp[i-1][j][0]+1,temp[i-1][j-1][1]+1);
				temp[i][j][1]=max(temp[i-1][j][1],temp[i-1][j-1][0]);
			}			
			else
			{
				temp[i][j][0]=max(temp[i-1][j][0],temp[i-1][j-1][1]);
				temp[i][j][1]=max(temp[i-1][j][1]+1,temp[i-1][j-1][0]+1);
			}
		}
	//write
		cout<<temp[n][w][1]<<endl;
	return 0;
}
