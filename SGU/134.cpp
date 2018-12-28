#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N=16000+8;
int n, c[MAX_N];
bool mark[MAX_N];
vector <int> arr[MAX_N];   
int DFS(int v)
{
    int sum=1, m=0, f;
    mark[v]=true;
    for(int i=0; i<arr[v].size(); i++)
    {
        if(!mark[arr[v][i]])
        {
            f=DFS(arr[v][i]);
            m=max(f,m);
            sum+=f;
        }
    }
    c[v]=max(m,n-sum);
    return sum;
}
            
int main()
{
    int u,v,k,f,sum=0;
    vector <int> m;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    k=DFS(1);
    f=c[1];
    for(int i=1; i<=n; i++)
        f=min(f, c[i]);
    for(int i=1; i<=n; i++)
        if(c[i]==f)
        {
            sum++;
            m.push_back(i);
        }
    cout<<f<<" "<<sum<<endl;
    for(int i=0; i<m.size(); i++)
        cout<<m[i]<<" ";
    system("pause");
    return 0;
}
