#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Macros...
#define int                 long long int
#define pii                 pair<int,int>
#define ordered_set         tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Sowrav_Nath         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i=n;i>=1;i--)
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

// Global Variables...
const int N = 2*1e5+10;
const int M = 998244353;

// Inline Function...
inline int bigmod(int x,int y, int mod);
inline int inverse_mod(int n,int mod)           {return bigmod(n,mod-2, mod);}
inline int ad(int x,int y, int mod)             {int ret=(x%mod+y%mod)%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}
inline int sub(int x,int y, int mod)            {int ret=((x%mod)-(y%mod)+mod)%mod;    if(ret<0)    {ret+=mod,ret=ret%mod;} return ret;}
inline int gun(int x,int y, int mod)            {int ret=((x%mod)*(y%mod))%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}
inline int bigmod(int x,int y, int mod)         {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%mod;}    y>>=1;x=(x*x)%mod;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)      {if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
inline int inverse(int a, int mod)              { int x, y; int g = egcd(a, mod, x, y); return (g != 1) ? -1 : (x % mod + mod) % mod; }


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).


/**
 * this problem is reduced to
 *  Sum( tuple t is good ) t = k length tuple {1, 2, ... n} -> {k elements}
 *  Sum( p^d for tuple t ) over all tuples
 *  Sum[ p^d * D] over all d from 1 to k
 *  d = distinct number in k length ordered tuple
 *  D = number of such tuples with fixed d
 *  p = probability for each round p = 1/m
 * 
 *  D can be calculated using dp.
 *  dp[i][j] = number of tuples of length i with j distinct numbers
 *  dp[i+1][j] +=  dp[i][j] * j  (choosing from existing distinct numbers)
 *  dp[i+1][j+1] += dp[i][j] * (n - j)  (choosing a new distinct number)
 */


void solve(){

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> dp(k+1, vector<int>(k+1,0));
  dp[0][0] = 1;
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      dp[i][j] = ad(dp[i][j], gun(dp[i-1][j], j, M), M);
      dp[i][j] = ad(dp[i][j], gun(dp[i-1][j-1], (n - j + 1), M), M);
    }
  }

  int ans = 0;
  m = inverse_mod(m, M);
  int p = 1;
  for(int i=1;i<=k;i++){
    p = gun(p, m, M);
    ans = ad(ans, gun(p, dp[k][i], M), M);
  }
  cout << ans << endl;

}


signed main(){
    Sowrav_Nath
    int test_cases = 1;
    // cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++){
        // cout << "Case " << i << ": ";
        // memset(dp,0,n*sizeof(int));
        solve();
    }
}