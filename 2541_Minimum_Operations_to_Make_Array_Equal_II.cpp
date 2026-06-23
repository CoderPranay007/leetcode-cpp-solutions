/*
 * LeetCode 2541. Minimum Operations to Make Array Equal II
 * Difficulty: Medium
 * Topics: Array, Greedy, Math
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if(k == 0) return nums1 == nums2 ? 0 : -1; 

        long long sumofdiff = 0;
        long long ops = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = (long long)nums1[i] - nums2[i];

            if (d % k != 0) return -1;

            sumofdiff += d;

            if (d > 0) ops += d / k;
        }

        return sumofdiff == 0 ? ops : -1;
    }
};
