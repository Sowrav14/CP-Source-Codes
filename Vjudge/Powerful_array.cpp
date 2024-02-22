/*
 * @file Powerful_array.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-22
 * @copyright Copyright (c) 2024
 * @problem: 
 * @approach: MO algorithms.
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int N = 2*1e5+10;
const int M = 1e6+10;
int blk;
 
struct query{
        int p, l, r;
 
        bool operator < (query cq){
            if(l/blk != cq.l/blk) return l/blk < cq.l/blk;
            else return r > cq.r;
         }
};
 
int a[N], res[N];
int freq[M];
 
signed main(){
    int n,t; cin >> n >> t;
    blk = sqrt(n);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<query>q(t);
    for(int i=0;i<t;i++){
        int x,y; cin >> x >> y;
        q[i].l = x;
        q[i].r = y;
        q[i].p = i+1;
    }
 
    sort(q.begin(), q.end());
 
    int prevl = 0, prevr = 0;
    int ans = 0;
    for(int i=0;i<t;i++){
        int curl = q[i].l;
        int curr = q[i].r;
        int idx = q[i].p;

        // adding extra from right.
        while(prevr < curr){
            ++prevr;
            int val = a[prevr];
            int c = freq[val];
            int red = c * c * val;
            freq[val]++;
            int add = freq[val] * freq[val] * val;
            ans += add - red;
        }
        // adding extra from left.
        while(curl < prevl){
            --prevl;
            int val = a[prevl];
            int c = freq[val];
            int red = c * c * val;
            freq[val]++;
            int add = freq[val] * freq[val] * val;
            ans += add - red;
        }
        // removing extra from left.
        while(prevl < curl){
            int val = a[prevl];
            int c = freq[val];
            int red = c * c * val;
            freq[val]--;
            int add = freq[val] * freq[val] * val;
            ans += add - red;
            prevl++;
        }
        // removing extra from right.
        while(prevr > curr){
            int val = a[prevr];
            int c = freq[val];
            int red = c * c * val;
            freq[val]--;
            int add = freq[val] * freq[val] * val;
            ans += add - red;
            prevr--;
        }
 
        res[idx] = ans;
 
    }
 
    for(int i=1;i<=t;i++){
        cout << res[i] << endl;
    }

}