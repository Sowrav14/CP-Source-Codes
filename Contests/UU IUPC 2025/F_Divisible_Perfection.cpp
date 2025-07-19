#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    if(n >= 5){
        cout << "NO" << endl;
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string t = s.substr(i, j - i + 1);
            int num = stoi(t);
            if(num % (j - i + 1) != 0){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}