#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
string s, ss;
vector<int> pi(N);
vector<vector<int>> aut(N, vector<int>(26, 0));
vector<pair<int,int>> g[N];

int ans;

void compute_automaton(char ch){
    ss.push_back(ch);
    int i = ss.size() - 1;
    for(int c = 0; c < 26; c++){
        if(i > 0 && 'a' + c != ss[i])
            aut[i][c] = aut[pi[i-1]][c];
        else
            aut[i][c] = i + ('a' + c == ss[i]);
    }
    pi[i] = (i == 0 ? 0 : aut[pi[i-1]][ss[i] - 'a']);
}

void dfs(int u, int d, int id){
    if(d != 0){
        int k = d - pi[d - 1];
        if(d % k == 0 && d != k) ans = max(ans, k);
    }
    for(auto [v, c] : g[u]){
        compute_automaton(c);
        dfs(v, d + 1, aut[id][c - 'a']);
        ss.pop_back();
    }
}



void solve(){

    cin >> n;
    vector<int> a(n+1);
    for(int i=2;i<=n;i++){
        cin >> a[i];
    }
    cin >> s;
    for(int i=2;i<=n;i++){
        g[a[i]].push_back({i, s[i-2]});
    }

    dfs(1, 0, 0);
    cout << ans << endl;

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