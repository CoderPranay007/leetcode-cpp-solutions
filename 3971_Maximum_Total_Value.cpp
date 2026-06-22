/*
 * LeetCode 3971. Maximum Total Value
 * Difficulty: Hard
 * Topics: Array, Binary Search, Greedy, Math, Heap (Priority Queue)
 *
 * Time Complexity: O(n log M)
 * Space Complexity: O(1)
 */

class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long countGE(vector<int>& value, vector<int>& decay, long long T) {
        long long cnt = 0;

        for (int i = 0; i < value.size(); i++) {
            long long v = value[i];
            long long d = decay[i];

            long long need = max(1LL, T);

            if (v < need) continue;

            cnt += (v - need) / d + 1;
        }

        return cnt;
    }

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long totalPositive = countGE(value, decay, 1);

        if (totalPositive <= m) {
            long long ans = 0;

            for (int i = 0; i < value.size(); i++) {
                long long v = value[i];
                long long d = decay[i];

                long long k = (v - 1) / d + 1;

                __int128 sum =
                    (__int128)k * v -
                    (__int128)d * k * (k - 1) / 2;

                ans = (ans + (long long)(sum % MOD)) % MOD;
            }

            return (int)ans;
        }

        long long lo = 1, hi = 1e9;

        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;

            if (countGE(value, decay, mid) >= m)
                lo = mid;
            else
                hi = mid - 1;
        }

        long long T = lo;

        long long picked = 0;
        long long ans = 0;

        for (int i = 0; i < value.size(); i++) {
            long long v = value[i];
            long long d = decay[i];

            long long k = 0;

            if (v > T)
                k = (v - (T + 1)) / d + 1;

            picked += k;

            __int128 sum =
                (__int128)k * v -
                (__int128)d * k * (k - 1) / 2;

            ans = (ans + (long long)(sum % MOD)) % MOD;
        }

        ans = (ans + ((m - picked) % MOD) * (T % MOD)) % MOD;

        return (int)ans;
    }
};
