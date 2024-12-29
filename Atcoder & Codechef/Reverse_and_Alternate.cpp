#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


bool isAlt(string s){
    int f = 1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == s[i+1]) f = 0;
    }
    return f;
}

bool solve(int n, string s){

    int l = -1;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            l = i + 1;
            break;
        }
    }

    if(l == -1){
        return 1;
    }

    int r = n-1;
    for(int i=n-1;i>=1;i--){
        if(i-1<=l) break;
        if(s[i] == s[i-1]){
            r = i - 1;
            break;
        }
    }

    // cout << l << " " << r << endl;
    string ss;
    for(int i=0;i<l;i++) ss += s[i];
    for(int i=r;i>=l;i--) ss += s[i];
    for(int i=r+1;i<n;i++) ss += s[i];

    return isAlt(ss);

}

void gg(){
    int n; cin >> n;
    string s; cin >> s;

    string rs = s;
    reverse(rs.begin(), rs.end());

    cout << ((solve(n, s) | solve(n, rs)) ? "Yes" : "No") << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        gg();
    }
}