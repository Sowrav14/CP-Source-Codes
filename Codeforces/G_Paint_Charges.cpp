#include<bits/stdc++.h>
using namespace std;

#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i = n;i>=1;i--)
#define le_debut            signed main
#define int                 long long int
#define pii                 pair<int,int>
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
const int N = 104;
const int M = 1e9+7;
const int inf = 1e5;


// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}

int n;
int a[N];
int tree[4*N];
int st[4*N];
int prop[4*N];
int tot;

void build(int node, int l, int r){
    prop[node] = 1;
    if(l == r){
        tree[node] = st[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    st[node] = tree[node] = tree[2*node] + tree[2*node+1];
}


void rangeupdate(int node, int l, int r, int i, int j, int val){
    if(i>r or j<l) return;
    if(i<=l and j>=r){
	    prop[node] = val;
        tree[node] = (prop[node] ? st[node] : 0);
        return;
    }


    int mid = (l + r) / 2;
    rangeupdate(2*node, l, mid, i, j, val);
    rangeupdate(2*node+1, mid+1, r, i, j, val);
    // tree[node] = tree[2*node] * prop[2*node] + tree[2*node+1] * prop[2*node+1];
    // tree[node] = (prop[2*node] ? st[2*node] : tree[2*node]) + (prop[2*node+1] ? st[2*node+1] : tree[2*node+1]);
    tree[node] = prop[node] ? tree[2*node] + tree[2*node+1] : 0;
}


int query(int node, int l, int r, int i, int j, int val=1){
    if(i>r or j<l){
        return 0;
    }
    if(i<=l and j>=r){
        return tree[node] * (val & prop[node]);
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j, val & prop[node]);
    int right = query(2*node+1, mid+1, r, i, j, val & prop[node]);
    return left + right;
}



int recur(int i, int sum){
    if(i > n) {
        if(sum == tot) return 0;
        else return inf;
    }
    int ans = inf;
    // going left....
    int l = max(1ll, i-a[i]+1), r = i;
    int x = query(1, 1, n, l, r);
    rangeupdate(1, 1, n, l, r, 0);
    ans = min(ans, 1 + recur(i+1, sum + x));
    rangeupdate(1, 1, n, l, r, 1);

    // going right.
    l = i, r = min(i+a[i]-1, n);
    x = query(1, 1, n, l, r);
    rangeupdate(1, 1, n, l, r, 0);
    ans = min(ans, 1 + recur(i+1, sum + x));
    rangeupdate(1, 1, n, l, r, 1);

    // going nowhere...
    ans = min(ans, recur(i+1, sum));

    return ans;
}




void allons_y(){

    cin >> n;
    tot = 0;
    f1(i,n){
        cin >> a[i];
        tot += a[i];
    }
    build(1, 1, n);
    
    cout << recur(1, 0) << endl;
    // cout << query(1, 1, n, 1, n) << endl;
    // rangeupdate(1, 1, n, 1, 2, 0);
    // for(int i=1;i<4*n;i++) cout << tree[i] << " "; cout << endl;
    // cout << query(1, 1, n, 1, n) << endl;
    // rangeupdate(1, 1, n, 1, 4, 0);
    // for(int i=1;i<4*n;i++) cout << tree[i] << " "; cout << endl;
    // cout << query(1, 1, n, 1, n) << endl;
    // rangeupdate(1, 1, n, 1, 2, 1);
    // cout << query(1, 1, n, 1, 8) << endl;
    // rangeupdate(1, 1, n, 1, 4, 1);
    // cout << query(1, 1, n, 1, 8) << endl;
    

}


le_debut(){
    Sowrav_Nath
    int test = 1;
    cin >> test;
    f1(tc,test){
        // cout << "Case " << tc << ": ";
        // memset(dp, 0, sizeof(dp));
        allons_y();
    }
}