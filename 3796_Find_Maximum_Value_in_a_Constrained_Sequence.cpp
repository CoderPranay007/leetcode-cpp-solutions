/*
 * LeetCode 3796. Find Maximum Value in a Constrained Sequence
 * Difficulty: Medium
 * Topics: Array, Dynamic Programming, Greedy
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {

        vector<int> range(n, INT_MAX);
 
        range[0] = 0;

        int m = restrictions.size();

        for(int i=0; i<m; i++) {

            int idx = restrictions[i][0];
            int mx = restrictions[i][1];

            range[idx] = min(range[idx], mx);
        }
        
        for(int i = 1; i < n; i++) {
            range[i] = min(range[i], range[i - 1] + diff[i - 1]);
        }
        
        int ans = 0;

        for(int i = n - 2; i >= 0; i--) {
            range[i] = min(range[i], range[i + 1] + diff[i]);

            ans = max(ans, range[i]);
        }
         
        return max(ans, range[n - 1]);
    }
};
