#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    vector<int>oc(20, 0);
    for(int i=1;i<=7;i++) {
        int x; cin >> x;
        oc[x]++;
    }

    int two = 0, three = 0;
    for(int i=1;i<=13;i++){
        if(oc[i] >= 3) three++;
        else if(oc[i] >= 2) two++;
    }
    // cout << three << " " << two << endl;
    if(three > 0 and two + three >=2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    

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