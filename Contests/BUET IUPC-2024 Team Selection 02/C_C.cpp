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
const int N = 1e6+10;
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


int f[N],invf[N];


// Big Mod
int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}



// Calculating factorials and inverse factorial
void fact_invfact(){
    f[0] = 1;
    for(int i=1;i<N;i++){
        f[i] = (1ll * f[i-1]%M * i%M) % M;
    }

    // calculate fact inverse
    invf[N-1] = A_pow_B(f[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        invf[i] = (1ll * invf[i+1]%M * (i+1)%M) % M;
    }
}


// Calculating nCr
int nCr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M * invf[r]%M) % M ; 
}


// Calculating nPr
int nPr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M) % M;
}


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).
int n, k;
int freq[11];
map<pair<int,pair<int,int>>, int>dp;

int recur(int i, int take, int sum){
    if(sum > k) return 0;
    if(i >= 11){
        if(take%2 and sum == k) return 1;
        return 0;
    }
    pair<int, pair<int, int>> d = {i, {take, sum}};
    if(dp[d]) return dp[d];

    int ans = 0;
    for(int cnt=0;cnt<=freq[i];cnt++){
        ans = ad(ans, gun(nCr(freq[i], cnt), recur(i+1, take+cnt, sum+cnt*i), M), M);
    }
    return dp[d] = ans;
}


void solve(){

    fact_invfact();
    cin >> n >> k;
    f(i,n){
        int x; cin >> x;
        freq[x]++;
    }

    cout << recur(1, 0, 0) << endl;



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