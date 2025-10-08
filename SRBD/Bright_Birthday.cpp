#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<string> colors{
    "blue", 
    "green", 
    "yellow", 
    "red", 
    "purple", 
    "orange", 
    "pink", 
    "grey", 
    "cyan", 
    "brown", 
    "ash", 
    "silver", 
    "gold", 
    "white", 
    "black"
};

int mx = (1 << 15) - 1;
vector<vector<int>> hm(mx+1, vector<int>(26, 0));

void generate(){
    for(int i=0;i<=mx;i++){
        for(int j=0;j<15;j++){
            if(i & (1 << j)){
                for(char c : colors[j]){
                    hm[i][c-'a']++;
                }
            }
        }
    }
}

void solve(){

    string s; cin >> s;
    vector<int> fr(26);
    for(char c : s) fr[c-'a']++;

    int ans = 0;
    for(int i=0;i<mx;i++){
        bool flag = true;
        for(int j=0;j<26;j++){
            if(hm[i][j] > fr[j]) flag = false;
        }
        if(flag) ans = max(ans, 1ll * __builtin_popcount(i));
    }
    cout << ans << '\n';

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}