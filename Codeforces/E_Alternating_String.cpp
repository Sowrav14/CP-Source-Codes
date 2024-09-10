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
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).
int ef[30];
int of[30];

int efn[30];
int ofn[30];

int check(int x, int flag){
    int emx = 0;
    int omx = 0;
    for(int i=1;i<=26;i++){

        int re = ef[i] - efn[i];
        int ro = of[i] - ofn[i];

        int te = efn[i] + ro;
        int to = ofn[i] + re;

        if(i == x){
            if(flag){
                to--;
            } else{
                te--;
            }
        }

        emx = max(emx, te);
        omx = max(omx, to);
        
    }

    int tot = emx + omx;
    return tot;
}


void solve(){

    int n; cin >> n;

    f(i,28) {
        of[i] = 0;
        ef[i] = 0;
        ofn[i] = 0;
        efn[i] = 0;
    }

    string s; cin >> s;
    f(i,n){
        if(i%2){
            of[s[i] - 'a' + 1]++;
        } else{
            ef[s[i] - 'a' + 1]++;
        }
    }

    if(n%2 == 0){
        cout << n - check(0, 0) << endl;
        return;
    }
    
    int ans = n;
    for(int i=0;i<n;i++){
        int c = s[i] - 'a' + 1;
        if(i%2){
            ofn[c]++;
            int x = check(c, 1);
            ans = min(ans, n - x);
        } else{
            efn[c]++;
            int x = check(c, 0);
            ans = min(ans, n - x);
        }
    }
    cout << ans << endl;

}


signed main(){
    Sowrav_Nath
    int test_cases = 1;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++){
        // cout << "Case " << i << ": ";
        // memset(dp,0,n*sizeof(int));
        solve();
    }
}