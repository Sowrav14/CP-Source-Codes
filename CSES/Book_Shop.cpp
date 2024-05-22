#include<bits/stdc++.h>
using namespace std;
#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n) for(int i=0;i<int(n);i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=int(n)-1;i>=0;i--)
#define rf1(i,n) for(int i = n;i>=1;i--)
#define saisir(v,x) int x; cin>>x; v.push_back(x);
#define le_debut int main
#define lol long long int
#define pb push_back
#define un first
#define deux second
#define oui cout<<"YES"<<endl
#define non cout<<"NO"<<endl
#define homme cout<<"Homme"<<endl
#define femme cout<<"Femme"<<endl
#define un_de_minus cout<<"-1"<<endl
#define duck cout<<0<<endl;
#define reponse cout<<ans<<endl
#define marche cout<<"working"<<endl
const int N = 1010;
const int M = 1e5+10;
int n,x;
int page[N],price[N];
int dp[N][M];
 
 
void allons_y(){
	cin>>n>>x;
	f(i,n) cin>>price[i];
	f(i,n) cin>>page[i];
 
	for(int i=1;i<=n;++i){
		for(int j=0;j<=x;++j){
 
			// dont include
			dp[i][j] = dp[i-1][j];
			// Include
			if(j >= price[i-1]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]] + page[i-1]);
			}
		}
	}
	
	cout<<dp[n][x]<<endl;
	
}
 
 
le_debut(){
	Sowrav_Nath
	int t;
	t = 1;
	//cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		allons_y();
	}
}