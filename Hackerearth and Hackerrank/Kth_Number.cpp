/**
 * @file Kth_Number.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-10-10
 * @copyright Copyright (c) 2024
 * @tags:   Persistent segment tree kth number
 */
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
const int N = 1e5+10;
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

struct PST {
    #define lc t[cur].l
    #define rc t[cur].r

    // defining node for segment tree...
    struct node {
        int l = 0, r = 0, val = 0;
    } t[40 * N];

    int T = 0;
    int build(int b, int e) {
        int cur = ++T;
        if (b == e){
            return cur;
        }
        int mid = b + e >> 1;
        lc = build(b, mid);
        rc = build(mid + 1, e);
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }

    int p_update(int pre, int b, int e, int i, int v){
        int cur = ++T;
        t[cur] = t[pre];
        if (b == e){
            t[cur].val += v;
            return cur;
        }

        int mid = b + e >> 1;
        if (i <= mid){
            rc = t[pre].r;
            lc = p_update(t[pre].l, b, mid, i, v);
        } else {
            lc = t[pre].l;
            rc = p_update(t[pre].r, mid + 1, e, i, v);
        }
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }

    int query(int cur, int b, int e, int k){
        if (b == e){
            return b;
        }
        int cnt = t[lc].val;
        int mid = b + e >> 1;
        if (cnt >= k)
            return query(lc, b, mid, k);
        else
            return query(rc, mid + 1, e, k - cnt);
    }

} pst;

vector<int> a[N];
int v[N], root[N];

void solve(){

    int n,q; cin >> n >> q;
    int mx = 1;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        mx = max(x, mx);
        v[i] = x;
        a[x].push_back(i);
    }
    root[mx+1] = pst.build(1, n);
    for(int i = mx;i>0;i--){
        root[i] = root[i+1];
        for(auto j : a[i]){
            root[i] = pst.p_update(root[i], 1, n, j, 1);
        }
    }
    // cout << root[6] << endl;
    // cout << pst.t[root[6]].val << endl;

    while(q--){
        int id, k; cin >> id >> k;
        int x = pst.query(root[id], 1, n, k);
        cout << v[x] << endl;
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