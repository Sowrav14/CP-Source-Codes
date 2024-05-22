#include<bits/stdc++.h>
using namespace std;
 
#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i = n;i>=1;i--)
#define le_debut            signed main
#define int                 long long int
#define endl                '\n'
#define pb                  push_back
#define oui                 cout << "YES" << endl
#define non                 cout << "NO" << endl
#define homme               cout << "Bob" << endl
#define femme               cout << "Alice" << endl
#define un_de_minus         cout << "-1" << endl
#define duck                cout << 0 << endl;
#define reponse             cout << ans << endl
#define ici                 cout << "Je suis ici" << endl
const int N = 2*1e6+10;
const int M = 1e9+7;
const int inf = 1e12;
 
 
// Inline Function
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
int dp[N];
 
vector<int> getdigits(int num){
    vector<int>a;
    while(num){
        a.pb(num % 10);
        num /= 10;
    }
    return a;
}
 
int recur(int n){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = inf;
    vector<int> digits = getdigits(n);
    for(auto i : digits){
        if(n-i >= 0 and i != 0) ans = min(ans, 1+recur(n-i));
    }
    return dp[n] = ans;
}
 
 
void allons_y(){
 
    int n; cin >> n;
    cout << recur(n) << endl;
 
}
 
 
le_debut(){
    Sowrav_Nath
    int test = 1;
    // cin >> test;
    f1(tc,test){
        // cout << "Case " << tc << ": ";
        memset(dp, -1, sizeof(dp));
        allons_y();
    }
}