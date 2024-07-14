#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void solve(){

    int n; cin >> n;
    if(n == 1){
        cout << 9999 << endl;
        for(int i=2;i<=10000;i++){
            cout << i << " " << i-1 << endl;
        }
        return;
    }
    string sn = to_string(n);
    vector<pair<int,int>>ans;
    int i = 0;
    string s = "";
    while(1){
        s += sn[i];
        i = (i + 1) % sn.size();
        if(s.size() >= 18) break;
        int p = stoll(s);
        int q = s.size();
        int a = p - q;
        a /= (n - sn.size());

        int b = a * sn.size() - q;

        if(n*a - b == p and 1 <= a and a <= 10000 and 1 <= b and b <= 10000){
            ans.push_back({a, b});
        }
    }


    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
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