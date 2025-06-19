#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> shu[100010];
int dp[100010][4]; // 0 关自己加父亲 1 开  2 被儿子点关
int vis[100010];

void dfs(int id)
{
  dp[id][0] = 1; // 关闭父节点
  vis[id] = 1;
  int f = 1;
  int ma = 1e9;
  for (int i = 0; i < shu[id].size(); i++)
  {

    int j = shu[id][i];
    if (vis[j])
      continue;
    dfs(j);

    dp[id][0] += min(dp[j][2], dp[j][1]); //
    dp[id][1] += min(dp[j][1], dp[j][2]); //  点亮自己 儿子节点一定全部被修改了

    dp[id][2] += dp[j][1]; // 被其中一个儿子节点所关闭
    if (ma > dp[j][0] - min(dp[j][1], dp[j][2]))
    {
      ma = dp[j][0] - min(dp[j][1], dp[j][2]);
    }
  }
  if (shu[id].size() > 1 || id == 1)
  {
    dp[id][1] += ma;
  }

  if (shu[id].size() == 1 && id != 1)
  {
    dp[id][1] = 1e9; //
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n;

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    shu[v].push_back(u);
    shu[u].push_back(v);
  }

  dfs(1);

  cout << min(dp[1][2], dp[1][1]);
}