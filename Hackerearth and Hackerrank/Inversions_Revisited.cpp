#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int mx;
vector<int>bit;


void update(int idx, int val){
    while(idx <= mx){
        bit[idx] += val;
        idx += (idx) & (-idx);
    }
}

int getsum(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx) & (-idx);
    }
    return sum;
}


void solve(){

    int n; cin >> n;
    vector<int>a(n+1), b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        mx = max(mx, b[i]);
    }

    bit.resize(mx+10, 0);
    
    int inv = 0;
    for(int i=n;i>=1;i--){
        inv += getsum(a[i]-1);
        update(b[i], 1);
    }
    cout << inv << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}