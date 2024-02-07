#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    // set for keeping ending values of lis es
    set<int>s;
    // vector for lis es
    vector<int>lis[n+10];
    // map for keep trace of lis with ending value.
    // m[i] = j  j th lis end i with 
    map<int,int>m;

    lis[1].push_back(v[1]);
    s.insert(v[1]);
    m[v[1]] = 1;
    int count = 1;
    for(int i=2;i<=n;i++){
        // determine suitable lis by ending values of lis es.
        auto it = s.upper_bound(v[i]);
        if(it == s.begin()){
            // new lis initalizes...
            count++;
            lis[count].push_back(v[i]);
            s.insert(v[i]);
            m[v[i]] = count;
            continue;
        }
        it--;
        
        // in which idx the lis is.
        int id = m[*it];
        // updating the lis.
        lis[id].push_back(v[i]);

        // settle the set.
        s.erase(it);
        s.insert(v[i]);

        // settle the map.
        m[v[i]] = id;

    }

    for(int i=1;i<=count;i++){
        for(auto j : lis[i]) cout << j << " "; cout << endl;
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