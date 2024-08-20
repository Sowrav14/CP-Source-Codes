#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Macros...
#define int                 long long int
#define ordered_set         tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Sowrav_Nath         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i=n;i>=1;i--)
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

// Global Variables...
const int N = 2*1e5+10;
const int M = 1e9+7;
const int inf = 1e15;

// Inline Function...
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).



void solve(){

    map<string, int > color;
    color["BG"] = 1;
    color["BR"] = 2;
    color["BY"] = 3;
    color["GR"] = 4;
    color["GY"] = 5;
    color["RY"] = 6;

    int n,q; cin >> n >> q;
    vector<string>a(n+1); f1(i,n) cin >> a[i];
    
    vector<vector<int>>left(n+1, vector<int>(7, inf)), right(n+1, vector<int>(7, inf));
    vector<int>v(7, inf);
    f1(i,n){
        v[color[a[i]]] = i;
        left[i] = v;
    }
    v.resize(7, inf);
    rf1(i,n){
        v[color[a[i]]] = i;
        right[i] = v;
    }

    while(q--){
        int x,y; cin >> x >> y;
        int ans = inf;
        f1(i,6){
            if(color[a[x]] + i != 7 and color[a[y]] + i != 7){
                ans = min(ans, abs(x - left[x][i]) + abs(y - left[x][i]));
                ans = min(ans, abs(x - right[x][i]) + abs(y - right[x][i]));
            }
        }
        if(2 * ans > inf) cout << -1 << endl;
        else cout << ans << endl;
    }

}


signed main(){
    Sowrav_Nath
    int test_cases = 1;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++){
        // cout << "Case " << i << ": ";
        // memset(dp,0,n*sizeof(int));
        solve();
    }
}