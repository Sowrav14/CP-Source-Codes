#include<bits/stdc++.h>
using namespace std;


void solve(){

    char a[3][3];
    int x,y;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
            if(a[i][j] == '?'){
                x = i, y = j;
            }
        }
    }

    int fa = 0, fb = 0, fc = 0;
    for(int i=0;i<3;i++){
        if(a[x][i] == 'A') fa  = 1;
        else if(a[x][i] == 'B') fb = 1;
        else if(a[x][i] == 'C') fc = 1;
    }

    if(fa == 0){
        cout << 'A' << endl;
    } else if(fb == 0){
        cout << 'B' << endl;
    } else {
        cout << 'C' << endl;
    }

    

}


int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}