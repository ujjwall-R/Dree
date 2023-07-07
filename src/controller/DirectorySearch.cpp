#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "DirectorySearch.h"

using namespace std;

DirectorySearch::DirectorySearch(int searchDepth)
{
    this->searchDepth = searchDepth;
}

int DirectorySearch::LevenshteinDistance(const string &s1, const string &s2)
{
    const int m = s1.length();
    const int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    return dp[m][n];
}