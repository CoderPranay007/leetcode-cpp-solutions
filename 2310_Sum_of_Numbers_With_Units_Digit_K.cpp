/*
 * LeetCode 2310. Sum of Numbers With Units Digit K
 * Difficulty: Medium
 * Topics: Math, Enumeration
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        if (num == 0) return 0;
        if (num % 2 != 0 && k % 2 == 0) return -1;

        vector<vector<int>> digits;

        digits.push_back({0});
        digits.push_back({1,2,3,4,5,6,7,8,9,0});
        digits.push_back({2,4,6,8,0});
        digits.push_back({3,6,9,2,5,8,1,4,7,0});
        digits.push_back({4,8,2,6,0});
        digits.push_back({5,0});
        digits.push_back({6,2,8,4,0});
        digits.push_back({7,4,1,8,5,2,9,6,3,0});
        digits.push_back({8,6,4,2,0});
        digits.push_back({9,8,7,6,5,4,3,2,1,0});
        
        int unit_digit = num % 10;

        for(int i = 0; i < digits[k].size(); i++) {
            if(digits[k][i] == unit_digit && num >= k * (i + 1))
                return i + 1;
        }

        return -1;
    }
};
