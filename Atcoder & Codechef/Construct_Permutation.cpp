#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


bool check(vector<int>&a){
    int flag = 0;
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            // cout << i << " " << j << " " << sum << " " << a.size()+1 << endl;
            if((sum % (a.size()+1)) == 0) flag = 1;
        }
    }
    return !flag;
}


void solve(){

    int n; cin >> n;
    vector<int>ans;
    for(int i=1;i<=n;i++) ans.push_back(i);
    

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