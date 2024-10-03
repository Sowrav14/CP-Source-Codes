#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Tasks{
    int st;
    int en;
    int du;

    Tasks(){}
    Tasks(int du, int en) : st(en-du), en(en), du(du) {}
};

void solve(){

    int n; cin >> n;
    vector<Tasks>tasks;
    for(int i=0;i<n;i++){
        int d, e; cin >> d >> e;
        tasks.push_back(Tasks(d, e));
    }
    sort(tasks.begin(), tasks.end(), [](Tasks a, Tasks b){
        if(a.du == b.du) return a.en > b.en;
        return a.du < b.du;
    });

    int last = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        // cout << last << " " << tasks[i].st << " " << tasks[i].en << " " << tasks[i].du << endl;
        last += tasks[i].du;
        ans += (tasks[i].en - last);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}