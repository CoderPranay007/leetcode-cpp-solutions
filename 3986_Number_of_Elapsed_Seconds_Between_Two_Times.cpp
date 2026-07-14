/*
 * LeetCode 3986. Number of Elapsed Seconds Between Two Times
 * Difficulty: Easy
 * Topics: String
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int convert(string s) {
        int seconds = 0;

        string hr = s.substr(0, 2);
        int a = stoi(hr);

        string min = s.substr(3, 2);
        int b = stoi(min);

        string sec = s.substr(6, 2);
        int c = stoi(sec);

        seconds += a * 3600;
        seconds += b * 60;
        seconds += c;

        return seconds;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        int start = convert(startTime);
        int end = convert(endTime);

        return end - start;
    }
};
