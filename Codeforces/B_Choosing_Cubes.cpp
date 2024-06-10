#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,f,k; cin >> n >> f >> k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int favo = a[f-1];

    sort(a.rbegin(), a.rend());
    queue<int>ff;
    for(int i=0;i<n;i++) ff.push(a[i]);
    int last = -1;

    for(int i=0;i<k;i++){
        if(!ff.empty()){
            last = ff.front();
            ff.pop();
        }
    }

    // cout << ff.front() << " " << ff.size() << " " << last << " " << favo << endl;
    if(ff.empty()){
        cout << "YES" << endl;
    } else if(ff.front() < favo){
        cout << "YES" << endl;
    } else if(ff.front() == favo and last == favo){
        cout << "MAYBE" << endl;
    } else{
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