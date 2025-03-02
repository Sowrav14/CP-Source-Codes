#include <iostream>
#include <vector>

using namespace std;

// Helper function for backtracking
void generate(int index, vector<int>& nums, vector<vector<int>>& groups, vector<vector<vector<int>>>& result) {
    if (index == nums.size()) {
        result.push_back(groups);
        return;
    }

    // Add current number to an existing group
    for (auto& group : groups) {
        group.push_back(nums[index]);
        generate(index + 1, nums, groups, result);
        group.pop_back();
    }

    // Create a new group with the current number
    groups.push_back({nums[index]});
    generate(index + 1, nums, groups, result);
    groups.pop_back();
}

// Main function to generate all groupings
vector<vector<vector<int>>> getAllGroupings(vector<int>& nums) {
    vector<vector<vector<int>>> result;
    vector<vector<int>> groups;
    generate(0, nums, groups, result);
    return result;
}

// Driver function
int main() {
    vector<int> nums = {1, 2, 3, 4}; // Example input

    auto groupings = getAllGroupings(nums);

    // Print all groupings
    cout << "Total groupings: " << groupings.size() << endl;
    for (const auto& partition : groupings) {
        cout << "{ ";
        for (const auto& group : partition) {
            cout << "{";
            for (int num : group) cout << num << " ";
            cout << "} ";
        }
        cout << "}\n";
    }

    return 0;
}
