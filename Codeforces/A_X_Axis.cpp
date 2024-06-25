#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    vector<int>a(3); cin >> a[0] >> a[1] >> a[2]; sort(a.begin(), a.end());
    cout << abs(a[1] - a[0]) + abs(a[2] - a[1]) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}