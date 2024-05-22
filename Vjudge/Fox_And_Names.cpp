#include<bits/stdc++.h>
using namespace std;
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 30;
set<int>adj[N];


// Function to return list containing vertices in Topological order.
void topologicalSort() {
	// Vector to store indegree of each vertex
	vector<int> indegree(26, 0);
	for (int i=0;i<26;i++){
		for (auto it : adj[i]){
			indegree[it]++;
		}
	}

	// Queue to store vertices with indegree 0
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i=0;i<26;i++) {
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
	if (result.size() != 26) {
		cout << "Impossible" << endl;
        return;
	}

	for(auto i : result) cout << char(i+'a'); cout << endl;
}


int main() {

    int n; cin >> n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        v.push_back(s);
    }

    for(int i=0;i<n;i++){
        string a = v[i];
        for(int j=i+1;j<n;j++){
            string b = v[j];
            int flag = 0;
            for(int k=0;k<min(a.size(), b.size());k++){
                if(a[k] != b[k]){
                    // cout << a[k] << "      " << b[k] << endl;
                    adj[a[k] - 'a'].insert(b[k] - 'a');
                    flag = 1;
                    break;
                }
            }
            // cout << a.size() << " " << b.size() << " " << flag << endl;
            if(flag == 0 and a.size() > b.size()){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    // for(int i=0;i<26;i++){
    //     for(auto child : adj[i]){
    //         cout << char(i+'a') << " " << char(child+'a') << endl;
    //     }
    // }
    topologicalSort();
    return 0;
}
