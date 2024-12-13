#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int ppx(vector<int>& arr) {
    int n = arr.size();
    vector<int> bit_counts(32, 0);
    for (int num : arr) {
        for (int i = 0; i < 32; ++i) {
            if (num & (1 << i)) {
                bit_counts[i]++;
            }
        }
    }
    long long prd = 1;
    int flag = 0;
    for (int count : bit_counts) {
        if (count % 2 == 1) {
            prd = (prd * 2);
            if(prd > inf) flag = 1;
        }
    }
    return flag == 1 ? 0 : prd;
}

void solve(){

    int n; cin >> n;
    int l, r; cin >> l >> r;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int pro = ppx(v);

    cout << pro << endl;

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