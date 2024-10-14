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

// Structuring Segment Tree...
struct SegmentTree {
  	#define lc (n << 1)
	#define rc ((n << 1) | 1)
	int tree[4 * N], lazy1[4 * N], lazy2[4 * N], a[N];
	SegmentTree() {
		memset(tree, 0, sizeof tree);
		memset(lazy1, 0, sizeof lazy1);
		memset(lazy2, 0, sizeof lazy2);
	}
    inline int getsum(int n){
        int x = n * (n + 1) / 2;
        return x;
    }
	// push the lazy value toward leafs...
	inline void push(int n, int b, int e) {
		if (lazy2[n] == 0) return;
        // check here how to update lazy...
		tree[n] += lazy1[n] * (e - b + 1) + lazy2[n] * getsum(e - b + 1);
		int m = (b + e) / 2;
		if (b != e) {
    		lazy1[lc] += lazy1[n];
			lazy2[lc] += lazy2[n];
			lazy1[rc] += lazy1[n] + (m - b + 1) * lazy2[n]; 
    		lazy2[rc] += lazy2[n];
		}
		lazy1[n] = lazy2[n] = 0;
	}
	// combine two node of segment tree... how??
	inline int combine(int a, int b) {
		return a + b;
	}
	inline void pull(int n) {
		tree[n] = tree[lc] + tree[rc];
	}
	// building the segment tree...
	void build(int n, int b, int e) {
		lazy1[n] = lazy2[n] = 0;
		if (b == e) {
    		tree[n] = a[b];
    		return;
		}
		int mid = (b + e) >> 1;
		build(lc, b, mid);
		build(rc, mid + 1, e);
		pull(n);
	}
	// Updating range...
	void update(int n, int b, int e, int i, int j) {
		push(n, b, e);
		if (j < b || e < i) return;
		if (i <= b && e <= j) {
    		lazy1[n] += (b - i);
			lazy2[n] += 1;
    		push(n, b, e);
    		return;
    	}
		int mid = (b + e) >> 1;
		update(lc, b, mid, i, j);
		update(rc, mid + 1, e, i, j);
		pull(n);
	}
	// range query...
	int query(int n, int b, int e, int i, int j) {
		push(n, b, e);
		if (i > e || b > j) return 0;	// what??
		if (i <= b && e <= j) return tree[n];
		int mid = (b + e) >> 1;
		return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
	}
};



void solve(){

    int n,q; cin >> n >> q;
    SegmentTree st;
    f1(i,n){
        cin >> st.a[i];
    }

    st.build(1, 1, n);

    while(q--){
		int t, a, b; cin >> t >> a >> b;
		if(t == 1){
			st.update(1, 1, n, a, b);
		} else {
			cout << st.query(1, 1, n, a, b) << endl;
		}
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