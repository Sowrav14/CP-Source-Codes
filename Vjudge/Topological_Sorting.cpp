/*
 * @file Topological_Sorting.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * @problem: Topological sort....
 * @approach: Kahn’s algorithm for Topological Sorting
 * @explanation: Hint: Indegree...
 *               Gfg : https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 10000 + 10;
set<int>adj[N];


// Function to return list containing vertices in Topological order.
void topologicalSort(int V) {
	// Vector to store indegree of each vertex
	vector<int> indegree(V+1, 0);
	for (int i=1;i<=V;i++){
		for (auto it : adj[i]){
			indegree[it]++;
		}
	}

	// Queue to store vertices with indegree 0
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i=V;i>=1;i--) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> result;
	while (!q.empty()) {
		int node = q.top();
		q.pop();
		result.push_back(node);
	
		// Decrease indegree of adjacent vertices as the
		// current node is in topological order
		for (auto it : adj[node]) {
			indegree[it]--;
		
			// If indegree becomes 0, push it to the queue
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	// Check for cycle
	if (result.size() != V) {
		cout << "Sandro fails." << endl;
        return;
	}

	for(auto i : result) cout << i << " "; cout << endl;
}


signed main() {

	int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].insert(v);
    }

	topologicalSort(n);
}
