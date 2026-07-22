/*
 * LeetCode 40. Combination Sum II
 * Difficulty: Medium
 * Topics: Array, Backtracking
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    void solve(vector<int>& arr,
               vector<int>& curr,
               vector<vector<int>>& ans,
               int index,
               int target) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < arr.size(); i++) {

            // Skip duplicate values at the same level.
            if (i > index && arr[i] == arr[i - 1])
                continue;

            // No need to continue if the current value exceeds the target.
            if (arr[i] > target)
                break;

            curr.push_back(arr[i]);

            solve(arr, curr, ans, i + 1, target - arr[i]);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> ans;

        solve(candidates, curr, ans, 0, target);

        return ans;
    }
};
