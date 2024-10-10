#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n,k; cin >> n >> k;
    priority_queue <int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(q.size() > 2){
        int x = q.top(); q.pop();
        q.pop();
        ans += (x * 2);
        q.push(x);
    }
    ans += q.top();
    cout << (ans <= k ? "YES" : "NO") << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}