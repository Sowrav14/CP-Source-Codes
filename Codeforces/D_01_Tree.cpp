#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    int flag = 0;
    int cnt = 0;
    for(int i=1;i<n;i++){
        flag = 0;
        while(v[i] >= v[i-1] and v[i] - v[i-1] < 2){
            i++;
            flag = 1;
        }
        if(flag == 1){
            // cout << i << endl;
            cnt++;
            i -= 1;
            continue;
        }

        while(v[i-1] >= v[i] and v[i-1] - v[i] <  2){
            i++;
            flag = 1;
        }
        if(flag == 1){
            // cout << i << endl;
            cnt++;
            i -= 1;
            continue;
        }
        if(flag == 0){
            cout << "NO" << endl;
            return;
        }
    }

    if(cnt <= 2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
