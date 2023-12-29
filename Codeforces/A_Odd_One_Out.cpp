#include<bits/stdc++.h>
using namespace std;


void solve(){

    int a,b,c; cin >> a >> b >> c;
    if(a == b){
        cout << c << endl;
    } else if(a == c){
        cout << b << endl;
    } else {
        cout << a << endl;
    }

}


int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}