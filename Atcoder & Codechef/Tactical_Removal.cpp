#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 10) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] += val;
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx) & (-idx);
        }
        return sum;
    }
    // update the value at [l...r] by val.
    void update(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
    // sum form [l...r]
    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int n, k;

int getAns(BIT &id, BIT &val, int sz){
    int l = 1, r = n;
    int mid = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(id.query(m) <= sz){
            mid = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    // cout << mid << endl;
    int oneAns = val.query(mid);
    return oneAns;
}

void solve(){

    cin >> n >> k;
    int flag = (n - k) % 2;
    int sz = ceil((n - k) / 2.0);
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    BIT bit(n);
    BIT bitv(n);

    for(int i=0;i<n-k;i++){
        int x = v[i];
        bit.update(x, 1);
        bitv.update(x, x);
    }

    int cur = getAns(bit, bitv, sz);
    if(flag){
        cur += getAns(bit, bitv, sz-1);
    } else {
        cur += getAns(bit, bitv, sz);
    }
    int ans = cur;
    // cout << ans << endl;

    int r = n - 1;
    int l = n - k - 1;
    while(l>=0){
        // remove l
        int L = v[l];
        bit.update(L, -1);
        bitv.update(L, -L);

        // add r
        int R = v[r];
        bit.update(R, 1);
        bitv.update(R, R);

        cur = getAns(bit, bitv, sz);
        if(flag){
            cur += getAns(bit, bitv, sz-1);
        } else {
            cur += getAns(bit, bitv, sz);
        }
        // cout << l << " " << cur << endl;
        l--, r--;
        ans = max(ans, cur);
    }

    // int sz = ceil(k/2.0);
    // int l = 1, r = n;
    // int ans = 0;
    // while(l <= r){
    //     int m = (l + r) / 2;
    //     if(bit.query(m) <= sz){
    //         ans = m;
    //         l = m + 1;
    //     } else {
    //         r = m - 1;
    //     }
    // }
    // cout << ans << endl;
    // cout << bitv.query(ans) << endl;


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