#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v, a, b;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x > 0){
            a.push_back(x);
        } else if(x < 0){
            b.push_back(x);
        } else{
            if(v.size() < 2) v.push_back(x);
        }
    }
    if(a.size() > 2 or b.size() > 2){
        cout << "NO" << endl;
        return;
    }
    for(auto i : a) v.push_back(i);
    for(auto i : b) v.push_back(i);
    n = v.size();
    // for(auto i : v) cout << i << " "; cout << endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int x = v[i] + v[j] + v[k];
                bool cur = false;
                for(int it=0;it<n;it++){
                    if(v[it] == x) cur = true;
                }
                if(cur == false) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;

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