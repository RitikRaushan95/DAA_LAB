#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;


int matrixChainMultiplication(vector<int> &dims) {
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));


    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int longestCommonSubsequence(string &s1, string &s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
     vector<int> dims = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplications in Matrix Chain Multiplication: "
         << matrixChainMultiplication(dims) << endl;

    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "Length of Longest Common Subsequence: "
         << longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
