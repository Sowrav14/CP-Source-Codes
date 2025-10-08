#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


// time 1 : 53

void solve(){

    int n, m; cin >> n >> m;
    vector<vector<int>> v;
    vector<int> freq(m+1, 0);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        vector<int> a;
        for(int j=0;j<x;j++){
            int el; cin >> el;
            a.push_back(el);
            freq[el]++;
        }
        v.push_back(a);
    }
    for(int i=1;i<=m;i++){
        if(freq[i] == 0) return cout << "NO" << endl, void();
    }
    int men = 0;
    for(int i=0;i<n;i++){
        for(auto x : v[i]){
            if(freq[x] == 1) {
                men++;
                break;
            }
        }
    }
    if(n - men > 1) cout << "YES" << endl;
    else cout << "NO" << endl;

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