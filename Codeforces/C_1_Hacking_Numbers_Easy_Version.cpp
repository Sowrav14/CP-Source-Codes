#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int x;
void solve(){

    int n; cin >> n;
    cout << "digit" << endl; cin >> x;
    cout << "digit" << endl; cin >> x;
    cout << "add " << -8 << endl; cin >> x;
    cout << "add " << -4 << endl; cin >> x;
    cout << "add " << -2 << endl; cin >> x;
    cout << "add " << -1 << endl; cin >> x;
    cout << "add " << n - 1 << endl; cin >> x;
    cout << "!" << endl; cin >> x;

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