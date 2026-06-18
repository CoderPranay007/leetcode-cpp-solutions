/*
 * LeetCode 3952. Maximum Total Value of Covered Indices
 * Difficulty: Medium
 * Topics: String, Array, Dp, Greedy
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = s.size();
        long long sum = 0;

        if (s[0] == '1') sum += nums[0];

        int i = 1;

        while (i < n) {
            if (s[i] == '1' && s[i - 1] == '1') {
                sum += nums[i];
                i++;
            }
            else if (s[i] == '1') {
                int start = i - 1;
                sum += nums[i-1];
                
                while (i < n && s[i] == '1') {
                    sum += nums[i];
                    i++;
                }

                int end = i - 1;

                sum -= *min_element(nums.begin() + start, nums.begin() + end + 1);
            }
            else {
                i++;
            }
        }

        return sum;
    }
};
