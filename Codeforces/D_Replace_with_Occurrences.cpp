#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    map<int,vector<int>> m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    map<int,int> out;
    int it = 1;
    vector<int> ans(n);
    for(auto i : m){
        int x = i.first;
        int y = i.second.size();
        if(y % x){
            cout << -1 << endl;
            return;
        }
        int cnt = 0;
        for(int j=0;j<i.second.size();j++){
            if(cnt >= x){
                cnt = 0;
                it++;
            }
            ans[i.second[j]] = it;
            cnt++;
        }
        it++;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

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