#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int solve(int n, int m, int w[], int v[])
{
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
            if(j >= w[i])
                dp[i][j] = max(dp[i][j-w[i]] + v[i], dp[i-1][j]);
        else
            dp[i][j] = dp[i-1][j];
    }
/*    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
*/
    cout << dp[n][m] << endl;
}


void find_num(int n, int m, int w[]) {
    vector<int> v;
    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            v.push_back(i);
            j -= w[i];
        } else {
            i--;
        }
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++)
    {
        int cnt = 1;
        if(v[i] == v[i-1])
        {
            cnt++;
        }
        cout << v[i] << " " << cnt << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("valy.inp", "r", stdin);
    freopen("valy.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int v[n+5], w[n+5];
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    solve(n, m, w, v);
    find_num(n, m, w);
    return 0;
}
