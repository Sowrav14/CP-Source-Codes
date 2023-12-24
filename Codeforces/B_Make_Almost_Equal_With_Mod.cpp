#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n; cin >> n;
    vector<long long int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int k = 0;
    while(1){
        int zero = 0, one = 0;
        for(int i=0;i<n;i++){
            if(v[i] & (1ll << k)){
                one = 1;
            } else {
                zero = 1;
            }
        }
        if(one != 0 and zero != 0){
            cout << (1ll << (k+1)) << endl;
            return;
        }
        k++;
    }

}


int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}