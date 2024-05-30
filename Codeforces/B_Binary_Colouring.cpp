#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void shift(vector<int>&ans){
    for(int i=30;i>=1;i--){
        if(ans[i] == 1 and ans[i-1] == 1){
            ans[i] = 0;
            ans[i+1] = 1;
            ans[i-1] = -1;
        } else if(ans[i] == 1 and ans[i-1] == -1){
            ans[i] = 0;
            ans[i-1] = 1;
        } else if(ans[i] == -1 and ans[i-1] == 1){
            ans[i] = 0;
            ans[i-1] = -1;
        }
    }
}


bool check(vector<int>&a){
    for(int i=0;i<32;i++){
        if(a[i] != 0 and a[i+1] != 0){
            return false;
        }
    }
    return true;
}



void solve(){

    int x; cin >> x;
    int i = 0;
    vector<int>ans(33, 0);

    while(i<33){
        if(x & (1 << i)){
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
        i++;
    }

    // for(int i=0;i<10;i++) cout << ans[i] << " "; cout << endl;
    while(!check(ans)){
        shift(ans);
    }
    cout << 32 << endl;
    for(int i=0;i<32;i++){
        cout << ans[i] << " ";  
    } cout << endl;

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