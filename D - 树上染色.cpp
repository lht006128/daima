#include <bits/stdc++.h>
#define int long long
using namespace std;
// 好像是树上背包 板子？

struct Node
{
  int t;
  int w;
};
int cnt[3000];     // 子节点数量
int f[3000][3000]; // dp 状态转移方程
vector<Node> shu[3001];
int n, m;

void dfs(int x, int fa)
{
  // 建树的同时跑DP；
  cnt[x] = 1;
  f[x][0] = 0;
  f[x][1] = 0;
  // cout << x << endl;
  for (int i = 0; i < shu[x].size(); i++)
  {
    Node next = shu[x][i];
    if (next.t == fa)
      continue;

    dfs(next.t, x);
    cnt[x] += cnt[next.t];
    // cout << x << " " << cnt[x] << endl;
    // 这里要先转移 j在转移k
    // 为什么不能直接转移k dp[x][j]=xxx 会楼状态无法转移 j 要从小到大求出来先，不然转移不了。 而且要从大到小，不然会重复转移
    for (int j = min(cnt[x], m); j >= 0; j--)
    {
      //
      for (int k = max((j - cnt[x] + cnt[next.t]), (long long)0); k <= min(j, cnt[next.t]); k++)
      {
        // 过滤掉非法的状态
        // if (f[x][j - k] == -1)
        //   continue;
        // ;

        // j 指当前节点+子节点染黑色数量
        int tot = (long long)(k * (m - k) + (cnt[next.t] - k) * (n - m + k - cnt[next.t]));
        f[x][j] = max(f[x][j], f[x][j - k] + f[next.t][k] + (long long)(tot)*next.w);
      }
    }
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(f, -1, sizeof(f)); // 初始化

  cin >> n >> m; // 读入数据

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    shu[u].push_back({v, w});
    shu[v].push_back({u, w});
  }

  dfs(1, -1); // 跑一遍树这是树形DP的关键

  cout << f[1][m];
}