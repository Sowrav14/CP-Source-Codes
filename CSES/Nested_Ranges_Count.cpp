/*
 * @file Nested_Ranges_Count.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-06-23
 * @copyright Copyright (c) 2024
 * @problem: CSES -> https://cses.fi/problemset/task/2169
 * @approach: BIT
 * @explanation:
 */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// Ordered Set Tree
#define int long long int
#define ordered_set tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).

struct Fenwick {
	int n; vector<int> bit;
	Fenwick() {}
	Fenwick(int _n) {
		n = _n; bit.assign(n + 1, 0);
	}
	int query(int i) {
		int ans = 0;
		for (; i >= 1; i -= (i & -i)) ans += bit[i];
		return ans;
	}
	void upd(int i, int val) {
		if (i <= 0) return;
		for (; i <= n; i += (i & -i)) bit[i] += val;
	}
	void upd(int l, int r, int val) {
		upd(l, val);
		upd(r + 1, -val);
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

struct Segment{
	int l, r, id;
	Segment(int l, int r, int id): l(l), r(r), id(id) {}
};

void solve(){

    int n; cin >> n;
	vector<int>ans(n+1, 0);
	// vector<int>points;
	// map<int, stack <pair <int,int> > > left, right;
	vector<Segment>seg;
	for(int i=1;i<=n;i++){
		int l,r; cin >> l >> r;
		// points.push_back(l);
		// points.push_back(r);
		// right[l].push({r, i});
		seg.push_back(Segment(l, r, i));
	}

	sort(seg.begin(), seg.end(), [](Segment a, Segment b){
		if(a.r != b.r) return a.r < b.r;
		return a.l > b.l;
	});

	ordered_set s;
	for(auto i : seg){
		int l = i.l;
		int r = i.r;
		int id = i.id;

		int large = s.size() - s.order_of_key(l);
		ans[id] = large;
		// cout << l << " " << r << " " << id << " " << large << endl;
		s.insert(l);
	}


	// using bit...
	// sort(points.begin(), points.end());
	// points.erase(unique(points.begin(), points.end()), points.end());
	// int sz = points.size();
	// Fenwick fen(sz);

	// for(int i=0;i<sz;i++){
	// 	int it = points[i];
	// 	while(!right[it].empty()){
	// 		int p = right[it].top().first;
	// 		int id = right[it].top().second;
	// 		right[it].pop();
	// 		left[p].push({i+1, id});
	// 	}

	// 	while(!left[it].empty()){
	// 		int l = left[it].top().first;
	// 		int id = left[it].top().second;
	// 		left[it].pop();

	// 		int res = fen.query(l, i+1);
	// 		ans[id] = res;
	// 		fen.upd(l, 1);
	// 	}
	// }

	for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;
	vector<int>res(n+1, 0);
	ordered_set os;
	sort(seg.begin(), seg.end(), [](Segment a, Segment b){
		if(a.l != b.l) return a.l < b.l;
		else return a.r > b.r;
	});
	for(auto i : seg){

		int l = i.l;
		int r = i.r;
		int id = i.id;

		int large = os.size() - os.order_of_key(r);
		res[id] = large;
		// cout << l << " " << r << " " << id << " " << large << endl;
		os.insert(r);
	}
	
	for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;

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