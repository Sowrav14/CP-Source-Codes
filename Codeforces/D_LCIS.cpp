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
const int N = 500+10;
const int M = 1e9+7;


// Inline Function
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}


void allons_y(){

    int n; cin >> n;
    vector<int>a(n+10);
    f1(i,n){
        cin >> a[i];
    }
    int m; cin >> m;
    vector<int>b(m+10);
    f1(j,m){
        cin >> b[j];
    }

    vector<int>dp(m+10);
    vector<int>p(m+10);

    f1(i,n){
        int prev = 0;
        f1(j,m){
            if(a[i] == b[j]){
                dp[j] = dp[prev] + 1;
                p[j] = prev;
            } else if(a[i] > b[j] and dp[j] > dp[prev]){
                prev = j;
            }
        }
    }
    int ans = dp[0], pos = 0;
    f1(i,m){
        if(dp[i] > ans){
            ans = dp[i];
            pos = i;
        }
    }
    vector<int>res;
    cout << ans << endl;
    while(ans--){
        res.pb(b[pos]);
        pos = p[pos];
    }
    reverse(res.begin(), res.end());
    for(auto i : res) cout << i << " "; cout << endl;

}


le_debut(){
    Sowrav_Nath
    int test = 1;
    // cin >> test;
    f1(tc,test){
        // cout << "Case " << tc << ": ";
        // memset(dp,0,sizeof(dp));
        allons_y();
    }
}