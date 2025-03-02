#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int freq[N];

void solve(){

    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++) freq[i] = 0;
    set<int>s;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        s.insert(x);
        freq[x]++;
    }

    int wow = 0;
    for(auto i : s){
        int x = i;
        int y = k - i;
        wow += min(freq[x], freq[y]);
        // cout << x << " " << y << " " << freq[x] << " " << freq[y] << endl;
    }

    cout << wow/2 << endl;
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