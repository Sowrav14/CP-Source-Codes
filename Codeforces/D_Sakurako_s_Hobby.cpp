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
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).


int v[N];
string s;
int vis[N], ans[N];
// int c;

void dfs(int i, int &c){
    vis[i] = 1;
    if(s[i-1] == '0') c++;
    int x = v[i];
    if(!vis[x]) dfs(x, c);
}

void dfs2(int i, int res){
    ans[i] = res;
    int x = v[i];
    if(ans[x] == -1) dfs2(x, res);
}


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        vis[i] = 0;
        ans[i] = -1;
    }
    s.clear();


    f1(i,n) cin >> v[i];
    cin >> s;
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            // cout << i << endl;
            int c = 0;
            dfs(i, c);
            ans[i] = c;
            // cout << i << " " << c << " " << ans[i] << endl;
            // ans[i] = dfs(i, 0);
        }
    }
    // dfs2(1, 0);
    for(int i=1;i<=n;i++){
        int res = ans[i];
        if(res != -1) dfs2(i, res);
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " \n"[i == n];
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