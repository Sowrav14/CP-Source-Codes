#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int ini_seg[4040][4040] = {0};    // initial segment tree.
int fin_seg[4040][4040] = {0};    // final segment tree.
int grid[1040][1040];             // given 2D grid.
int size;                         // size of x coordinate.

/* 
* A recursive function that constructs Initial Segment Tree for array grid[][] = { }. 
* 'pos' is index of current node in segment tree seg[].
* 'strip' is the enumeration for the y-axis. 
* Call it with segment(0, n-1, 1, strip) for every strip in range(0, n-1)
*/
void segment(int low, int high, int pos, int strip) { 
    if (high == low) { 
        ini_seg[strip][pos] = grid[strip][low]; 
    } 
    else { 
        int mid = (low + high) / 2; 
        segment(low, mid, 2 * pos, strip); 
        segment(mid + 1, high, 2 * pos + 1, strip); 
        ini_seg[strip][pos] = ini_seg[strip][2 * pos] + ini_seg[strip][2 * pos + 1]; 
    } 
} 

/* 
* A recursive function that constructs Final Segment Tree for array ini_seg[][] = { }.
* Call it with finalSegment(0, n-1, 1) once.
*/
void finalSegment(int low, int high, int pos) { 
    if (high == low) { 
        for (int i = 1; i < 2 * size; i++) fin_seg[pos][i] = ini_seg[low][i];
    } 
    else { 
        int mid = (low + high) / 2; 
        finalSegment(low, mid, 2 * pos); 
        finalSegment(mid + 1, high, 2 * pos + 1); 
        for (int i = 1; i < 2 * size; i++)
            fin_seg[pos][i] = fin_seg[2 * pos][i] + fin_seg[2 * pos + 1][i];
    } 
} 

/* 
* Return sum of elements in range from index x1 to x2 .
* It uses the final_seg[][] array created using finalsegment() function. 
* 'pos' is index of current node in segment tree fin_seg[][]. 
* Don't call it for query it will be called by Query().
*/
int finalQuery(int pos, int start, int end, int x1, int x2, int node) { 
    if (x2 < start || end < x1) return 0;
    if (x1 <= start && end <= x2) return fin_seg[node][pos];

    int mid = (start + end) / 2; 
    int p1 = finalQuery(2 * pos, start, mid, x1, x2, node); 
    int p2 = finalQuery(2 * pos + 1, mid + 1, end, x1, x2, node); 

    return (p1 + p2); 
} 

/* 
* This function calls the finalQuery function for elements in range from index x1 to x2 . 
* This function queries the yth coordinate.
* Call it with query(1, 1, n, y1, y2, x1, x2) to get sum between grid[x1][y1] -> grid[x2][y2] 
*/
int query(int pos, int start, int end, int y1, int y2, int x1, int x2) { 
    if (y2 < start || end < y1) return 0;
    if (y1 <= start && end <= y2) return (finalQuery(1, 1, size, x1, x2, pos));

    int mid = (start + end) / 2; 
    int p1 = query(2 * pos, start, mid, y1, y2, x1, x2); 
    int p2 = query(2 * pos + 1, mid + 1, end, y1, y2, x1, x2); 

    return (p1 + p2); 
} 

/* 
* A recursive function to update the nodes which for the given index.
* The following are parameters : 
*     pos --> index of current node in segment tree fin_seg[][].
*     x -> index of the element to be updated.
*     val --> Value to be change at node idx.
* No need to call it query will call it.
*/
void finalUpdate(int pos, int low, int high, int x, int val, int node) { 
    if (low == high) { 
        fin_seg[node][pos] = val; 
    } 
    else { 
        int mid = (low + high) / 2; 
        if (low <= x && x <= mid) { 
            finalUpdate(2 * pos, low, mid, x, val, node); 
        } 
        else { 
            finalUpdate(2 * pos + 1, mid + 1, high, x, val, node); 
        } 
        fin_seg[node][pos] = fin_seg[node][2 * pos] + fin_seg[node][2 * pos + 1]; 
    } 
} 

/* 
* This function call the final update function after visiting the yth coordinate in the segment tree fin_seg[][].
* Call it with update(1, 1, n, x, y, value) to update grid[x][y] with value. 
*/
void update(int pos, int low, int high, int x, int y, int val) { 
    if (low == high) { 
        finalUpdate(1, 1, size, x, val, pos); 
    } 
    else { 
        int mid = (low + high) / 2; 
        if (low <= y && y <= mid) { 
            update(2 * pos, low, mid, x, y, val); 
        } 
        else { 
            update(2 * pos + 1, mid + 1, high, x, y, val); 
        } 
        for (int i = 1; i < 2 * size; i++) 
            fin_seg[pos][i] = fin_seg[2 * pos][i] + fin_seg[2 * pos + 1][i]; 
    } 
} 

void solve() {
    int n, q; cin >> n >> q;
    size = n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch; cin >> ch;
            grid[i][j] = (ch == '*' ? 1 : 0);
        }
    }

    // Initializing segment tree.
    for (int strip = 0; strip < n; strip++) segment(0, n-1, 1, strip); 
    finalSegment(0, n-1, 1);

    while(q--) {
        int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        cout << query(1, 1, n, y1, y2, x1, x2) << endl;
    }
}

signed main() {
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "Case " << t << ": ";
        solve();
    }
}
