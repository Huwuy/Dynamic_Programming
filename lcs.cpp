#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

string find_LCS(string s1, string s2)
{
    memset(dp, 0, sizeof(dp));

     for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string res = "";
    int i = s1.length(), j = s2.length();
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            res = s1[i-1] + res;
            cout << i << " ";
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("lcs.inp", "r", stdin);
    freopen("lcs.out", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    cout << find_LCS(s1, s2);
    return 0;
}
