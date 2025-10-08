#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int x;
map<pair<int,int>, int> m;

int recur(int i, int j){
    if(i*2 + j*3 > x){
        return 10000;
    }
    if(i*2 + j*3 == x){
        return 0;
    }
    pair<int,int> t = {i, j};
    if(m.count(t) != 0) return m[t];
    int ans = 10000;
    ans = min(ans, 4 + recur(i+1, j));
    ans = min(ans, 5 + recur(i, j+1));
    return m[t] = ans;
}

void solve(){

    cin >> x;
    m.clear();
    cout << recur(0, 0) << endl;

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