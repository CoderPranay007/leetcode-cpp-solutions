/*
 * LeetCode 213. House Robber II
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:

    int solve(vector<int>& nums, int s, int e) {
        int l = e - s + 1;

        vector<int> dp(l + 1, 0);

        dp[1] = nums[s];
        int mx = nums[s];

        for (int i = 2; i <= l; i++) {

            if (i == 2) {
                dp[i] = nums[s + 1];
                mx = max(nums[s], nums[s + 1]);
            }
            else if (i == 3) {
                dp[i] = dp[1] + nums[s + 2];
            }
            else {
                dp[i] = mx + nums[s + i - 1];
                mx = max(mx, dp[i - 1]);
            }
        }

        return max(dp[l], dp[l - 1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(solve(nums, 0, n - 2),
                   solve(nums, 1, n - 1));
    }
};
