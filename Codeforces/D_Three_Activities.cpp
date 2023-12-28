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


// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}

pair<int,int> temp[3][3];


int recur(int i, int j, int k){
    int ans = 0;
    set<int>t;
    ans += temp[0][i].first;
    t.insert(temp[0][i].second);
    ans += temp[1][j].first;
    t.insert(temp[1][j].second);
    ans += temp[2][k].first;
    t.insert(temp[2][k].second);

    return t.size() == 3 ? ans : 0;
}

void allons_y(){

    int n; cin >> n;
    vector<pair<int,int>>a,b, c;
    f1(i,n){
        int x; cin >> x;
        a.pb({x, i});
    }
    f1(i,n){
        int x; cin >> x;
        b.pb({x, i});
    }
    f1(i,n){
        int x; cin >> x;
        c.pb({x, i});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    for(int i=0;i<3;i++){
        temp[0][i] = a[i];
        temp[1][i] = b[i];
        temp[2][i] = c[i];
    }

    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ans = max(ans, recur(i, j, k));
            }
        }
    }
    cout << ans << endl;
    

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