/**
 * @tags: Trie bits
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Trie {

	// Node structure of Trie...
  	struct Node {
    	Node* links[2];	// two possibility to go next.
    	bool vis;
		Node() {
			links[0] = links[1] = NULL;
			vis = false;
		}
  	} *root;

	Trie() {
		root = new Node();
	}

  	void query(int x, Node* cur, string &s) {
    	if(x == 0){
            cur->vis = 1;
            return;
        }
        if(cur->links[0] == NULL){
            cur->links[0] = new Node();
			s += '0';
			query(x-1, cur->links[0], s);
        } else if(cur->links[0]->vis == 0){
			s += '0';
			query(x-1, cur->links[0], s);
		} else if(cur->links[1] == NULL){
			s += '1';
			cur->links[1] = new Node();
			query(x-1, cur->links[1], s);
		} else if(cur->links[1]->vis == 0){
			s += '1';
			query(x-1, cur->links[1], s);
		}

		if(cur->links[0] != NULL and cur->links[1] != NULL){
			if(cur->links[0]->vis == 1 and cur->links[1]->vis == 1){
				cur->vis = 1;
			}
		}
  	}

} trie;

string ans[N];

void solve(){

	int n; cin >> n;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());

	for(int i=0;i<n;i++){
		string res = "";
		trie.query(v[i].first, trie.root, res);

		if(res.size() != v[i].first){
			cout << "NO" << endl;
			return;
		}
		ans[v[i].second] = res;
	}

	cout << "YES" << endl;
	for(int i=0;i<n;i++){
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