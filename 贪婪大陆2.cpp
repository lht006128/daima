#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> shu[200010];
int a[200010];
int dp[200010];

void dfs(int x, int fa)
{
  dp[x] = a[x];

  for (int i = 0; i < shu[x].size(); i++)
  {
    int j = shu[x][i];
    if (j == fa)
      continue;
    dfs(j, x);
    if (dp[j] >= 0)
    {
      dp[x] += dp[j];
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    shu[a].push_back(b);
    shu[b].push_back(a);
  }
  int root = 0;
  int maxnum = -2147483648;
  for (int i = 1; i <= n; i++)
  {
    if (maxnum < a[i])
    {
      maxnum = a[i];
      root = i;
    }
  }
  dfs(root, -1);

  cout << dp[root];
}