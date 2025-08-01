#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


// 0 1 -> all 1s
// 0 2 -> all 2s
// 1 2 -> all 3s


void solve(){

    int n, s; cin >> n >> s;
    vector<int> v(3, 0);
    int sum = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        sum += x;
        v[x]++;
    }

    int rem = s - sum;
    if(rem < 0){
        for(int i=0;i<3;i++){
            for(int j=0;j<v[i];j++){
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    if(rem == 0){
        cout << -1 << endl;
        return;
    }

    if(rem % 2 == 0){
        cout << -1 << endl;
    } else if(rem != 1 and rem % 2){
        cout << -1 << endl;
    } else {
        for(int j=0;j<v[0];j++){
            cout << 0 << " ";
        }
        for(int j=0;j<v[2];j++){
            cout << 2 << " ";
        }
        for(int j=0;j<v[1];j++){
            cout << 1 << " ";
        }
        cout << endl;
    }

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