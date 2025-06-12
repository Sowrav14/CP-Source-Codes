#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    int zero = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] == 0) zero++;
    }

    if(zero == 0){
        cout << "YES" << endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(a[i] == 0 and a[i-1] == 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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