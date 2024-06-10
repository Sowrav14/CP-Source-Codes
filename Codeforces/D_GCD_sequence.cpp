#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


bool isvalid(int id, vector<int>&vec){
    vector<int>a;
    for(int i=0;i<vec.size();i++){
        if(i == id) continue;
        a.push_back(vec[i]);
    }

    vector<int>seq;
    for(int i=1;i<a.size();i++){
        seq.push_back(__gcd(a[i], a[i-1]));
    }

    bool ret = 1;
    for(int i=1;i<seq.size();i++){
        if(seq[i] < seq[i-1]){
            ret = 0;
        }
    }
    return ret;
}


void solve(){

    int n; cin >> n;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<int>sec;
    for(int i=0;i<n-1;i++){
        sec.push_back(__gcd(v[i], v[i+1]));
    }
    int flag = 1;
    int id = -1;
    for(int i=1;i<sec.size();i++){
        if(sec[i] < sec[i-1]){
            flag = 0;
            id = i;
            break;
        }
    }

    if(flag == 1){
        cout << "YES" << endl;
        return;
    }
    // cout << id << endl;
    
    for(int i = max(id-2, 0ll); i<=min(n-1, id+2);i++){
        // cout << i << " " << n-1 << endl;
        if(isvalid(i, v)) flag = true;
    }

    cout << (flag ? "YES" : "NO") << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}