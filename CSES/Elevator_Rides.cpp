//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
//EndCodeSnip

int main() {
	int people, max_weight;
	cin >> people >> max_weight;
	vector<int> weight(people);
	for (int &i : weight) cin >> i;

	vector<pair<int, int>> dp(1 << people, {people + 1, max_weight + 1});
	dp[0] = make_pair(1, 0);
	/*
	 * Loop through all bitmasks.
	 * The bitmasks represent whether each person has used the elevator or not.
	 * If the ith bit is set, this means the ith person has used the elevator.
	 */
	for (int mask = 1; mask < (1 << people); mask++) {
		for (int i = 0; i < people; i++)
			// The ith person has used the elevator.
			if (mask & (1 << i)) {
				auto prev = dp[mask ^ (1 << i)];
				int num_rides = prev.first;
				int total_weight = prev.second;
				// We need to use a new ride.
				if (total_weight + weight[i] <= max_weight) total_weight += weight[i];
				else {
					// Add the weight of the ith person to the current ride.
					num_rides++;
					total_weight = weight[i];
				}
				// Update if it is better than the original.
				dp[mask] = min(dp[mask], make_pair(num_rides, total_weight));
			}
	}
	// Result when all people have used the elevator.
	cout << dp[(1 << people) - 1].first;
}