#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 10, 0) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] = max(bit[idx], val);
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum = max(sum, bit[idx]);
            idx -= (idx) & (-idx);
        }
        return sum;
    }
};

void solve(){

    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    BIT bit(2*n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        // find l on a
        int x = 2*n - a[i] + 1;
        int l = bit.query(x);
        bit.update(x, i);
        
        // also find for b
        int y = 2*n - b[i] + 1;
        int ll = bit.query(y);

        // get the contri.
        int cnt = 0;
        if(a[i] == b[i]) cnt = i - l;
        cnt += min(l, ll);
        ans += cnt * (n - i + 1);
    }
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