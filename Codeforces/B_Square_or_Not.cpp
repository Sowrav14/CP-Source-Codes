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


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    int col = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '0') break;
        col++;
    }
    if(col == n){
        if(col == 4 || col == 1){
            cout << "YES" << endl;
            return;
        } else{
            cout << "NO" << endl;
            return;
        }
    }
    if(col != n) col--;
    vector<vector<char>>v;
    for(int i=0;i<n;i+=col){
        vector<char>temp;
        for(int j=i;j<i+col;j++){
            temp.push_back(s[j]);
        }
        v.push_back(temp);
    }
    int row = v.size();
    if(row != col){
        cout << "NO" << endl;
        return;
    }
    // cout << row << " " << col << endl;
    // for(auto i : v){
    //     for(auto j : i){
    //         cout << j;
    //     } cout << endl;
    // }

    int flag = 1;
    for(int i=0;i<row;i++){
        if(v[i][0] == '0') flag = 0;
        if(v[i][col-1] == '0') flag = 0;
    }
    for(int i=0;i<col;i++){
        if(v[0][i] == '0') flag = 0;
        if(v[row-1][i] == '0') flag = 0;
    }

    for(int i=1;i<row-1;i++){
        for(int j=1;j<col-1;j++){
            if(v[i][j] == 1) flag = 0;
        }
    }

    flag ? oui : non;

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