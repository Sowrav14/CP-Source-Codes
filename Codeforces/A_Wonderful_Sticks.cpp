#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;
    for(int i=0;i<n-1;i++){
        if(s[i] == '<') l++;
        else r++;
    }
    int x1 = l + 1;
    int x2 = n - r;
    if(x1 > x2) swap(x1, x2);
    int x = x1;
    if(s[0] == '>') x = x2;
    else x = x1;

    cout << x << " ";
    l = 0, r = 0;
    for(int i=0;i<n-1;i++){
        if(s[i] == '<'){
            l++;
            cout << x - l << " ";
        }
        else{
            r++;
            cout << x + r << " ";
        }
    }
    cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}