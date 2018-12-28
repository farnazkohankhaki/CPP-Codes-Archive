#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const int MAX_N=100+5;
vector <int> arr[MAX_N];
int n, t[MAX_N];
bool mark[MAX_N];

int dfs(int v)
{
    mark[v]=1;
    int max1=-1, max2=-1, k;
    for(int i=0; i<arr[v].size(); i++)
    {
        if(!mark[arr[v][i]])
        {
            k= dfs(arr[v][i]);
            if(max1<k)
            {
                max2= max1;
                max1= k;   
            }
            else if(max2<k)
                max2=k;
        }
    }
    t[v]= max1+max2+2;
    return max1+1;
}

int main()
{
    int a, b, g=0;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>a>>b;
		arr[b].push_back(a);
		arr[a].push_back(b);
    }
    int w= dfs(1);
    for(int i=1; i<=n; i++)
        g=max(g, t[i]);
    cout<<g;
    return 0;
}
