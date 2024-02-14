/**
 * @file Interval_removal.cpp
 * @author Sowrav Nath
 * @brief 
 * @version 0.1
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 *  Problem : 
 *  In an array when we get two distinct number in adjacent we can remove them.
 *  The resultant size of the array after operations in required..
 *  So, the logic is to find the majority element of greater than n/2 occurance.
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int blk = sqrt(N) + 1;   // block size and total block will be sqrt(N)

class query{

    public :
         int l,r,k,id,block;                // each query belongs to a block
         query() {}
         query(int l, int r, int k, int id){
            this->l = l;
            this->r = r;
            this->k = k;
            this->id = id;
            this->block = l/blk;            // block number will be l/blk
         }

         bool operator < (query cq){        // sort according to block then r
            if(block != cq.block) return block < cq.block;
            else return r < cq.r;
         }

};



int a[N],res[M], range[M];
query qu[M];
int freq[N], counter[N];         // count frequency of values..
                                 // count which frequency occurs how many times.. 

void solve(){
    int n, q; cin >> n >> q;
    vector<int>v;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }


    for(int i=1;i<=q;i++){
        int l, r, k; cin >> l >> r >> k;
        qu[i] = query(l, r, k, i);
        range[i] = (r - l + 1);           // range will be (r - l + 1) if all same
    }

    sort(qu+1, qu+q+1);
    int prevl = 1, prevr = 0;             // keep trace of previous segment
    int prev_ans = 0;

    for(int i=1;i<=q;i++){
        int curl = qu[i].l;
        int curr = qu[i].r;
        int curk = qu[i].k;
        int idx = qu[i].id;

        while(curl < prevl){            // adding extra from left
            --prevl;
            int val = a[prevl];
            int c = freq[val];          // frequency of adding element. 2
            counter[c]--;               // this freq_counter will go up 5(2)->4(2)
            freq[val]++;                // new frequncy of adding element 3
            counter[freq[val]]++;       // freq_counter of this element updated.3(1)->3(2)
            prev_ans = max(prev_ans, freq[val]); // updated max frequency

        }
        while(prevr < curr){            // adding extra from right.
            ++prevr;
            int val = a[prevr];
            int c = freq[val];
            counter[c]--;
            freq[val]++;
            counter[freq[val]]++;
            prev_ans = max(prev_ans, freq[val]);
        }
        while(prevl < curl){            // removing extra from left.
            int val = a[prevl];         // freq. of removing element.
            int c = freq[val];          // counter of removing element freq.
            counter[c]--;               // counter will go down 1(3) -> 0(3)
            freq[val]--;                // freq. will decreased
            counter[freq[val]]++;       // update the counter for new freq. 1(2)->2(2)
            while(counter[prev_ans] == 0) prev_ans--; // max freq. element is removed c=0(f=3) -> c=2(f=2).
            prevl++;
        }
        while(prevr > curr){            // removing extra from right.
            int val = a[prevr];
            int c = freq[val];
            counter[c]--;
            freq[val]--;
            counter[freq[val]]++;
            while(counter[prev_ans] == 0) prev_ans--;
            prevr--;
        }

        res[idx] = (curk * prev_ans >= range[idx]);

    }

    for(int i=1;i<=q;i++){
        cout << (res[i] ? "YES" : "NO") << endl;
    }

}



signed main(){
    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
}