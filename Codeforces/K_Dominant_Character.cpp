#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
string s;
int freq[N][26];

int ishere(int l, int r, int c){
    int x = freq[r][c] - freq[l-1][c];
    return x>0;
}

bool ccheck(int k, int c){
    int flag = 1;
    for(int i=1;i<=n;i++){
        if(i+k-1 > n) break;
        flag &= ishere(i, i+k-1, c);
    }
    return flag;
}

bool check(int k){
    int flag = 0;
    for(int i=0;i<26;i++){
        if(ccheck(k, i)) flag = 1;
    }
    return flag;
}


void solve(){

    cin >> s;
    n = s.size();
    for(int i=0;i<26;i++) freq[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int c=0;c<26;c++) freq[i][c] = freq[i-1][c];
        freq[i][s[i-1]-'a']++;
    }

    int ans = n;
    int l = 1, r = n;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        } else {
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}