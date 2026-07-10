/*
 * LeetCode 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Topics: Array, Binary Search, Divide and Conquer
 *
 * Time Complexity: O(log n + log m + (n + m))
 * Space Complexity: O(1)
 */

class Solution {
public:
    int lowerBound(vector<int>& arr, double x) {
        int l = 0, r = arr.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    double median(vector<int>& arr) {
        int n = arr.size();

        if (n & 1)
            return arr[n / 2];

        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        if (n == 0) {
            return median(nums2);
        }

        if (m == 0) {
            return median(nums1);
        }

        double med1 = median(nums1);
        double med2 = median(nums2);

        int i, j, count;

        if (med1 <= med2) {

            i = (n & 1) ? n / 2 : n / 2 - 1;
            j = lowerBound(nums2, nums1[i]);

            count = i + j;

        } else {

            j = (m & 1) ? m / 2 : m / 2 - 1;
            i = lowerBound(nums1, nums2[j]);

            count = i + j;
        }

        int target = (n + m) / 2;

        int prev = -1, curr = -1;

        while (count <= target) {

            prev = curr;

            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else if (j < m) {
                curr = nums2[j++];
            } else {
                break;
            }

            count++;
        }

        if ((n + m) & 1)
            return curr;

        return (prev + curr) / 2.0;
    }
};
