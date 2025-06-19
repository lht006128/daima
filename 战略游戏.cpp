#include <bits/stdc++.h>
using namespace std;

vector<int> shu[1501];

int dp[1510][2]; /// 0 不放 1 放

void dfs(int id, int fa)
{
  dp[id][0] = 0;
  dp[id][1] = 1;

  for (int i = 0; i < shu[id].size(); i++)
  {
    int j = shu[id][i];
    if (j == fa)
      continue;

    dfs(j, id);
    dp[id][0] += dp[j][1];
    dp[id][1] += min(dp[j][0], dp[j][1]);
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(), cout.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int u, v, k;
    cin >> u >> k;

    while (k--)
    {
      cin >> v;

      shu[u].push_back(v);
      shu[v].push_back(u);
    }
  }

  dfs(0, -1);

  // for (int i = 0; i <= 3; i++)
  // {
  //   cout << dp[i][0] << " " << dp[i][1] << " " << i << endl;
  // }

  cout << min(dp[0][1], dp[0][0]);
}