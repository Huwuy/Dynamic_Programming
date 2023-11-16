#include <bits/stdc++.h>

using namespace std;
void solve(bool dp[], int a[], int n, int s)
{
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = s; j >= a[i]; j--)
        {
            if(dp[j-a[i]] == true)
            {
                dp[j] = true;
            }
        }
    }
    if(dp[s])
    {
        cout << "YES\n";
        int curSum = s;
        for(int i = 1; i <= n; i++)
        {
            if(dp[s-a[i]] && curSum >= a[i]){
                curSum -= a[i];
            cout << i << " ";
            }
        }
    }
    if(!dp[s])
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
    bool dp[n+5];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    solve(dp, a, n, s);
    return 0;
}
