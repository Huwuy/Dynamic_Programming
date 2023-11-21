#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("caykhe.inp", "r", stdin);
    freopen("caykhe.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int v[n+5], w[n+5];
    int dp[n+5][m+5];
    memset(dp, 0, sizeof(dp));
    vector <int> x;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(w[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][m] << '\n';
    for(int i = n, j = m; i > 0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            cnt++;
            x.push_back(i);
            j -= w[i];
        }
    }
    cout << cnt << " ";
    for(int i = x.size()-1; i >= 0; i--)
        cout << x[i] << " ";
    return 0;
}
