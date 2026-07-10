/*
 * LeetCode 3754. Concatenate Non-Zero Digits and Multiply by Sum I
 * Difficulty: Easy
 * Topics: Math
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long sumAndMultiply(int n) {

        long long product = 1;
        long long ans = 0;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                ans += digit * product;
                product *= 10;
                sum += digit;
            }

            n /= 10;
        }

        return ans * sum;
    }
};
