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
const int N = 1000+10;
const int M = 1e9+7;

// Inline Function...
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).


int d[N][N];
queue<pii> q;
pii A;
int n,m;

void multiSourceBfs(){
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        // cout << cur.first << " " << cur.second << " " << d[cur.first][cur.second] << endl;

        if(cur.second+1 <= m){
            if(d[cur.first][cur.second] + 1 < d[cur.first][cur.second+1]){
                d[cur.first][cur.second+1] = d[cur.first][cur.second] + 1;
                q.push({cur.first, cur.second+1});
            }
        }
        if(cur.second-1 >= 1){
            if(d[cur.first][cur.second] + 1 < d[cur.first][cur.second-1]){
                d[cur.first][cur.second-1] = d[cur.first][cur.second] + 1;
                q.push({cur.first, cur.second-1});
            }
        }
        if(cur.first-1 >= 1){
            if(d[cur.first][cur.second] + 1 < d[cur.first-1][cur.second]){
                d[cur.first-1][cur.second] = d[cur.first][cur.second] + 1;
                q.push({cur.first-1, cur.second});
            }
        }
        if(cur.first+1 >= 1){
            if(d[cur.first][cur.second] + 1 < d[cur.first+1][cur.second]){
                d[cur.first+1][cur.second] = d[cur.first][cur.second] + 1;
                q.push({cur.first+1, cur.second});
            }
        }
    }
}

pii g[1001][1001];
pii ans = {-1, -1};
void singleSourceBfs(){
    queue<pii> qu;
    qu.push(A);
    d[A.first][A.second] = 0;

    while(!qu.empty()){
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        if(x == 1 or x == n or y == 1 or y == m){
            ans = {x, y};
        }

        if(x+1 <= n){
            if(d[x][y] + 1 < d[x+1][y]){
                d[x+1][y] = d[x][y] + 1;
                g[x+1][y] = {x, y};
                qu.push({x+1, y});
            }
        }
        if(x-1 >= 1){
            if(d[x][y] + 1 < d[x-1][y]){
                d[x-1][y] = d[x][y] + 1;
                g[x-1][y] = {x, y};
                qu.push({x-1, y});
            }
        }
        if(y+1 <= m){
            if(d[x][y] + 1 < d[x][y+1]){
                d[x][y+1] = d[x][y] + 1;
                g[x][y+1] = {x, y};
                qu.push({x, y+1});
            }
        }
        if(y-1 >= 1){
            if(d[x][y] + 1 < d[x][y-1]){
                d[x][y-1] = d[x][y] + 1;
                g[x][y-1] = {x, y};
                qu.push({x, y-1});
            }
        }
    }
}

void solve(){

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch; cin >> ch;
            if(ch == '#') d[i][j] = 0;
            if(ch == 'M'){
                d[i][j] = 0;
                q.push({i, j});        // sources for bfs run...
            }
            if(ch == 'A'){
                d[i][j] = M;
                A = {i, j};                 // starting point...
            }
            if(ch == '.') d[i][j] = M;
        }
    }

    multiSourceBfs();
    singleSourceBfs();

    if(ans.first == -1){
        cout << "NO" << endl;
        return;
    }
    string res = "";
    pii c = ans;
    while(1){
        if(c == A) break;
        pii par = g[c.first][c.second];
        if(par.first + 1 == c.first) res += 'D';
        if(par.first - 1 == c.first) res += 'U';
        if(par.second + 1 == c.second) res += 'R';
        if(par.second - 1 == c.second) res += 'L';
        c = par;
    }

    reverse(res.begin(), res.end());
    cout << "YES" << endl;
    cout << res.size() << endl;
    cout << res << endl;

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