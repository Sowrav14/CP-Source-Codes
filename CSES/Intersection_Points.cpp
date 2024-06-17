/*
 * @file Line Sweep Algorithm.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-06-16
 * @copyr Copyr (c) 2024
 * @problem: Find intersection between lines.
 * @approach: Sweep Line Algorithms.
 * @explanation: https://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/
 */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// Ordered Set Tree
#define int long long int
#define ordered_set tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).
struct Point{ int x, y; };
struct Segment{ Point l, r; };

int n;
vector<Segment>lines;

struct Event{
    int x,y;
    int id;
    bool isLeft, isHor;

    Event(int x, int y, bool l, bool h, int i) : x(x), y(y), isLeft(l), isHor(h), id(i) {}

	// This is for sorting
	bool operator<(const Event& e) const {
        if(x != e.x) return x < e.x;
        else if(y != e.y) return y < e.y;
        else return id < e.id;
	}
};

int findIntersect(){
	
    vector<Event>ev;
    for(int i=0;i<n;i++){
        bool flag = (lines[i].l.y == lines[i].r.y);
        ev.push_back(Event(lines[i].l.x, lines[i].l.y, true, flag, i));
        ev.push_back(Event(lines[i].r.x, lines[i].r.y, false, flag, i));
    }
    sort(ev.begin(), ev.end());

    ordered_set ys;
    int intersect = 0;
    for(int i=0;i<2*n;i++){
        Event curr = ev[i];
        if(curr.isLeft and curr.isHor){
            // what happens if the point is in left of any horizontal segment.
            ys.insert(curr.y);
        } else if(curr.isLeft){
            // what happens if the point is in right of any vertical segment.
            continue;
        } else if(curr.isHor){
            // what happens if the point is in right of any horizontal segment.
            ys.erase(ys.find(curr.y));
        } else{
            // what happens if the point is in right of any vertical segment.
            int idx = curr.id;
            int left = lines[idx].l.y;
            int right = lines[idx].r.y;

            intersect += ys.order_of_key(right) - ys.order_of_key(left);
        }
    }

    return intersect;

}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++){
        Point p, q; cin >> p.x >> p.y >> q.x >> q.y;
        Segment s; s.l = p, s.r = q;
        lines.push_back(s);
    }

    cout << findIntersect() << endl;

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