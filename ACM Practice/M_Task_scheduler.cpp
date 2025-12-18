#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Task {
  int id, priority, time;
  Task() {};
  bool operator<(const Task &other) const {
    if(priority == other.priority) return time < other.time;
    return priority < other.priority;
  }
};

void solve(){

  int n; cin >> n;
  vector<Task> t(n);
  for(int i=0;i<n;i++){
    int x; cin >> x;
    t[i].id = x;
    t[i].time = i;
  }
  for(int i=0;i<n;i++){
    int p; cin >> p;
    t[i].priority = p;
  }
  sort(t.begin(), t.end());
  for(int i=0;i<n;i++){
    cout << t[i].id << " ";
  }
  cout << endl;

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