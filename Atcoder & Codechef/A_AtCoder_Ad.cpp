#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Baseline guillotine packer for AHC001 A (AtCoder Ad).
- Places rectangles so each contains (x_i+0.5,y_i+0.5).
- Greedy: sort by requested area descending; place large ones first.
- Free rectangles are split into two (right and bottom) after placement.
- Fallback: if can't fit ideal size, place minimal rect containing the point (1x1 or small).
- This is a baseline; use local search / SA to improve areas and packing.
*/

struct Company {
    int x,y;
    long long r;
    int id;
};

struct FreeRect {
    int x,y; // top-left corner (inclusive)
    int w,h; // width (x dir), height (y dir)
};

int clip_int(int v, int lo, int hi){ if(v<lo) return lo; if(v>hi) return hi; return v; }

int fits_and_get_score(int sx,int sy,int w,int h,int xi,int yi,long long ri){
    // quick check: does rectangle [sx,sx+w) x [sy,sy+h) contain (xi+0.5, yi+0.5)
    // which is equivalent to xi in [sx, sx+w-1] and yi in [sy, sy+h-1]
    if(!(xi >= sx && xi <= sx + w - 1 && yi >= sy && yi <= sy + h - 1)) return -1;
    // compute integer area s = w*h
    long long s = 1LL*w*h;
    // score proxy: absolute relative difference; smaller is better
    long long a = min((long long)ri, s);
    long long b = max((long long)ri, s);
    // we return an integer proxy of how close it is: smaller is better
    // use squared relative difference numerator scaled to avoid floating
    // but for greedy selection a simpler metric: abs(s - r)
    return (int) llabs(s - ri);
}

signed main(){
    Fast_IO()
    int n;
    if(!(cin >> n)) return 0;
    vector<Company> comp(n);
    for(int i=0;i<n;i++){
        long long xi, yi, ri;
        cin >> xi >> yi >> ri;
        comp[i].x = (int)xi;
        comp[i].y = (int)yi;
        comp[i].r = ri;
        comp[i].id = i;
    }

    // Sort indices by requested area descending
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a,int b){
        return comp[a].r > comp[b].r;
    });

    // initial free rect: full canvas [0,0,10000,10000)
    vector<FreeRect> freeRects;
    freeRects.push_back({0,0,10000,10000});

    // output rectangles (in original order)
    vector<array<int,4>> ans(n, {0,0,1,1});

    // helper to remove free rect at index i fast
    auto remove_free = [&](int idx){
        freeRects[idx] = freeRects.back();
        freeRects.pop_back();
    };

    // For each company in descending area order, try to place a rectangle
    for(int idx=0; idx<n; ++idx){
        int ci = order[idx];
        Company &C = comp[ci];
        long long want = C.r;

        bool placed = false;
        int bestFree = -1;
        int best_w=1, best_h=1, best_sx=0, best_sy=0;
        long long best_metric = (long long)9e18;

        // Try each free rectangle to find a good fit
        for(int fi=0; fi < (int)freeRects.size(); ++fi){
            FreeRect &F = freeRects[fi];
            // The placed rectangle must contain the integer point (x,y) (i.e. xi in [sx, sx+w-1])
            // So the placement top-left sx can be at most xi and at least F.x
            // and sx+w must be <= F.x + F.w
            // We'll try to choose width w to be as close to want as possible but bounded by F.w and F.h
            // Try a few candidate widths around sqrt(want) and also widths that exactly fit horizontally
            int maxW = F.w;
            int maxH = F.h;
            if(maxW <= 0 || maxH <= 0) continue;

            // Candidate widths: clamp sqrt, divisors not feasible; try set of heuristics
            vector<int> candW;
            int sq = max(1ll, (int)floor(sqrt((double)want)));
            for(int dw = -3; dw <= 3; ++dw){
                int w = sq + dw;
                if(w <= 0) continue;
                if(w > maxW) w = maxW;
                candW.push_back(w);
            }
            candW.push_back(maxW);
            // also try width equal to width that allows height <= maxH
            int w_from_h = (int)max(1LL, (want + maxH - 1) / maxH);
            if(w_from_h <= maxW) candW.push_back(w_from_h);
            // dedup
            sort(candW.begin(), candW.end());
            candW.erase(unique(candW.begin(), candW.end()), candW.end());

            for(int w : candW){
                int h = (int)((want + w - 1) / w);
                if(h <= 0) h = 1;
                if(h > maxH) continue; // can't fit in this free rect with this width
                // now pick position (sx,sy) such that rectangle fits into F and contains the point (x,y)
                int xi = C.x, yi = C.y;
                // allowed top-left ranges:
                int sx_min = F.x;
                int sx_max = F.x + F.w - w;
                int sy_min = F.y;
                int sy_max = F.y + F.h - h;
                if(sx_min > sx_max || sy_min > sy_max) continue;
                // must have xi in [sx, sx+w-1] => sx in [xi - (w-1), xi]
                int sx_lo = max(sx_min, xi - (w - 1));
                int sx_hi = min(sx_max, xi);
                int sy_lo = max(sy_min, yi - (h - 1));
                int sy_hi = min(sy_max, yi);
                if(sx_lo > sx_hi || sy_lo > sy_hi) continue; // cannot contain point
                // pick a placement which is near top-left of free rect but within allowable range
                int sx = clip_int(xi - (w/2), sx_lo, sx_hi);
                int sy = clip_int(yi - (h/2), sy_lo, sy_hi);
                // metric: absolute area difference
                long long metric = llabs(1LL*w*h - want);
                if(metric < best_metric){
                    best_metric = metric;
                    bestFree = fi;
                    best_w = w; best_h = h; best_sx = sx; best_sy = sy;
                    placed = true;
                }
            }
        } // end scanning free rects

        if(!placed){
            // Fallback: place minimal containing rectangle centered at the point and 1x1 (or small)
            int sx = clip_int(C.x, 0, 9999);
            int sy = clip_int(C.y, 0, 9999);
            int w = 1, h = 1;
            // try to find any free rect containing (sx,sy)
            bool foundF = false;
            for(int fi=0; fi < (int)freeRects.size(); ++fi){
                FreeRect &F = freeRects[fi];
                if(sx >= F.x && sx <= F.x + F.w - 1 && sy >= F.y && sy <= F.y + F.h - 1){
                    bestFree = fi;
                    best_w = 1; best_h = 1; best_sx = sx; best_sy = sy;
                    foundF = true;
                    break;
                }
            }
            if(!foundF){
                // If still not found, forcibly place at (0,0) 1x1 and skip splitting (rare)
                bestFree = -1;
                ans[ci] = {0,0,1,1};
                continue;
            }
        }

        // Commit placement
        int place_x = best_sx, place_y = best_sy, place_w = best_w, place_h = best_h;
        // Ensure coordinates within canvas
        if(place_x < 0) place_x = 0;
        if(place_y < 0) place_y = 0;
        if(place_x + place_w > 10000) place_w = 10000 - place_x;
        if(place_y + place_h > 10000) place_h = 10000 - place_y;
        ans[ci] = {place_x, place_y, place_x + place_w, place_y + place_h};

        if(bestFree != -1){
            // Remove freeRects[bestFree] and add split pieces
            FreeRect F = freeRects[bestFree];
            // The placed area is inside F (by construction)
            // Create right rect (to the right of placed) and bottom rect (below placed)
            // Right rect: x = place_x + place_w, y = F.y, w = F.x + F.w - (place_x + place_w), h = F.h
            int rx = place_x + place_w;
            int ry = F.y;
            int rw = (F.x + F.w) - (place_x + place_w);
            int rh = F.h;
            if(rw > 0 && rh > 0){
                freeRects.push_back({rx, ry, rw, rh});
            }
            // Bottom rect: x = F.x, y = place_y + place_h, w = F.w, h = (F.y + F.h) - (place_y + place_h)
            int bx = F.x;
            int by = place_y + place_h;
            int bw = F.w;
            int bh = (F.y + F.h) - (place_y + place_h);
            if(bw > 0 && bh > 0){
                freeRects.push_back({bx, by, bw, bh});
            }
            // Additionally, if the placement leaves a left-top gap inside F (when placement isn't aligned), create it
            // Left-top gap (between F.x..place_x-1 horizontally and F.y..place_y-1 vertically)
            int lx = F.x;
            int ly = F.y;
            int lw = place_x - F.x;
            int lh = place_y - F.y;
            if(lw > 0 && lh > 0){
                freeRects.push_back({lx, ly, lw, lh});
            }
            // Right-top small area (to the right of placed on top)
            int rtx = place_x + place_w;
            int rty = F.y;
            int rtw = (F.x + F.w) - (place_x + place_w);
            int rth = place_y - F.y;
            if(rtw > 0 && rth > 0){
                freeRects.push_back({rtx, rty, rtw, rth});
            }
            // Bottom-left area
            int blx = F.x;
            int bly = place_y + place_h;
            int blw = place_x - F.x;
            int blh = (F.y + F.h) - (place_y + place_h);
            if(blw > 0 && blh > 0){
                freeRects.push_back({blx, bly, blw, blh});
            }

            // Remove the used free rect
            remove_free(bestFree);

            // Optional: coalesce free rects (not implemented here) to reduce fragmentation
        }
    } // placed all companies

    // Output answers in original order
    for(int i=0;i<n;i++){
        auto &r = ans[i];
        // ensure validity: if something invalid, clamp
        int a=r[0], b=r[1], c=r[2], d=r[3];
        if(a<0) a=0; if(b<0) b=0; if(c>a){} else c = min(a+1,10000ll);
        if(d>b){} else d = min(b+1,10000ll);
        if(c>10000){ c=10000; if(a>=c) a = c-1; }
        if(d>10000){ d=10000; if(b>=d) b = d-1; }
        cout << a << " " << b << " " << c << " " << d << "\n";
    }

    return 0;
}
