#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    // cout << n << " " << k << endl;
    bool f = 0;
    int i = 0, j = n - 1;
    while(k--){
        if(f) j--;
        else i++;
        f = 1 - f;
    }
    // cout << i << " " << j << " " << f << endl;

    if(f) {
        for(int x=j;x>=i;x--){
            cout << v[x] << " ";
        }
    } else {
        for(int x=i;x<=j;x++){
            cout << v[x] << " ";
        }
    }
    cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}