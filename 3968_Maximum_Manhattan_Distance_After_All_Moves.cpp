/*
 * LeetCode 3968. Maximum Manhattan Distance After All Moves
 * Difficulty: Medium
 * Topics: String, Greedy, Counting
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxDistance(string moves) {
        int hash[4] = {0};

        int n = moves.size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(moves[i] == 'U') hash[0]++;
            else if(moves[i] == 'D') hash[1]++;
            else if(moves[i] == 'R') hash[2]++;
            else if(moves[i] == 'L') hash[3]++;
            else {
                ans++;
            }
        }

        return abs(hash[0] - hash[1]) + abs(hash[2] - hash[3]) + ans;
    }
};
