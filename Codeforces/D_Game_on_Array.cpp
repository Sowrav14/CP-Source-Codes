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
    map<int,int> m;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        m[x]++;
    }
    vector<pair<int,int>> v;
    for(auto i : m){
        v.push_back({i.second, i.first});
    }
    sort(v.rbegin(), v.rend());

    int turn = 0;
    int alice = 0, bob = 0;
    for(auto i : v){
        int x = i.first;
        int y = i.second;

        int a = (y + 1) / 2;
        int b = y / 2;

        if(turn == 0){
            alice += a * x;
            bob += b * x;
        } else {
            alice += b * x;
            bob += a * x;
        }

        if(y % 2){
            turn = 1 - turn;
        }
    }
    cout << alice << " " << bob << endl;

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