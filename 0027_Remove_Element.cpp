/*
 * LeetCode 27. Remove Element
 * Difficulty: Easy
 * Topics: Array, Two pointers
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
