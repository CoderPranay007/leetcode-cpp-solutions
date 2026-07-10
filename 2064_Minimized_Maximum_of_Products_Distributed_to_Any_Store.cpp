/*
 * LeetCode 2064. Minimized Maximum of Products Distributed to Any Store
 * Difficulty: Medium
 * Topics: Array, Binary Search, Greedy
 *
 * Time Complexity: O(m log M)
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool canDistribute(vector<int>& quantities, int n, int k) {
        long long stores = 0;

        for (int q : quantities) {
            stores += (q + k - 1) / k;

            if (stores > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canDistribute(quantities, n, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
