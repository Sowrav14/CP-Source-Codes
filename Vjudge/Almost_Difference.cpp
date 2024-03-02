#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
int n;
int a[N];
map<int,int>m;
int bito[N], bitv[N];

// updating a single value in bit
void update_sum(int idx, int val){
    while(idx <= n){
        bitv[idx] += val;
        idx += (idx) & (-idx);
    }
}

// return sum of (1 - idx)
int query_for_sum(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bitv[idx];
        idx -= (idx) & (-idx);
    }
    return ret;
}


// updating a single value in bit
void update_occurence(int idx, int val){
    while(idx <= n){
        bito[idx] += val;
        idx += (idx) & (-idx);
    }
}

// return sum of (1 - idx)
int query_for_occurence(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bito[idx];
        idx -= (idx) & (-idx);
    }
    return ret;
}


void solve(){

    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        a[i] = v[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();i++){
        m[v[i]] = i + 1;
    }

    // for(auto i : m){
    //     cout << i.first << " " << i.second << endl;
    // }

    unsigned long long add = 0, sub = 0;
    for(int i=0;i<n;i++){
        // current value and mapped with value.
        int cv = a[i];
        int mw = m[cv];
        

        // calculate left, right
        int left, right;
        if(m[cv-1]){
            left = m[cv-1];
        } else {
            left = m[cv];
        }

        if(m[cv+1]){
            right = m[cv+1];
        } else{
            right = m[cv];
        }

        // answer for left portion.
        int sum = query_for_sum(left-1);
        int occ = query_for_occurence(left-1);
        unsigned long long one = (cv * occ - sum);

        // answer for right portion.
        sum = query_for_sum(n) - query_for_sum(right);
        occ = query_for_occurence(n) - query_for_occurence(right);
        unsigned long long two = (sum - cv * occ);

        update_occurence(mw, 1);
        update_sum(mw, a[i]);

        // cout << one << " " << two << endl;
        add += one;
        sub += two;
        // // cout << res << endl;
        // int res = one - two;
        // // cout << res << endl;
        // ans = ans + res;
    }
    // cout << add << " " << sub << endl;
    if(add >= sub){
        cout << add - sub << endl;
    } else {
        cout << "-" << sub - add << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}