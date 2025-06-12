#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    if(k < n/2) return cout << -1 << endl, void();
    string s, t; 
    for(int i=0;i<n;i++){
        if(i%2 == 0) {
            s += 'A';
            t += 'B';
        } else {
            s += 'C';
            t += 'C';
        }
    }

    for(int i=0;i<(k-n/2);i++){
        s[i*2] = 'B';
    }

    cout << s << endl;
    cout << t << endl;

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