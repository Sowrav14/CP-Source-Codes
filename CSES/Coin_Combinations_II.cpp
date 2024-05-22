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
const int N = 2*1e5+10;
const int M = 1e9+7;
int n,x;
int coins[105];
 
 
/*
	number of ways to make a subset sum
	similar problem in how many way a amount can be made
	by coins;
*/
 
 
/*lol coindp(int i,int sum){
	if(sum == 0) return 1;
	if(i < 0) return 0;
	if(dp[i][sum] != -1) return dp[i][sum];
	lol ans = 0;
	for(int coin=0;coin<=sum;coin+=coins[i]){
			ans += coindp(i-1,sum - coin);
			ans %= M;
	}
	return dp[i][sum] = ans;
}*/
 
 
void allons_y(){
 
	cin >> n >> x;
	f(i,n) cin >> coins[i];
	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			dp[i][j] = dp[i-1][j];
			int left = j-coins[i-1];
			if(left >= 0){
				dp[i][j] += dp[i][left];
				dp[i][j] %= M;
			}
		}
	}
 
	cout << dp[n][x] << endl;
}
 
 
le_debut(){
	Sowrav_Nath
	//memset(prime,true,sizeof(prime));
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		// memset(dp,0,sizeof(dp));
		allons_y();
	}
}