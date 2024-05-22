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
#define marche cout<<"working"<<endl
const int N = 1e6+10;
const int M = 1e9+7;
int n;
lol dp[N];
 
 
lol combinator(int i){
	if(i == 0) return 1;
	if(dp[i] != -1) return dp[i];
 
	lol ans = 0;
	for(int j=1;j<=6;j++){
		if(i-j >= 0){
			ans = (ans + combinator(i-j))%M;
		}
	}
	return dp[i] = ans;
}
 
 
void allons_y(){
 
	cin >> n;
	cout<< combinator(n) <<endl;
}
 
 
le_debut(){
	Sowrav_Nath
	//memset(prime,true,sizeof(prime));
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		allons_y();
	}
}