/*
 * LeetCode 3955. Valid Binary Strings With Cost Limit
 * Difficulty: Medium
 * Topics: String, Bit manipulation
 *
 * Time Complexity: O(n.2^n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
    vector<string> result;

    for (int i = 0; i < (1 << n); i++) {
        string s;
        bool a = true;

        for (int j = n - 1; j >= 0; j--) {
            if (i & (1 << j))
                s += '1';
            else
                s += '0';
        }
        
        for(int i=0; i+1<n; i++){
            if(s[i] == '1' && s[i+1] == '1'){
                a = false;
                break;
            }
        }
        
        int sum = 0;
        if(a) {
            for(int i=0; i<n; i++) {
                    if(s[i] == '1') sum +=i;
                }

            if(sum <=k) result.push_back(s);
        }
        }
        return result;
    }
};
