#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

const int MAX = 1e7;
vector<int> spf(MAX + 1);

void computeSPF() {
    for (int i = 1; i <= MAX; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}


map<int,int> prime_factorize(int x) {
    map<int,int>m;
    while (x != 1) {
        m[x]++;
        x /= spf[x];
    }
    return m;
}

int getans(map<int,int> a, map<int,int> b){
    // for(auto i : a) cout << i.first << " " << i.second << endl;
    // for(auto i : b) cout << i.first << " " << i.second << endl;
    // if(a.size() > b.size()) a.swap(b);
    for(auto i : a){
        b[i.first] += i.second;
    }
    // for(auto i : b) cout << i.first << " " << i.second << endl;
    int ans = 1;
    for(auto i : b){
        ans = (ans%M * (i.second + 1)%M)%M;
    }
    return ans%M;
}


void solve(){

    computeSPF();
    int n, m; cin >> n >> m;
    map<int,int>a;
    for(int i=1;i<=m;i++){
        map<int,int>x = prime_factorize(i);
        for(auto i : x){
            a[i.first] += i.second;
        }
    }
    // for(auto i : a){
    //     cout << i.first << " " << i.second << endl;
    // }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        // cout << x << endl;
        map<int,int> b = prime_factorize(x);
        cout << getans(b, a) << " \n"[i == n];
    }
    // cout << "done" << endl;
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