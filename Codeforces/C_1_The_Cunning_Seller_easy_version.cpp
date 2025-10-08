#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


vector<int> pows;
vector<int> c;
void generate(){
    long long p = 1;
    for(int x=0;p<=1e10;x++,p*=3){
        pows.push_back(p);
        if(x == 0) c.push_back(3);
        else c.push_back(p * 3 + x * (p / 3));
    }
}

void solve(){

    int n; cin >> n;

    int ans = 0;
    for(int i=pows.size()-1;i>=0;i--){
        int res = n / pows[i];
        n -= res * pows[i];
        ans += res * c[i];
    }
    cout << ans << endl;

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