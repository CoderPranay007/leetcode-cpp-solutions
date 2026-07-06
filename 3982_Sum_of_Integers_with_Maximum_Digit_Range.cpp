/*
 * LeetCode 3982. Sum of Integers with Maximum Digit Range
 * Difficulty: Easy
 * Topics: Array, Math
 *
 * Time Complexity: O(n × d)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int max_range = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {

            int n = nums[i];
            int s = 10, l = 0, range = 0;

            while(n > 0) {
                int digit = n % 10;

                if(digit > l) l = digit;
                if(digit < s) s = digit;

                n /= 10;
            }

            range = l - s;

            if(range > max_range) {
                max_range = range;
                sum = nums[i];
            }
            else if(range == max_range) {
                sum += nums[i];
            }
        }

        return sum;
    }
};
