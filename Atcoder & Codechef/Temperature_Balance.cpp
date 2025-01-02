#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>pos, neg;
    int sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x > 0) pos.push_back(x);
        if(x < 0) neg.push_back(x);
        sum += x;
        ans += abs(sum);
    }
    cout << ans <<endl;

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