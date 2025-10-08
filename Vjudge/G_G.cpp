#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

double part = (2 * acos(-1) * 50) / 8;
double pi = acos(-1);

double get(int a, int b){
    int diff = abs(a - b);
    diff = min(diff, 8 - diff);
    double angle = diff * 45.0 * pi / 180.0;
    return 2 * 50 * sin(angle / 2.0);
}


void solve(){

    string s; cin >> s;
    int a = s[0] - '0';
    int b = s[2] - '0';

    int t = s[1];
    cout << fixed << setprecision(10);
    if(t == '-'){
        cout << get(a, b) << endl;
    } else if(t == 'v'){
        cout << (double)(100) << endl;
    } else if(t == '>'){
        int x = 0;
        while(a != b){
            x++;
            a = (a + 1);
            if(a == 9) a = 1;
        }
        cout << (double)(part * x) << endl;
    } else {
        int x = 0;
        while(a != b){
            x++;
            a = a - 1;
            if(a == 0) a = 8;
        }
        cout << (double)(part * x) << endl;
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