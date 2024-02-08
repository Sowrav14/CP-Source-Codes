/*
 * @file Chef_and_Queries.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-08
 * @copyright Copyright (c) 2024
 * @problem: https://www.codechef.com/problems/CHEFNUMK
 * @approach: MO's Algorithms. (TLE with BIT - O(n*sqrt(n)*log(n))).
 * @explanation:
 *              aro kisu test case dile maybe variable declare kora bad deya 
 *              lagto... tle er jonno ki dise era jane...
 */

#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
int blk = sqrt(N) + 10;

struct offline{
        int l,r,k,id;
        bool operator < (offline x){
            return make_pair(l/blk, r) < make_pair(x.l/blk, x.r);
        }
};





int a[N], ans[N];
int n,q;
// int bit[N];
int cnt[N], freq[N];

/*
void update(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += (idx) & (-idx);
    }
}

int get(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);
    }
    return ret;
}
*/



void solve(){

    cin >> n >> q;
    blk = sqrt(n);
    for(int i=1;i<=n;i++){
        // bit[i] = 0;
        cnt[i] = 0;
        freq[i] = 0;
    }
    vector<int>temp;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        temp.push_back(a[i]);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    // for(auto i : temp) cout << i << " "; cout << endl;
    // coordinate compression...
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    vector<offline>query(q);
    for(int i=0;i<q;i++){
        int l,r,k; cin >> query[i].l >> query[i].r >> query[i].k;
        query[i].id = i;
    }

    sort(query.begin(), query.end());

    int prevl = 0, prevr = 0;
    for(int i=0;i<q;i++){
        int curl = query[i].l;
        int curr = query[i].r;
        int k = query[i].k;
        int idx = query[i].id;


        // adding values in left.
        while(curl < prevl){
            prevl--;
            int el = a[prevl];
            // if(freq[el] > 0) update(freq[el], -1);
            freq[el]++;
            cnt[freq[el]]++;
            // if(freq[el] > 0) update(freq[el], 1);
        }
        // adding values in right.
        while(curr > prevr){
            prevr++;
            int el = a[prevr];
            // if(freq[el] > 0) update(freq[el], -1);
            freq[el]++;
            cnt[freq[el]]++;
            // if(freq[el] > 0) update(freq[el], 1);
        }
        // removing values from left.
        while(curl > prevl){
            int el = a[prevl];
            cnt[freq[el]]--;
            // if(freq[el] > 0) update(freq[el], -1);
            freq[el]--;
            // if(freq[el] > 0) update(freq[el], 1);
            prevl++;
        }
        // removing values from right.
        while(curr < prevr){
            int el = a[prevr];
            cnt[freq[el]]--;
            // if(freq[el] > 0) update(freq[el], -1);
            freq[el]--;
            // if(freq[el] > 0) update(freq[el], 1);
            prevr--;
        }
        ans[idx] = cnt[1] - cnt[k+1];
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << endl;
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