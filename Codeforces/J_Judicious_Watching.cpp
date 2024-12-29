#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Job{
    Job(){}
    int du, st, en;
};

void solve(){

    int n, m, q; cin >> n >> m >> q;
    cout << n << endl;
    vector<Job>j(n);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        j[i].du = x;
    }
    for(int i=0;i<n;i++){
        int x; cin >> x;
        j[i].en = x;
        j[i].st = j[i].en - j[i].du;
    }
    vector<int>ser(m);
    for(int i=0;i<m;i++) cin >> ser[i];
    // vector<int>t(q);
    // for(int i=0;i<q;i++) cin >> t[i];
    sort(j.begin(), j.end(), [](Job a, Job b){
        if(a.st != b.st) return a.st < b.st;
        else return a.en < b.en;
    });
    for(int i=0;i<n;i++){
        cout << j[i].st << " " << j[i].du << " " << j[i].en << endl;
    }

    vector<int>ft(n);

    while(q--){
        int t; cin >> t;

        int pos = n;
        int l = 0, r = n-1;
        while(l <= r){
            int m = (l + r) / 2;

            if(j[m].st <= t){
                l = m + 1;
            } else {
                pos = m;
                r = m - 1;
            }
        }
        cout << pos << endl;
        // pos in next task
        int prev = pos - 1;
        // handle if prev = -1;

        int pst = j[prev].st;
        int pen = j[prev].en;

        int time;
        if(pst <= t and pen >= t){
            // free time is fixed.
        } else {
            // free time will be prev + new
        }
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