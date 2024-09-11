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
const int M = 1e9+7;

// Inline Function...
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M)             {return bigmod(n,M-2);}
inline int ad(int x,int y)                      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)                     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)                     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)                  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)      {if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
inline int inverse(int a, int m)                { int x, y; int g = egcd(a, m, x, y); return (g != 1) ? -1 : (x % m + m) % m; }


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).

map<int, int> mp;
int phi(int n) {
    if (mp.count(n)) return mp[n];
    int ans = n, m = n;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            while (m % i == 0) m /= i;
            ans = ans / i * (i - 1);
        }
    }
    if (m > 1) ans = ans / m * (m - 1);
    return mp[n] = ans;
}

int MOD(int x, int m) {
    if (x < m) return x;
    return x % m + m;
}
int power(int n, int k, int mod) {
    int ans = MOD(1, mod);
    while (k) {
        if (k & 1) ans = MOD(ans * n, mod);
        n = MOD(n * n, mod);
        k >>= 1;
    }
    return ans;
}

int a[N];


// cumulative power [l,r] = a[l] * cumulative power [l+1, r];
// a^b^c mod m = a^(b^c mod phi(m)) mod m
// cumPow(l, r) = a[l] ^ (cumPow(l+1, r)) mod m

int cumPow(int l, int r, int m) {
  if (l == r) return MOD(a[l], m);
  if (m == 1) return 1;
  return power(a[l], cumPow(l + 1, r, phi(m)), m);
}


void solve(){

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        cout << cumPow(l, r, m) % m << endl;
    }

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