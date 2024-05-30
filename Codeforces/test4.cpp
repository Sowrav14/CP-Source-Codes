#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    string s; cin >> s;

    int flag = 1;
    char prev = '0';
    int p = 0;
    for(int i=0;i<n;i++){   
        if(isdigit(s[i])){
            if(prev > s[i]){
                flag = 0;
                break;
            } else{
                p = i + 1;
                prev = s[i];
            }
        } else {
            p = i;
            break;
        }
    }
    // cout << p << endl;
    if(flag == 0){
        cout << "NO" << endl;
        return;
    }
    char pr = 'a';
    for(int i=p;i<n;i++){
        if(isdigit(s[i])){
            flag = 0;
            break;
        } else if(s[i] < pr){
            flag = 0;
            break;
        } else{
            pr = s[i];
        }
    }

    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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