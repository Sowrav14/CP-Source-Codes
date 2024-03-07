#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int>v;
bool check(int id){
    map<int,int>a,b;
    for(int i=0;i<id;i++){
        a[v[i]]++;
    }
    for(int i=n-1;i>=id;i--){
        b[v[i]]++;
    }

    int m1 = 0;
    for(auto i : a){
        if(i.first != m1) break;
        else m1++;
    }
    int m2 = 0;
    for(auto i : b){
        if(i.first != m2) break;
        else m2++;
    }

    return m1 == m2;
}



void solve(){

    cin >> n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    int l=1, r = n-1;
    while(l <= r){
        int m = (l + r) / 2;
        cout << m << endl;
        if(check(m)){
            cout << 2 << endl;
            cout << 1 << " " << m << endl;
            cout << m+1 << " " << n << endl;
            return;
        } else{
            l = m + 1;
        }
    }
    cout << -1 << endl;

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