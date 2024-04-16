#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M = 1e9+7;
// Inline Function
inline int bigmod(int x,int y);
inline int inverse_mod(int n,int M) 			{return bigmod(n,M-2);}
inline int ad(int x,int y)      				{int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     				{int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)		{if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
const int N = 1e5 + 10;
int bit[32];
int a[N];
int d[N];
// updating a single value in bit
void update(int idx, int val){
    while(idx <= 30){
        bit[idx] += val;
        idx += (idx) & (-idx);  // lsb will be added.
    }
}

// return sum of (1 - idx)
int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);  // lsb will be substracted.
    }
    return ret;
}

int sum(int a, int d, int n){
    int x = gun(2, a);
    int y = sub(n, 1);
    y = gun(y, d);
    int z = ad(x, y);
    z = gun(z, n);
    int p = inverse_mod(2, M);
    z = gun(z, p);
    return z;
}



void solve(){

    string s; cin >> s;
    int n; cin >> n;

    for(int i=0;i<s.size();i++){
        int cur = s[i] - 'a' + 1;
        int x = query(29) - query(cur);
        a[i] = x;
        update(cur, 1);
    }

    for(int i=0;i<s.size();i++){
        int cur = s[i] - 'a' + 1;
        int x = query(29) - query(cur);
        d[i] = x - a[i];
        update(cur, 1);
    }

    // for(int i=0;i<s.size();i++) cout << a[i] << " "; cout << endl;
    // for(int i=0;i<s.size();i++) cout << d[i] << " "; cout << endl;

    int ans = 0;
    for(int i=0;i<s.size();i++){
        int x = sum(a[i], d[i], n);
        ans = ad(ans, x);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}