#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    vector<int> v(5);
    for(int i=0;i<5;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=0;i<5;i++){
        sum += v[i];
    }
    int ans = 0;
    for(int i=0;i<5;i++){
        if(sum >= 35) break;
        sum -= v[i];
        sum += 10;
        ans++;
    }
    cout << ans*100 << endl;

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