/*
 * LeetCode 2919. Minimum Increment Operations to Make Array Beautiful
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> dp(n);

        dp[0] = max(0, k - nums[0]);
        dp[1] = max(0, k - nums[1]);
        dp[2] = max(0, k - nums[2]);

        for(int i = 3; i < n; i++) {
            long long a = min({dp[i - 1], dp[i - 2], dp[i - 3]});
            dp[i] = max(0LL, 1LL * k - nums[i]) + a;
        }

        return min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
    }
};
