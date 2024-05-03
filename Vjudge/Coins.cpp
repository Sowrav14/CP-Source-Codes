#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
map<char, int>a;

void func(string p){
    char x = p[0];
    char y = p[2];
    if(p[1] == '>'){
        a[x]++;
    } else {
        a[y]++;
    }
}

void solve(){

    string p,q,r; cin >> p >> q >> r;
    a['A'] = a['B'] = a['C'] = 0;
    func(p);
    func(q);
    func(r);
    map<int,char>m;
    for(auto i : a){
        // cout << i.first << " " << i.second << endl;
        m[i.second] = i.first;
    }

    if(m.size() != 3){
        cout << "Impossible" << endl;
    } else{
        for(auto i : m){
            cout << i.second;
        } cout << endl;
    }
}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}