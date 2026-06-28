/*
 * LeetCode 1846. Maximum Element After Decreasing and Rearranging
 * Difficulty: Medium
 * Topics: Array, Greedy, Sorting
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.begin() + n);

        arr[0] = 1;

        for(int i = 0; i + 1 < n; i++)
            if(arr[i + 1] - arr[i] > 1)
                arr[i + 1] = arr[i] + 1;

        return arr[n - 1];
    }
};
