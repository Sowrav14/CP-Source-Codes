#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Macros...
#define int                 long long int
#define pii                 pair<int,int>
#define ordered_set         tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
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

multiset<pair<int,int>>a,b;
int l = 0, r = 0;
vector<int>v;
void add(int i){
    auto ait = a.end(); ait--;
    if(v[i] < ait->first){
        a.insert({v[i], i});
        l += v[i];
    } else{
        b.insert({v[i], i});
        r += v[i];
    }
    int x = a.size();
    int y = b.size();
    if(x - y > 1) {
        auto it = a.end(); it--;
        a.erase(it); l -= it->first;
        b.insert(*it); r += it->first;
    } else if(y > x){
        auto it = b.begin();
        b.erase(it); r -= it->first;
        a.insert(*it); l += it->first;
    }
}

void remove(int i){
    if(a.find({v[i], i}) != a.end()){
        a.erase(a.find({v[i], i}));
        l -= v[i];
    }
    if(b.find({v[i], i}) != b.end()){
        b.erase(b.find({v[i], i}));
        r -= v[i];
    }
    int x = a.size();
    int y = b.size();
    if(x - y > 1) {
        auto it = a.end(); it--;
        a.erase(it); l -= it->first;
        b.insert(*it); r += it->first;
    } else if(y > x){
        auto it = b.begin();
        b.erase(it); r -= it->first;
        a.insert(*it); l += it->first;
    }
}


void solve(){

    int n,k; cin >> n >> k;
    v.resize(n); f(i,n) cin >> v[i];
    for(int i=0;i<k;i++){
        if(a.size() == 0){
            a.insert({v[i], i});
            l += v[i];
            continue;
        }
        add(i);
    }
    int m = (--a.end())->first, x = a.size(), y = b.size();
    cout << (m*x - l) + (r - m*y) << " ";

    for(int i=k;i<n;i++){
        add(i);
        remove(i-k);
        m = (--a.end())->first, x = a.size(), y = b.size();
        cout << (m*x - l) + (r - m*y) << " ";
}
    cout << endl;

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