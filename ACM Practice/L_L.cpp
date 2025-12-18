#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n; cin >> n;
  stack<pair<int,int>> s;
  stack<pair<int,int>> q;
  vector<char> vis(n+1, '.');
  for(int i=0;i<2*n;i++){
    int x; cin >> x;
    // cout << c << " " << x << endl;
    if(x > 0){
      s.push({x, i});
      vis[x] = '$';
    } else {
      x = -x;
      if(vis[x] == '$'){
        vector<pair<int,int>> temp;
        while(!s.empty()){
          int tp = s.top().first;
          int tm = s.top().second;
          s.pop();
          if(tp == x) {
            vis[x] = 'S';
            break;
          } else {
            temp.push_back({tp, tm});
            vis[tp] = '#';
          }
        }
        if(temp.size() != 0){
          if(q.empty()){
            for(int i=temp.size()-1;i>=0;i--){
              q.push(temp[i]);
            }
          } else {
            int tp = temp.back().second;
            int t2 = q.top().second;
            if(tp > t2){
              for(int i=temp.size()-1;i>=0;i--){
                q.push(temp[i]);
              }
            } else {
              stack<pair<int,int>> ts;
              for(int i=temp.size()-1;i>=0;i--){
                ts.push({temp[i].first, temp[i].second});
              }
              while(!q.empty()){
                ts.push(q.top());
                q.pop();
              }
            }
          }
        }
        
      } else if(vis[x] == '#'){
        if(q.empty() or q.top().first != x){
          cout << "*" << endl;
          // cout << "from queue check" << endl;
          return;
        } else {
          q.pop();
          vis[x] = 'G';
        }
      } else {
        cout << "*" << endl;
        return;
      }
    }
  }

  for(int i=1;i<=n;i++){
    if(vis[i] == '$') {
      cout << "*" << endl;
      return;
    }
  }
  for(int i=1;i<=n;i++){
    cout << vis[i];
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