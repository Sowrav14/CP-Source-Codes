#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<vector<int>> v;

void generate(){
    v.push_back({6, 3, 0});
    v.push_back({6, 1, 1});
    v.push_back({4, 3, 1});
    v.push_back({4, 4, 0});
    v.push_back({4, 2, 1});
    v.push_back({3, 3, 3});
    v.push_back({2, 2, 2});
}

void solve(){

    vector<int>a(3);
    for(int i=0;i<3;i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    bool flag = 0;
    for(vector<int> i : v){
        if(i == a) flag = 1;
    }
    if(flag){
        cout << "perfectus" << endl;
    } else {
        cout << "invalidum" << endl;
    }

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}