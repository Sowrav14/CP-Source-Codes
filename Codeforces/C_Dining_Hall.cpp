#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Cell {
    int x, y;
};

struct Table {
    int x, y;
    vector<Cell> cells;
    int occupied;

    Table(int x, int y) : x(x), y(y), occupied(0) {
        cells.push_back({3 * x + 1, 3 * y + 1});
        cells.push_back({3 * x + 1, 3 * y + 2});
        cells.push_back({3 * x + 2, 3 * y + 1});
        cells.push_back({3 * x + 2, 3 * y + 2});
    }

    bool operator<(const Table& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int manhattanDistance(Cell a, Cell b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    set<Table> availableTables;
    priority_queue<pair<int, Cell>, vector<pair<int, Cell>>, greater<pair<int, Cell>>> availableChairs;
    vector<pair<int, int>> result(n);
    vector<Table> tables;

    for (int i = 0; i < n; ++i) {
        if (t[i] == 1) {
            if (availableTables.empty()) {
                int next_table_x = 0;
                int next_table_y = 0;
                if (!tables.empty()) {
                    next_table_x = tables.back().x + 1;
                    next_table_y = tables.back().y;
                    if (next_table_x * 3 + 1 > next_table_y * 3 + 1) {
                        next_table_x = tables.back().x;
                        next_table_y = tables.back().y + 1;
                    }
                }
                tables.emplace_back(next_table_x, next_table_y);
                availableTables.insert(tables.back());
            }

            auto it = availableTables.begin();
            Table table = *it;
            availableTables.erase(it);
            result[i] = {table.cells[table.occupied].x, table.cells[table.occupied].y};
            table.occupied++;
            for (int j = table.occupied; j < 4; ++j) {
                availableChairs.push({manhattanDistance({0, 0}, table.cells[j]), table.cells[j]});
            }
            if (table.occupied < 4) {
                availableTables.insert(table);
            }
        } else {
            if (!availableChairs.empty()) {
                Cell chair = availableChairs.top().second;
                availableChairs.pop();
                result[i] = {chair.x, chair.y};
            } else {
                int next_table_x = 0;
                int next_table_y = 0;
                if (!tables.empty()) {
                    next_table_x = tables.back().x + 1;
                    next_table_y = tables.back().y;
                    if (next_table_x * 3 + 1 > next_table_y * 3 + 1) {
                        next_table_x = tables.back().x;
                        next_table_y = tables.back().y + 1;
                    }
                }
                tables.emplace_back(next_table_x, next_table_y);
                availableTables.insert(tables.back());

                auto it = availableTables.begin();
                Table table = *it;
                availableTables.erase(it);
                result[i] = {table.cells[table.occupied].x, table.cells[table.occupied].y};
                table.occupied++;
                for (int j = table.occupied; j < 4; ++j) {
                    availableChairs.push({manhattanDistance({0, 0}, table.cells[j]), table.cells[j]});
                }
                if (table.occupied < 4) {
                    availableTables.insert(table);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i].first << " " << result[i].second << endl;
    }
}

signed main() {
    Fast_IO()
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}