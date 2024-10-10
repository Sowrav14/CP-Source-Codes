#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Tasks{
    int a;      // arrival
    int d;      // departure
    int idx;    // given order
    int r;      // allocated room

    Tasks() {}
    Tasks(int a, int d, int idx) : a(a), d(d), idx(idx), r(0) {}

};


void solve(){

    int n; cin >> n;
    vector<Tasks>tasks;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        tasks.push_back(Tasks(x, y, i));
    }
    sort(tasks.begin(), tasks.end(), [](Tasks a, Tasks b){
        if(a.a != b.a) return a.a < b.a;
        return a.d <= b.d;
    });
    // for(auto i : tasks){
    //     cout << i.a << " " << i.d << " " << i.idx << " " << i.r << endl;
    // }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0, 1});
    for(auto &i : tasks){
        int min_d = pq.top().first;
        if(min_d < i.a){
            i.r = pq.top().second;
            pq.pop();
            pq.push({i.d, i.r});
        } else{
            i.r = pq.size() + 1;
            pq.push({i.d, i.r});
        }
    } 

    cout << pq.size() << endl;
    sort(tasks.begin(), tasks.end(), [](Tasks a, Tasks b){
        return a.idx < b.idx;
    });
    for(auto i : tasks){
        cout << i.r << " ";
    }
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