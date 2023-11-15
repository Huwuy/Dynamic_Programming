#include <bits/stdc++.h>

using namespace std;
void solve(int dp[], int a[], int n, int s)
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = s; j >= a[i]; j--)
        {
            if(dp[j-a[i]] == 1)
                dp[j] = 1;
        }
    }
    if(dp[s])
    {
        cout << "YES\n";
        int curSum = s;
        for(int i = n; i > 0; i--)
        {
            if(curSum >= a[i] && dp[curSum-a[i]] == 1)
                cout << i << " ";
                curSum -= a[i];
        }
    }
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ;cout.tie(nullptr);
    freopen("sums.inp","r",stdin);
    freopen("sums.out","w",stdout);

    int n,s;
    cin >> n >> s;
    int a[n+5];
    int dp[n+5];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    solve(dp, a, n, s);
    return 0;
}
