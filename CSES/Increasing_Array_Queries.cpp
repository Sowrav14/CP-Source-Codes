#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, T val) { add(ind, val - arr[ind]); }

	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

int main() {
	int arr_size;
	int query_num;
	std::cin >> arr_size >> query_num;
	vector<int> arr(arr_size);
	for (int &i : arr) { std::cin >> i; }
	vector<vector<pair<int, int>>> queries(arr_size);
	for (int q = 0; q < query_num; q++) {
		int start, end;
		std::cin >> start >> end;
		queries[start - 1].push_back({end - 1, q});
	}

	vector<ll> pref_arr(arr_size + 1);
	for (int i = 0; i < arr_size; i++) { pref_arr[i + 1] = pref_arr[i] + arr[i]; }

	vector<ll> ans(query_num);
	vector<pair<int, int>> maxes;
	BIT<ll> contrib(arr_size);
	for (int i = arr_size - 1; i >= 0; i--) {
		while (!maxes.empty() && arr[i] >= maxes.back().first) {
			maxes.pop_back();
			contrib.set(maxes.size(), 0);
		}

		int len = (maxes.empty() ? arr_size : maxes.back().second) - i;
		contrib.set(maxes.size(), (ll)arr[i] * len);
		maxes.push_back({arr[i], i});

		for (const auto &[end, q] : queries[i]) {
			int lo = 0;
			int hi = maxes.size() - 1;
			int valid = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (maxes[mid].second <= end) {
					valid = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			ll sum1 = contrib.pref_sum(maxes.size() - 1) - contrib.pref_sum(valid);
			ll sum2 = (ll)(end - maxes[valid].second + 1) * maxes[valid].first;
			ll pref_sub = pref_arr[end + 1] - pref_arr[i];
			ans[q] = sum1 + sum2 - pref_sub;
		}
	}

	for (ll a : ans) { cout << a << '\n'; }
}