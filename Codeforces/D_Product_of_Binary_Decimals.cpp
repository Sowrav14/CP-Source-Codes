#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int>a;
void generate(){
    vector<int> elements = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 
                            1011, 1100, 1101, 1110, 1111, 10000, 10001, 
                            10010, 10011, 10100, 10101, 10110, 10111, 
                            11000, 11001, 11010, 11011, 11100, 11101, 
                            11110, 11111};
    a = elements;
}


bool recur(int num, int n){
    if(num == n) return true;
    if(num > n) return false;

    bool ans = false;
    for(int i=0;i<31 and a[i]<=n;i++){
        ans |= recur(num*a[i], n);
    }
    return ans;
}


void solve(){

    int n; cin >> n;
    cout << (recur(1, n) ? "YES" : "NO") << endl;

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}