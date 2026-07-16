/*
 * LeetCode 2550. Count Collisions of Monkeys on a Polygon
 * Difficulty: Medium
 * Topics: Math, Recursion
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int monkeyMove(int n) {
        long long mod = 1000000007;
        long long ans = 1;
        long long base = 2;

        while (n > 0) {
            if (n & 1)
                ans = (ans * base) % mod;

            base = (base * base) % mod;
            n >>= 1;
        }

        return (ans - 2 + mod) % mod;
    }
};
