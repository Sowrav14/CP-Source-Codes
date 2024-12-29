#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int f = 1;
    for(int i=0;i<n;i++){
        if(a[i] == '#' and b[i] == '#'){
            continue;
        } else if(a[i] == '#' and b[i] == '.'){
            if(i+1 < n and b[i+1] == '.'){
                b[i+1] = '#';
            } else {
                f = 0;
                break;
            }
        } else if(a[i] == '.' and b[i] == '#'){
            if(i+1 < n and a[i+1] == '.'){
                a[i+1] = '#';
            } else {
                f = 0;
                break;
            }
        } else {
            if(i+1 < n and a[i+1] == '.' and b[i+1] == '.'){
                f = 2;
            }
            a[i] = '#';
            b[i] = '#';
        }
    }

    if(f == 0){
        cout << "None" << endl;
    } else if(f == 1){
        cout << "Unique" << endl;
    } else {
        cout << "Multiple" << endl;
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