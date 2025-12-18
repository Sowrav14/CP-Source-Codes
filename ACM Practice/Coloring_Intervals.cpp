#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Interval {
  int start;
  int end;
  int id;
  Interval(int s, int e, int i) : start(s), end(e), id(i) {}
  Interval() {}

  bool operator<(const Interval& other) const {
    if(start != other.start) return start < other.start;
    return end < other.end;
  }
};

void solve(){

  int n; cin >> n;
  vector<Interval> v(n);
  for(int i=0;i<n;i++){
    int s, e; cin >> s >> e;
    v[i] = Interval(s, e, i + 1);
  }
  sort(v.begin(), v.end());
  vector<int> color(n + 1, 0);
  int c = 0;
  for(int i=0;i<n;i++){
    int l = v[i].start;
    int r = v[i].end;
    color[v[i].id] = c;
    c ^= 1;
    for(int j=i+1;j<n;j++){
      if(v[j].end <= r){
        color[v[j].id] = c;
        i = j;
      } else {
        break;
      }
    }
  }
  for(int i=1;i<=n;i++){
    cout << color[i];
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