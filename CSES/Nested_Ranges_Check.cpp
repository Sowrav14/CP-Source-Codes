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


struct Segment{
	int l, r, id;
	Segment(int l, int r, int id): l(l), r(r), id(id) {}
};

void solve(){

    int n; cin >> n;
	vector<int>ans(n+1, 0);
	vector<Segment>seg;
	for(int i=1;i<=n;i++){
		int l,r; cin >> l >> r;
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
		s.insert(l);
	}

	for(int i=1;i<=n;i++) cout << (ans[i] ? 1 : 0) << " \n"[i == n];
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
		os.insert(r);
	}
	
	for(int i=1;i<=n;i++) cout << (res[i] ? 1 : 0) << " \n"[i == n];

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