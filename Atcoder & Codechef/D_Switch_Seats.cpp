#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve() {
    int n; cin >> n;
    vector<int> a(2*n+1);
    for(int i=1; i<=2*n; i++) {
        cin >> a[i];
    }
    
    vector<int> pos1(n+1, 0), pos2(n+1, 0);
    for(int i=1; i<=2*n; i++) {
        if(pos1[a[i]] == 0) {
            pos1[a[i]] = i;
        } else {
            pos2[a[i]] = i;
        }
    }
    vector<bool> not_adjacent(n+1, false);
    for(int i=1; i<=n; i++) {
        if(abs(pos1[i] - pos2[i]) != 1) {
            not_adjacent[i] = true;
        }
    }

    set<pair<int, int>> valid_pairs;

    for(int i=1; i<2*n; i++) {
        int num1 = a[i];
        int num2 = a[i+1];
        
        if(!not_adjacent[num1] || !not_adjacent[num2]) continue;
        
        int other_pos1 = (pos1[num1] == i) ? pos2[num1] : pos1[num1];
        int other_pos2 = (pos1[num2] == i+1) ? pos2[num2] : pos1[num2];
        
        if(abs(other_pos1 - other_pos2) == 1) {
            int min_val = min(num1, num2);
            int max_val = max(num1, num2);
            valid_pairs.insert({min_val, max_val});
        }
    }
    
    cout << valid_pairs.size() << endl;
}

signed main() {
    Fast_IO();
    int t = 1;
    cin >> t;
    for(int i=1; i<=t; i++) {
        solve();
    }
    return 0;
}