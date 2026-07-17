/*
 * LeetCode 78. Subsets
 * Difficulty: Medium
 * Topics: Array, Backtracking, Bit Manipulation
 *
 * Time Complexity: O(n · 2^n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    void generate(vector<int>& arr,
                  vector<int>& curr,
                  vector<vector<int>>& ans,
                  int index)
    {
        if (index == arr.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(arr[index]);
        generate(arr, curr, ans, index + 1);

        curr.pop_back();
        generate(arr, curr, ans, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        generate(nums, current, ans, 0);

        return ans;
    }
};
