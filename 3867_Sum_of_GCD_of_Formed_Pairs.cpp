/*
 * LeetCode 3867. Sum of GCD of Formed Pairs
 * Difficulty: Medium
 * Topics: Array, Math, Sorting
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

class Solution {
public:

    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixgcd(n);

        int mx = nums[0];
        prefixgcd[0] = nums[0];

        for (int i = 1; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixgcd[i] = gcd(nums[i], mx);
        }

        sort(prefixgcd.begin(), prefixgcd.end());

        long long sum = 0;

        for (int i = 0; i < n / 2; i++) {
            sum += gcd(prefixgcd[i], prefixgcd[n - 1 - i]);
        }

        return sum;
    }
};
