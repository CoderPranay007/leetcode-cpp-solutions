/*
 * LeetCode 1732. Find the Highest Altitude
 * Difficulty: Easy
 * Topics: Array, Prefix Sum
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int current = 0;
        
        for(int i=0; i<gain.size(); i++) {

            current += gain[i];
            if(current > alt) alt = current;
        }

        return alt;
    }
};
