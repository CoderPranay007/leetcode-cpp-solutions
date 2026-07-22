/*
 * LeetCode 198. House Robber
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = nums[0];

        int mx = nums[0];

        for (int i = 2; i <= n; i++) {

            if (i == 2) {
                dp[i] = nums[1];
                mx = max(nums[0], nums[1]);
            }

            else if (i == 3) {
                dp[i] = dp[1] + nums[2];
            }

            else {
                dp[i] = mx + nums[i - 1];
                mx = max(mx, dp[i - 1]);
            }
        }

        return max(dp[n], dp[n - 1]);
    }
};
