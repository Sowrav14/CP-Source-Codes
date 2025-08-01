#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k, x;
vector<string> v;
vector<string> s;
vector<int> sub;

void recur(int i){
    if(i == k) {
        string res = "";
        for(int j : sub){
            res += s[j];
        }
        v.push_back(res);
        return;
    }

    for(int k=0;k<n;k++){
        sub[i] = k;
        recur(i+1);
    }
}


void solve(){

    cin >> n >> k >> x;
    for(int i=0;i<n;i++){
        string t; cin >> t;
        s.push_back(t);
    }
    
    sub.resize(k, 0);
    recur(0);

    sort(v.begin(), v.end());
    cout << v[x-1] << endl;

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