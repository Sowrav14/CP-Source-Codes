#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
int n,p,d;
vector<pii>ini;

int calculate(vector<pii>arr){
    int sz = arr.size();
    if(sz == 0) return 0;
    int ret = 0;
    int pen = 0, pro = 0;
    for(int i=0;i<sz;i++){
        int x = arr[i].first;
        int w = arr[i].second;

        pro += w;
        if(x <= p){
            int time = p - x;
            if(time > d){
                pen += time - d;
            }
        } else{
            int time = p + x - 2 * arr[0].first;
            if(time > d){
                pen += time - d;
            }
        }
    }

    ret = pro - pen;
    pen = 0, pro = 0;
    for(int i=0;i<sz;i++){
        int x = arr[i].first;
        int w = arr[i].second;

        pro += w;
        if(x >= p){
            int time = x - p;
            if(time > d){
                pen += time - d;
            }
        } else{
            int time = 2 * arr.back().first - p - x;
            if(time > d){
                pen += time - d;
            }
        }
    }

    cout << pro << " " << pen << endl;
    ret = max(ret, pro - pen);
    return ret;

}



int generate(int i, vector<pii>&ss){
    if(i == n){
        return calculate(ss);
    }
    int ans = 0;
    ss.push_back(ini[i]);
    ans = max(ans, generate(i+1, ss));
    ss.pop_back();
    ans = max(ans, generate(i+1, ss));
    return ans;
}



void solve(){

    cin >> n >> p >> d;
    ini.resize(n);
    for(int i=0;i<n;i++) cin >> ini[i].first;
    for(int i=0;i<n;i++) cin >> ini[i].second;
    vector<pii>v;
    // cout << generate(0, v) << endl;
    cout << calculate(ini) << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}