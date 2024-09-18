/**
 * @file Distributing_Apples.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-09-16
 * @copyright Copyright (c) 2024
 * @problem: CSES Distributing Apples
 * @solution: https://www.geeksforgeeks.org/number-of-integral-solutions-of-the-equation-x1-x2-xn-k/#:~:text=Number%20of%20non%2Dnegative%20integral%20solutions%20of%20equation%20x1%20%2B%20x2%20%2B%20%E2%80%A6%E2%80%A6%20%2B%20xn%20%3D%20k%20is%20given%20by%20(n%2Bk%2D1)!%20/%20(n%2D1)!*k!.%C2%A0%0ANumber%20of%20positive%20integral%20solutions%20of%20equation%20x1%20%2B%20x2%20%2B%20%E2%80%A6..%20%2B%20xn%20%3D%20k%20is%20given%20by%20(k%2D1)!%20/%20(n%2D1)!%20*%20(k%2Dn)!.%C2%A0
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
const int N = 2*1e6+10;
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


int f[N],invf[N];

// Big Mod
int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}



// Calculating factorials and inverse factorial
void fact_invfact(){
    f[0] = 1;
    for(int i=1;i<N;i++){
        f[i] = (1ll * f[i-1]%M * i%M) % M;
    }

    // calculate fact inverse
    invf[N-1] = A_pow_B(f[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        invf[i] = (1ll * invf[i+1]%M * (i+1)%M) % M;
    }
}


// Calculating nCr
int nCr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M * invf[r]%M) % M ; 
}


// Calculating nPr
int nPr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M) % M;
}


void solve(){

    int n, k; cin >> n >> k;
    int ans = f[n+k-1];
    ans = gun(ans, invf[n-1], M);
    ans = gun(ans, invf[k], M);
    cout << ans << endl;

}


signed main(){
    Sowrav_Nath
    fact_invfact();
    int test_cases = 1;
    // cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++){
        // cout << "Case " << i << ": ";
        // memset(dp,0,n*sizeof(int));
        solve();
    }
}