#include<bits/stdc++.h>
using namespace std;

#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i = n;i>=1;i--)
#define le_debut            signed main
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
const int N = 2*1e5+10;
const int M = 1e9+7;
const int inf = 1e12;
const double rinf = 1e-7;


// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}

vector<int>v;
vector<double>temp;

void check(double power){

    double l = 0, r = 0;
    while(r < v.size()){
        while(r < v.size() and (v[r] - v[l])/2.0 <= power){
            r++;
        }
        temp.pb(v[l] + (v[r-1]-v[l])/2.0);
        l = r;
    }
}

void allons_y(){

    double n; cin >> n;
    f(i,n){
        double x; cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());

    double p = inf;
    vector<double>ans;
    double l = 0, r = inf;

    while(r - l >= rinf){
        double m = (l + r) / 2;
        temp.clear();
        check(m);
        if(temp.size() <= 3){
            p = m;
            ans = temp;
            r = m;
        } else {
            l = m;
        }
    }

    cout << fixed << setprecision(6) << p << endl;
    if(ans.size() < 3){
        while(ans.size() != 3){
            ans.pb(ans.back());
        }
    }
    for(auto i : ans) cout << fixed << setprecision(6) << i << " "; cout << endl;

}


le_debut(){
    Sowrav_Nath
    int test = 1;
    // cin >> test;
    f1(tc,test){
        // cout << "Case " << tc << ": ";
        // memset(dp, 0, sizeof(dp));
        allons_y();
    }
}