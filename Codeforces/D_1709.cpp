#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int swap_count = 0;
    vector<pair<int,int>> ans;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swap_count++;
                ans.push_back({1, j});
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                swap_count++;
                ans.push_back({2, j});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
            ans.push_back({3, i});
            swap_count++;
        }
    }
    cout << swap_count << '\n';
    for(auto i : ans){
        cout << i.first << " " << i.second + 1 << endl;
    }

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