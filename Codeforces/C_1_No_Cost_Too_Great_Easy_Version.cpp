#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Num {
    int a, b, id;
    Num(int _a, int _b, int _id) : a(_a), b(_b), id(_id) {}
    operator < (Num t){
        return b <= t.b;
    }
};



void solve(){

    int n; cin >> n;
    vector<Num> v;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(Num(x, 1, i));
    } 
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i].b = x;
    }
    sort(v.begin(), v.end());

    for(auto i : v){
        cout << i.a << " " << i.b << " " << i.id << endl;
    }

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