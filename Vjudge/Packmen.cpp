#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int>p,f;
vector<int>rp, rf;

bool check(int time){

    int l = 0;
    for(auto i : p){
        int cur = i;
        int t = 0;
        if(l >= f.size()) return true;
        int leftmost = f[l];
        while(l < f.size()){
            if(f[l] < cur) l++;
            else break;
        }

        if(leftmost < cur){
            t += abs(leftmost - cur);
            cur = leftmost;
        }

        if(t > time) {
            return false;
        }

        while(l < f.size()){
            t += abs(f[l] - cur);
            if(t > time) break;

            cur = f[l];
            l++;
        }
    }

    if(l == f.size()) return true;
    else return false;

}

bool check2(int time){

    int l = 0;
    for(auto i : rp){
        int cur = i;
        int t = 0;
        if(l >= rf.size()) return true;
        int leftmost = rf[l];
        while(l < rf.size()){
            if(rf[l] < cur) l++;
            else break;
        }

        if(leftmost < cur){
            t += abs(leftmost - cur);
            cur = leftmost;
        }

        if(t > time) {
            return false;
        }

        while(l < rf.size()){
            t += abs(rf[l] - cur);
            if(t > time) break;

            cur = rf[l];
            l++;
        }
    }

    if(l == rf.size()) return true;
    else return false;

}


void solve(){

    int n; cin >> n;
    string s; cin >> s;

    for(int i=0;i<n;i++){
        if(s[i] == 'P'){
            p.push_back(i);
        }
        if(s[i] == '*'){
            f.push_back(i);
        }
    }

    reverse(s.begin(), s.end());
    for(int i=0;i<n;i++){
        if(s[i] == 'P'){
            rp.push_back(i);
        }
        if(s[i] == '*'){
            rf.push_back(i);
        }
    }


    int l = 0, r = 1e9;
    int ans = 1e9;
    cout << check2(26) << endl;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m) or check2(m)){
            ans = min(m, ans);
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