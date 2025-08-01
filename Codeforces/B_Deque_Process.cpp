#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int l = 0, r = n - 1;
    string s = "";
    vector<int> t;
    while(l < r){
        int a = v[l];
        int b = v[r];

        string cur = "";
        if(a > b) cur = "LR";
        else {
            swap(a, b);
            cur = "RL";
        }

        if(t.empty()) {
            if(a > b){
                t.push_back(a);
                t.push_back(b);
                s += "LR";
            } else {
                t.push_back(b);
                t.push_back(a);
                s += "RL";
            }
        } else {
            int x = t.back();
            if(a > x){
                // cout << a << " " << b << endl;
                t.push_back(a);
                t.push_back(b);
                s += cur;
            } else {
                t.push_back(b);
                t.push_back(a);
                reverse(cur.begin(), cur.end());
                s += cur;
            }
        }
        l++, r--;
    }
    if(s.size() != n) s += 'L';
    cout << s << endl;
    // for(auto i : t) cout << i << " "; cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}