/**
 * @file Kim_and_Refrigerators.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-17
 * @copyright Copyright (c) 2025
 * @problem:https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators/problem
 * @tag: recursion, backtracking, travelling salesman problem
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<pair<int,int>> customer;
pair<int,int> office, home;

int dist(int i, int j){
    int ret = 0;
    ret += abs(customer[i].first - customer[j].first);
    ret += abs(customer[i].second - customer[j].second);
    return ret;
}

int all;
int tsp(int i, int mask){
    // cout << i << " " << mask << " " << all << endl;
    if(mask == all) return abs(customer[i].first - home.first) + abs(customer[i].second - home.second); 
    int ans = inf;
    // cout << n << endl;
    for(int j=0;j<n;j++){
        if((mask & (1 << j)) == 0){
            int nmask = mask | (1 << j);
            ans = min(ans, dist(i, j) + tsp(j, nmask));
        }
    }
    return ans;
}

void solve(){

    cin >> n;
    customer.clear();
    customer.resize(n);
    cin >> office.first >> office.second;
    cin >> home.first >> home.second;
    for(int i=0;i<n;i++){
        cin >> customer[i].first >> customer[i].second;
    }
    all = (1 << n) - 1;
    int ans = inf;
    for(int i=0;i<n;i++){
        int mask = (1 << i);
        int cost = abs(customer[i].first - office.first) + abs(customer[i].second - office.second);
        ans = min(ans, cost + tsp(i, mask));
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 10;
    // cin >> t;
    for(int i=1;i<=t;i++){
        cout << "# " << i << " ";
        solve();
    }
}