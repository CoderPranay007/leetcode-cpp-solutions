/*
 * LeetCode 3987. Minimum Total Cost to Process All Elements
 * Difficulty: Medium
 * Topics: Array, Math, Greedy
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long avl = k;
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (avl < nums[i]) {
                count += (nums[i] - avl + k - 1) / k;

                avl = ((avl - nums[i]) % k + k) % k;
            } 
            else {
                avl -= nums[i];
            }
        }

        const long long MOD = 1000000007;

        long long a = count % MOD;
        long long b = (count + 1) % MOD;

        if (a % 2 == 0)
            a /= 2;
        else
            b /= 2;

        long long ans = (a * b) % MOD;

        return (int)ans;
    }
};
