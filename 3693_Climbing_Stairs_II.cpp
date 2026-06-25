/*
 * LeetCode 3693. Climbing Stairs II
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = costs[0] + 1;

        for (int i = 2; i <= n; i++) {

            if(i == 2)
                dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 4) + costs[i - 1];
            else
                dp[i] = min(min(dp[i - 1] + 1, dp[i - 2] + 4), dp[i - 3] + 9) + costs[i - 1];
        }

        return dp[n];
    }
};
