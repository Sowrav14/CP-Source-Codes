#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1010;
set<int>adj[N];

void reset(int n){
    for(int i=0;i<n;i++){
        adj[i].clear();
    }
}

void topologicalSort(int V) {
	vector<int> indegree(V, 0);
	vector<int> rank(V);
	for (int i=0;i<V;i++){
		for (auto it : adj[i]){
			indegree[it]++;
		}
	}

	queue<int>q;
	for (int i=0;i<V;i++) {
		if (indegree[i] == 0) {
			q.push(i);
            rank[i] = 1;
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
        int flag = 0;
		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0){
				q.push(it);
                rank[it] = rank[node] + 1;
            }
		}
	}

	vector<pair<int,int>>ans;
	for(int i=0;i<V;i++){
		ans.push_back({rank[i], i});
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans){
		cout << i.first << " " << i.second << endl;
	}

}


void solve(){

    int n,m; cin >> n >> m;
    reset(n);
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        adj[v].insert(u);
    }
    topologicalSort(n);

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Scenario #" << i << ":" << endl;
        solve();
    }
}