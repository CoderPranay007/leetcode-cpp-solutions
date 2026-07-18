/*
 * LeetCode 39. Combination Sum
 * Difficulty: Medium
 * Topics: Array, Backtracking
 *
 * Time Complexity: O(2^target) (approximately)
 * Space Complexity: O(target)
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

        if (target < 0 || index == arr.size()) {
            return;
        }

        // Include the current element.
        curr.push_back(arr[index]);
        solve(arr, curr, ans, index, target - arr[index]);

        // Exclude the current element.
        curr.pop_back();
        solve(arr, curr, ans, index + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> current;
        vector<vector<int>> answer;

        solve(candidates, current, answer, 0, target);

        return answer;
    }
};
