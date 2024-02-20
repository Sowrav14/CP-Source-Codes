#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int>p,f;


bool check(int time){

    int l = 0;
    for(auto i : p){
        int cur = i;
        int t = time;
        if(l >= f.size()) return true;
        int leftmost = f[l];
        while(l < f.size()){
            if(f[l] < cur) l++;
            else break;
        }
        // cout << cur << " " << leftmost << endl;
        if(leftmost < cur){
            int dist = abs(leftmost - cur);
            int one = 2 * dist;
            one = time - one;
            int two = time - dist;
            // two = two / 2;
            two = floor(two/2.0);
            // cout << one << " " << two << endl;
            t = max(one, two);
        } else {
            t = time;
        }
        // cout << leftmost << " " << cur << endl;
        // cout << "time " << t << endl;
        

        if(t < 0) {
            return false;
        }

        while(l < f.size()){
            t -= abs(f[l] - cur);
            if(t < 0) break;

            cur = f[l];
            l++;
        }
    }

    if(l == f.size()) return true;
    else return false;

}



void solve(){

    int n; cin >> n;
    string s; cin >> s;

    // cout << floor(-1/2.0) << endl;

    for(int i=0;i<n;i++){
        if(s[i] == 'P'){
            p.push_back(i);
        }
        if(s[i] == '*'){
            f.push_back(i);
        }
    }
    // cout << check(2) << endl;

    int l = 0, r = 1e9;
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        } else{
            l = m + 1;
        }
    }
    cout << ans << endl;

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