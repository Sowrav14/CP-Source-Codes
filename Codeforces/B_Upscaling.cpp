#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<vector<char>>ans;

    for(int i=1;i<=n;i++){
        char ch[2];
        if(i%2){
            ch[0] = '#';
            ch[1] = '.';
        } else {
            ch[0] = '.';
            ch[1] = '#';
        }
        vector<char>res;
        for(int j=1;j<=n;j++){
            if(j%2){
                res.push_back(ch[0]);
                res.push_back(ch[0]);
            } else{
                 res.push_back(ch[1]);
                 res.push_back(ch[1]);
            }
        }
        ans.push_back(res);
        ans.push_back(res);    
    }

    for(auto res : ans){
        for(auto c : res) cout << c; cout << endl;
    }

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