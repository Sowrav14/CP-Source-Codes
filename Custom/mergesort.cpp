#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000;
vector< int >g[N];
int par[N];
vector<int> child[N], val[N];

void solve(){

    vector<int>a;
    a.push_back(6);
    a.push_back(5);
    a.push_back(4);
    a.push_back(8);
    a.push_back(3);

    val[1] = a;

    int cur = 1;
    int newnode = 1;
    while(1){

        // cout << cur << " " << child[cur].size() << endl;
        // for(auto i : val[cur]){
        //     cout << i << " ";
        // } cout << endl;
        // cout << endl;

        int childCount = child[cur].size();
        if(val[cur].size() == 1){
            cur = par[cur];
            continue;
        }
        if(childCount == 0){
            // go left
            vector<int> temp;
            int m = (0 + val[cur].size() - 1) / 2;
            for(int i=0;i<=m;i++){
                temp.push_back(val[cur][i]);
            }
            newnode++;
            int next = newnode;
            g[cur].push_back(next);
            par[next] = cur;
            child[cur].push_back(next);
            val[next] = temp;
            cur = next;
        } else if(childCount == 1){
            // go right
            vector<int> temp;
            int m = (0 + val[cur].size() - 1) / 2;
            for(int i=m+1;i<val[cur].size();i++){
                temp.push_back(val[cur][i]);
            }
            newnode++;
            int next = newnode;
            g[cur].push_back(next);
            par[next] = cur;
            child[cur].push_back(next);
            val[next] = temp;
            cur = next;
        } else {
            // merge left, right
            int leftnode = child[cur][0];
            int rightnode = child[cur][1];

            vector<int>leftarray = val[leftnode];
            vector<int>rightarray = val[rightnode];

            // sort(leftarray.begin(), leftarray.end());
            // sort(rightarray.begin(), rightarray.end());

            vector<int>temp;
            for(auto i : leftarray) temp.push_back(i);
            for(auto i : rightarray) temp.push_back(i);
            sort(temp.begin(), temp.end());
            newnode++;
            val[newnode] = temp;

            g[leftnode].push_back(newnode);
            // g[rightnode].push_back(newnode);

            if(cur == 1){
                break;
            }
            int parent = par[cur];
            if(child[parent][0] == cur){
                child[parent][0] = newnode;
            } else{
                child[parent][1] = newnode;
            }
            cur = parent;
        }
    }
    
    vector<int>vis(1000, 0);
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        vector<int>temp;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            temp.push_back(u);
        }
        for(auto u : temp){

            for(auto arr : val[u]){
                cout << arr << " ";
            } cout << " ";

            for(auto v : g[u]){
                if(!vis[v]) q.push(v);
                vis[v] = 1;
            }
        }
        cout << endl;
    }
    
    
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