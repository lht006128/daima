#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // dp[i][j][k]: processed i chars in b, matched j chars in a, balance k
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(m + 2, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j <= n; ++j)
      {
        for (int k = 0; k <= m; ++k)
        {
          if (dp[i][j][k] == 0)
            continue;
          // Try '('
          int new_j = j;
          if (j < n && s[j] == '(')
          {
            new_j = j + 1;
          }
          int new_k = k + 1;
          if (new_k <= m)
          {
            dp[i + 1][new_j][new_k] = (dp[i + 1][new_j][new_k] + dp[i][j][k]) % MOD;
          }
          // Try ')'
          new_j = j;
          if (j < n && s[j] == ')')
          {
            new_j = j + 1;
          }
          new_k = k - 1;
          if (new_k >= 0)
          {
            dp[i + 1][new_j][new_k] = (dp[i + 1][new_j][new_k] + dp[i][j][k]) % MOD;
          }
        }
      }
    }
    cout << dp[m][n][0] % MOD << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}