#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// time 1 : 35

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n);

    queue<int> t;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            t.push(i+1);
        } else {
            v[i] = i + 1;
            int j = i - 1;
            if(t.size() == 1) return cout << "NO" << endl, void();
            while(!t.empty()){
                v[j--] = t.front();
                t.pop();
            }
        }
    }
    int j = n - 1;
    if(t.size() == 1) return cout << "NO" << endl, void();
    while(!t.empty()){
        v[j--] = t.front();
        t.pop();
    }

    cout << "YES" << endl;
    for(int i=0;i<n;i++) cout << v[i] << " "; cout << endl;

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