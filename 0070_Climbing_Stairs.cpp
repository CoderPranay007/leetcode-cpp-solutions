/*
 * LeetCode 70. Climbing Stairs
 * Difficulty: Easy
 * Topics: Math, Dynamic Programming
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1; 
        int prev1 = 1; 

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

OR

/*
 * LeetCode 70. Climbing Stairs
 * Difficulty: Easy
 * Topics: Math, Combinatorics
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long nCr(int n, int r) {
        r = min(r, n - r);

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        return res;
    }

    int climbStairs(int n) {
        int steps = n / 2 + 1;
        long long sum = 0;
        int count1 = n;

        while (steps > 0) {
            sum += nCr(n, count1);

            count1 -= 2;
            steps--;
            n--;
        }

        return (int)sum;
    }
};
