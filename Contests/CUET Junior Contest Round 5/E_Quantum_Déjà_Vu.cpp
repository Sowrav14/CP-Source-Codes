#include <bits/stdc++.h>
using namespace std;
 
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
};
 
 
void solve() {
	int n;
	cin >> n;
 
	vector<int> arr(n+10); for(int i = 1; i <= n; i++) cin >> arr[i];
	vector<vector<pair<int, pair<int,int>>>> queries(n+1);
	int q; cin >> q;
    for(int i = 1; i <= q; i++) {
		int a, b; cin >> a >> b;
        int tot = b - a + 1;
		queries[a].push_back({b, {i, tot}});
	}
 
	BIT bit(n);
	
    // last_index[val] is the left-most index where arr[last_index[val]] = val.
	map<int, int> last_index;
 
	vector<int> ans(q+1, -1);
	// Update the indices and answer queries from right to left.
	for (int i = n; i >= 1; i--) {
		int val = arr[i];
		//  * If val already appeared earlier, then the saved value is no
		//  * longer the left-most index, so erase it from our BIT.
		if (last_index.count(val) > 0) bit.update(last_index[val], -1);
		// i becomes the left-most index.
		last_index[val] = i;
		bit.update(i, 1);
		// Answer all queires with starting here  i.e a == i.
		for (auto &qr : queries[i]) {
			//  * The solution for this query is bit[i,b].
			//  * This equals bit[0,b] since bit[0,i-1] = 0.
            int res = bit.query(qr.first);
            int tot = qr.second.second;
            int id = qr.second.first;
            if(tot == res) ans[id] = 0;
            else ans[id] = 1;
			// ans[qr.second] = bit.query(qr.first);
		}
	}
 
	for(int i=1;i<=q;i++){ 
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
}
 
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}