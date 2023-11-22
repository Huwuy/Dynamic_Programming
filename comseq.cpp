#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int solve(int m, int n, int a[], int b[])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp[i-1][j] == dp[i][j-1])
                dp[i][j] = dp[i][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[m][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("comseq.inp", "r", stdin);
    freopen("comseq.out", "w", stdout);

    int m, n;
    cin >> m >> n;
    int a[m+5], b[n+5];
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    solve(m, n, a, b);

    return 0;
}
