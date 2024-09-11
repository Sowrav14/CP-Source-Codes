/**
 * @file Counting_Coprime_Pairs.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-09-11
 * @copyright Copyright (c) 2024
 * @problem: https://cses.fi/problemset/task/2417
 * @approach: https://codeforces.com/blog/entry/82103#:~:text=We%20will%20be,coprime3%2Deditorial/6051
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int spf[N], mobius[N];

void smallest_prime_factor(){
    for(int i=2;i<N;i++){
        if(!spf[i]){
            for(int j=i;j<N;j+=i){
                if(!spf[j]) spf[j]=i;
            }
        }
    }
}

void Mobius(){
    for(int i=1;i<1000001;i++) {
        if(i==1){
            mobius[i]=1;
        } else {
            if(spf[i/spf[i]] == spf[i]) mobius[i]=0;
            else mobius[i] = -1 * mobius[i/spf[i]];
        }
    }
}

int cnt[N];

void solve(){

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for(int i=1;i<N;i++){
        if(mobius[i] == 0) continue;
        int d = 0;
        for(int j=i;j<N;j+=i){
            d += cnt[j];
        }
        ans += (d * (d-1)) / 2 * mobius[i];
    }
    cout << ans << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    smallest_prime_factor();
    Mobius();
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}