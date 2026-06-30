/*
 * LeetCode 45. Jump Game II
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming, Greedy
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int max = 0;
        int ans = 0;
        int end = 0;

        for(int i = 0; i < n - 1; i++) {
            max = max > (nums[i] + i) ? max : (nums[i] + i);

            if(i == end) {
                end = max;
                ans++;
            }

            if(end >= n - 1) break;
        }

        return ans;
    }
};
