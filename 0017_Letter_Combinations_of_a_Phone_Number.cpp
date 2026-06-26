/*
 * LeetCode 17. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Topics: Hash Table, String, Backtracking
 *
 * Time Complexity: O(4ⁿ × n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<string> ans;

    void solve(string digits, int index, string current, string mapping[]) {

        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            current += ch;

            solve(digits, index + 1, current, mapping);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        string mapping[10];

        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(digits, 0, "", mapping);

        return ans;
    }
};
