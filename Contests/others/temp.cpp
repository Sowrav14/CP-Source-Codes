#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;

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
    pi[i] = (i == 0 ? 0 : aut[i-1][ss[i] - 'a']);
}

void dfs(int source, int d, int id){
    if(d != 0){
        int k = d - pi[d-1] - 1;
        if(d % k == 0 && d != k) ans = max(ans, k);
    }
    for(auto [child, ch] : g[source]){
        compute_automaton(ch);
        int new_id = id + 1; // or some new identifier for pi length
        dfs(child, d + 1, new_id);
        ss.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 2; i <= n; i++) cin >> a[i];
        cin >> s;

        for(int i = 2; i <= n; i++)
            g[a[i]].push_back({i, s[i-2]});

        dfs(1, 0, 0);
        cout << ans << endl;
    }

    return 0;
}
