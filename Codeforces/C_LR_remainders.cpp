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
const int N = 2*1e5+10;
int M;
const int inf = 1e12;



// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}


int a[N];
int tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = (a[l]%M);
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = gun(tree[2*node], tree[2*node + 1]);

}



int query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return 1;
    }
    if(i<=l and j>=r){
        return (tree[node]%M);
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right = query(2*node+1, mid+1, r, i, j);
    return gun(left, right);
}





void allons_y(){

    int n,m; cin >> n >> m;
    M = m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    string s; cin >> s;
    int l = 0, r = n-1;
    for(int i=0;i<n;i++){
        cout << query(1, 1, n, l+1, r+1) << " ";
        if(s[i] == 'L'){
            l++;
        } else{
            r--;
        }
    } cout << endl;

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