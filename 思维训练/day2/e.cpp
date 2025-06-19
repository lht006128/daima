#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[300110];
vector<int> shu[300010];
int n;
int dp[300010][2]; // 0 最小值，1 是最大值

void dfs(int x, int fa)
{
  dp[x][0] = arr[x];
  dp[x][1] = arr[x];
  if (fa != -1)
  {
    dp[x][0] = min(dp[x][0], arr[x] - dp[fa][1]);
    dp[x][1] = max(dp[x][1], arr[x] - dp[fa][0]);
  }

  for (int i = 0; i < shu[x].size(); i++)
  {
    int j = shu[x][i];
    if (j == fa)
      continue;
    dfs(j, x);
  }
}

void slove()
{

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;

    shu[u].push_back(v);
    shu[v].push_back(u);
  }

  dfs(1, -1);

  for (int i = 1; i <= n; i++)
  {
    cout << dp[i][1] << " ";
  }
  cout << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
    for (int i = 1; i <= n; i++)
    {
      shu[i].clear();
    }
  }
}