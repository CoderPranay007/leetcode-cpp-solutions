/*
 * LeetCode 3954. Sum of Compatible Numbers in Range I
 * Difficulty: Easy
 * Topics: Dynamic Programming, Bit manipulation
 *
 * Time Complexity: O(k)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int start = (n - k > 1) ? n - k : 1;
        int end = n + k;
        
        int sum = 0;
        for(int i = start; i<=end; i++)
        {
            if((i & n) == 0) sum += i;
        }
        
        return sum;
    }
};
