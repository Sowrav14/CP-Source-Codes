#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++) pq.push(v[i]);

    int ans = 0;
    for(int i=0;i<n;i++) ans += v[i];

    int preva = -1, prevb = -1;
    for(int i=0;i<k;i++){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        int z = (x + y + 1) / 2;
        if(preva == x and prevb == y){
            int rem = k - i;
            ans += rem * z;
            break;
        }
        preva = x, prevb = y;
        ans += z;
        pq.push(x);
        pq.push(y);
        pq.push(z);
    }
    cout << ans << endl;

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