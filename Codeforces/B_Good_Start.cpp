#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long w, h, a, b, x1, y1, x2, y2;
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Check if both sheets can be on the same grid
        if ((x2 - x1) % a != 0 || (y2 - y1) % b != 0) {
            cout << "No\n";
            continue;
        }
        
        // Calculate grid offset using sheet 1's position
        // Handle negative modulo correctly
        long long dx = ((x1 % a) + a) % a;
        long long dy = ((y1 % b) + b) % b;
        
        // Verify sheet 2 aligns with same grid
        long long dx2 = ((x2 % a) + a) % a;
        long long dy2 = ((y2 % b) + b) % b;
        
        if (dx != dx2 || dy != dy2) {
            cout << "No\n";
            continue;
        }
        
        // Check if grid can cover [0, w) in x-direction
        bool x_covered = false;
        
        // Find leftmost position that covers x = 0
        long long left_pos;
        if (dx == 0) {
            left_pos = 0;
        } else {
            // Need to go left by ceil(dx/a) steps
            long long steps = (dx + a - 1) / a;
            left_pos = dx - steps * a;
        }
        
        // Find rightmost position that covers x = w-1
        long long steps_right = (w - 1 - dx) / a;
        if (steps_right < 0) steps_right = -1;
        long long right_pos = dx + (steps_right + 1) * a;
        
        if (left_pos <= 0 && right_pos >= w) {
            x_covered = true;
        }
        
        // Check if grid can cover [0, h) in y-direction
        bool y_covered = false;
        
        // Find bottommost position that covers y = 0
        long long bottom_pos;
        if (dy == 0) {
            bottom_pos = 0;
        } else {
            // Need to go down by ceil(dy/b) steps
            long long steps = (dy + b - 1) / b;
            bottom_pos = dy - steps * b;
        }
        
        // Find topmost position that covers y = h-1
        long long steps_up = (h - 1 - dy) / b;
        if (steps_up < 0) steps_up = -1;
        long long top_pos = dy + (steps_up + 1) * b;
        
        if (bottom_pos <= 0 && top_pos >= h) {
            y_covered = true;
        }
        
        if (x_covered && y_covered) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}