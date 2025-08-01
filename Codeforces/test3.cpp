#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
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


// contribution method.
// for each inversion.
// for each reduction if miror?


void solve(){

    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    BIT bit(n);

    int tot = 0;
    vector<int> inv(n+1, 0);
    for(int i=n;i>=1;i--){
        int x = bit.query(v[i] - 1);
        inv[i] = x;
        tot += x;
        bit.update(v[i], 1); 
    }
    // cout << tot << endl;

    vector<int> boro(n+10);
    BIT git(n);
    for(int i=1;i<=n;i++){
        int x = (i - 1) - (git.query(v[i]));
        boro[i] = x;
        git.update(v[i], 1);
    }
    // for(int i=1;i<=n;i++) cout << boro[i] << " "; cout << endl;

    int red = 0;
    for(int i=1;i<=n;i++){
        int curinv = inv[i];
        int itcostinv = boro[i];
        int right = n - i;
        int balance = right - curinv - itcostinv;
        if(balance > 0){
            continue;
        }
        else red += balance;
        // cout << balance << " ";
    }
    // cout << red << endl;
    cout << tot + red << endl;

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