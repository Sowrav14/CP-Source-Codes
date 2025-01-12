#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, q;
int a[N];
int pref[N];
map<int,int>oc;
vector<pair<int,int>>queries[N];
int ans[N];

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 10) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] ^= val;
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int xr = 0;
        while(idx > 0){
            xr ^= bit[idx];
            idx -= (idx) & (-idx);
        }
        return xr;
    }
    // update the value at [l...r] by val.
    void update(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
    // sum form [l...r]
    int query(int l, int r){
        return query(r) ^ query(l-1);
    }
};

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i-1] ^ a[i];
    }
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        queries[l].push_back({r, i});
    }
    BIT bit(n);
    for(int i=n;i>=1;i--){
        if(oc.count(a[i]) != 0){
            bit.update(oc[a[i]], a[i]);
        }
        oc[a[i]] = i;
        bit.update(i, a[i]);
        for(auto qu : queries[i]){
            int l = i, r = qu.first;
            int id = qu.second;
            ans[id] = bit.query(l, r) ^ pref[r] ^ pref[l-1];
        }
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}