#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=103;
int n,a[N],f[N][N][N];
int Dfs(int x,int l,int r)
{
	if(x>n)return l<=n?N:0;
	int &s=f[x][l][r];
	if(s!=-1)return s;
	s=Dfs(x+1,l<x?l:x+(r>x),max(x+1,r));
	int lb=max(x-a[x]+1,1),rb=min(n,x+a[x]-1);
	if(lb<=l)s=min(s,Dfs(x+1,x+1,max(x+1,r))+1);
	s=min(s,Dfs(x+1,l==x?x+1:l,max(r,rb+1))+1);
	return s;
}
void Solve()
{
	cin>>n;memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<Dfs(1,1,1)<<endl; 
}
int main()
{
	int T;cin>>T;
	while(T--)Solve();
	return 0;
}
