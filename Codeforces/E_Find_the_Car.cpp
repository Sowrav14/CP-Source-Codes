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
const int M = 1e9+7;
const int inf = 1e12;


// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}



void allons_y(){

    int n,k,q; cin >> n >> k >> q;
    vector<int>p(k+1, 0), t(k+1, 0);
    f1(i,k) cin >> p[i];
    f1(i,k) cin >> t[i];

    vector<int> a;
    vector<pair<int,int>> b;
    int prev = 0;
    int pt = 0;
    f1(i,k){
        int cur = p[i];
        int ct = t[i];
        int dis = cur - prev;
        int time = ct - pt;
    
        a.pb(prev);
        b.pb({dis, time});

        prev = cur;
        pt = ct;
    }

    // f(i, a.size()){
    //     cout << a[i] << " " << b[i] << endl;
    // }

    while(q--){
        int d; cin >> d;
        int it = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
        // cout << p[it] << " " << t[it] << " " << a[it] << " " << b[it] << endl;
        int ini = t[it];
        int dis = d - p[it];
        // cout << it << " " << ini << " " << dis << " " << b[it] <<  endl;
        int extra = (dis * b[it].second / (b[it].first));
        cout << ini + extra << " ";
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