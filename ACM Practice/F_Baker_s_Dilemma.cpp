#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Job {
  int id, penalty, day;
  Job(){}
  Job(int id, int penalty, int day) : id(id), penalty(penalty), day(day) {}
  
  bool operator<(const Job &other) const {
    if(penalty*other.day == other.penalty*day) {
      return id < other.id;
    }
    return penalty*other.day > other.penalty*day;
  }
};


void solve(){

  int n; cin >> n;
  vector<Job> jobs(n);
  for(int i=1;i<=n;i++){
    int d, p; cin >> d >> p;
    jobs[i-1] = Job(i, p, d);
  }
  sort(jobs.begin(), jobs.end());
  for(auto job : jobs){
    cout << job.id << " ";
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