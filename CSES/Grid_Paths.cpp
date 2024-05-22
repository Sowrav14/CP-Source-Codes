/*
																																																				*
	░██████╗░█████╗░░██╗░░░░░░░██╗██████╗░░█████╗░██╗░░░██╗░░░░░░███╗░░██╗░█████╗░████████╗██╗░░██╗		
	██╔════╝██╔══██╗░██║░░██╗░░██║██╔══██╗██╔══██╗██║░░░██║░░░░░░████╗░██║██╔══██╗╚══██╔══╝██║░░██║		
	╚█████╗░██║░░██║░╚██╗████╗██╔╝██████╔╝███████║╚██╗░██╔╝█████╗██╔██╗██║███████║░░░██║░░░███████║		
	░╚═══██╗██║░░██║░░████╔═████║░██╔══██╗██╔══██║░╚████╔╝░╚════╝██║╚████║██╔══██║░░░██║░░░██╔══██║		
	██████╔╝╚█████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░██║░░╚██╔╝░░░░░░░░██║░╚███║██║░░██║░░░██║░░░██║░░██║		
	╚═════╝░░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░░░░░░╚═╝░░╚══╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝		
 		            . None can deserve anyting but can achieve everyting . 							
 																										
*/
 
#include<bits/stdc++.h>
using namespace std;
#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dites_moi_lheure cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define f(i,n) for(int i=0;i<int(n);i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=int(n)-1;i>=0;i--)
#define rf1(i,n) for(int i = n;i>=1;i--)
#define saisir(v,x) int x; cin>>x; v.push_back(x);
#define le_debut int main
#define lol long long int
#define endl '\n'
#define pb push_back
#define un first
#define deux second
#define oui cout<<"YES"<<endl
#define non cout<<"NO"<<endl
#define un_de_minus cout<<"-1"<<endl
#define duck cout<<0<<endl;
#define reponse cout<<ans<<endl
#define ici cout<<"I am here"<<endl
const int N = 1000+10;
const int M = 1e9+7;
int n;
string grid[N];
int dp[N][N];
 
int going(int i,int j){
 
	if(i==n || j==n) return 0;
	if(grid[i][j] == '*') return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(i==n-1 && j==n-1) return 1;
 
	int ret = 0;
 
	ret += going(i+1,j);
	ret += going(i,j+1);
	ret %= M;
 
	return dp[i][j] = ret;
}
 
 
 
void allons_y(){
	cin >> n;
	f(i,n){
		cin >> grid[i];
	}
 
	cout << going(0,0) << endl;
	
}
 
 
le_debut(){
	Sowrav_Nath
	//memset(vis,false,sizeof(vis));
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		allons_y();
	}
}