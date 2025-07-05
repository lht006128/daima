#include <bits/stdc++.h>
using namespace std;

vector<int> shu[600010];

int dep[600010];
int fa[600010][30];

void dfs(int x, int pre)
{
  dep[x] = dep[pre] + 1;
  fa[x][0] = pre;

  for (int i = 1; (1 << i) <= dep[x]; i++)
  {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for (int i = 0; i < shu[x].size(); i++)
  {
    int j = shu[x][i];
    if (j == pre)
      continue;
    dfs(j, x);
  }
}

int LCA(int a, int b)
{
  if (dep[a] > dep[b])
  {
    swap(a, b);
  }
  for (int i = dep[b] - dep[a], j = 0; i > 0; i >>= 1, j++)
  {
    if (i & 1)
    {
      b = fa[b][j];
    }
  }
  if (a == b)
    return a; // a 节点就是LCA 的情况 特判
  int k;

  for (k = 0; (1 << k) <= dep[a]; k++)
    ; // 求最多往上多少层

  for (; k >= 0; k--)
  {
    if ((1 << k) <= dep[a] && fa[a][k] != fa[b][k])
    {
      a = fa[a][k], b = fa[b][k];
    }
  }

  return fa[a][0];
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, s;
  cin >> n >> m >> s;

  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    shu[x].push_back(y);
    shu[y].push_back(x);
  }

  dfs(s, 0);

  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << endl;
  }
}