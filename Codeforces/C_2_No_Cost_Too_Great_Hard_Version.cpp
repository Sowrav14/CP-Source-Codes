#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Num {
    int a, b, id;
    Num(int _a, int _b, int _id) : a(_a), b(_b), id(_id) {}
    bool operator<(const Num &t) const {
    return b < t.b;
}

};

vector<int> spf[N];
void sieve(){
    for(int i=2;i<=N-5;i++){
        if(spf[i].empty()){
            for(int j=i;j<=N-5;j+=i){
                spf[j].push_back(i);
            }
        }
    }
}


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

    map<int, int> m;
    int ans = v[0].b + v[1].b;
    for(int i=0;i<n;i++){
        for(auto p : spf[v[i].a]) {
            m[p]++;
            if(m[p] > 1) ans = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(auto p : spf[v[i].a]) m[p]--;
        for(auto p : spf[v[i].a+1]) if(m[p] == 1) ans = min(ans, v[i].b);
        for(auto p : spf[v[i].a]) m[p]++;
    }
    

    vector<int> check;
    for(int i=1;i<n;i++){
        for(int x : spf[v[i].a])
            check.push_back(x);
    }

    for (int x : check){
        int times = x - (v[0].a % x);
        if (times == x)
            times = 0;

        ans = min(ans, times * v[0].b);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    sieve();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}