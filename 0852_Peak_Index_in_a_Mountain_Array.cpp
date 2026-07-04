/*
 * LeetCode 852. Peak Index in a Mountain Array
 * Difficulty: Medium
 * Topics: Array, Binary Search
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */

class Solution {
public:
    int find(vector<int>& arr, int l, int r) {
        if (l == r) return l;

        int mid = l + (r - l) / 2;

        if (arr[mid] < arr[mid + 1])
            return find(arr, mid + 1, r);
        else
            return find(arr, l, mid);
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        return find(arr, 0, arr.size() - 1);
    }
};
