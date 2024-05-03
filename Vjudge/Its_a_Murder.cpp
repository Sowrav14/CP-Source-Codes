#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int>bit;
int mx;

// updating a single value in bit
void update(int idx, int val){
    while(idx <= mx){
        bit[idx] += val;
        idx += (idx) & (-idx);  // lsb will be added.
    }
}

// return sum of (1 - idx)
int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);  // lsb will be substracted.
    }
    return ret;
}


void solve(){

    int n; cin >> n;
    vector<int>a(n);
    vector<int>temp;
    mx = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        temp.push_back(a[i]);  
    }

    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    sort(temp.begin(), temp.end());
    mx = temp.size();

    bit.clear();
    bit.resize(mx+10, 0);
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
        // cout << a[i] << " " << x << endl;
        ans += query(x-1);
        update(x, a[i]);
    }
    cout << ans << endl;

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