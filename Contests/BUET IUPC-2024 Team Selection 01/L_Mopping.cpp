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
const int M = 1e9+7;

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

vector<string>v;
int n;
set<char>vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};
int dp[N][3];

int recur(int i, int x){
    // cout << i << " " << x << endl;
    if(x >= 3) return 1e15;
    if(i >= n) return 0;
    if(dp[i][x] != -1) return dp[i][x];

    string s = v[i];
    int sz = s.size();
    int ans = 1e15;
    int y = x;
    for(int j=0;j<min(sz, 3ll);j++){
        // if vowel x = 0;
        auto it = vowels.find(s[j]);
        if(it != vowels.end()){
            if(y < 3) y = 0;
        } else {
            y++;
        }
        // if consonent x++;
        // if x nge 3
        ans = min(ans, j + 1 + recur(i+1, y));
    }
    return dp[i][x] = ans;
}


void solve(){

    memset(dp, -1, sizeof(dp));
    cin >> n;
    f(i,n){
        string s; cin >> s;
        v.push_back(s);
    }

    int ans = recur(0, 0);
    if(ans > 1e12){
        cout << '*' << endl;
    } else{
        cout << ans << endl;
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