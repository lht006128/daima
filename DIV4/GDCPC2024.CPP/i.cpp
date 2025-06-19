#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> e[300007];
vector<int> fa[300007];
int val[300007];
int vis[300007];
int flag;

void dfs(int n, int t)
{
  if (!vis[n])
    vis[n]++;
  else
  {
    flag = 1;
    return;
  }
  val[n] += t;
  for (int f : fa[n])
  {
    dfs(f, t);
  }
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  int f, a, b;
  while (m--)
  {
    cin >> f >> a >> b;
    fa[a].push_back(f);
    fa[b].push_back(f);
    if (val[a] == 0)
      val[a] = 1;
    if (val[b] == 0)
      val[b] = 1;
    if (val[f] < val[a] + val[b])
    {
      int t = val[a] + val[b] - val[f];
      val[f] = val[a] + val[b];
      int g = 0;
      for (int d : fa[f])
      {
        memset(vis, 0, sizeof(vis));
        if (g == 0)
        {
          g = d;
        }
        else if (g != d)
        {
          g = d;
          if (!vis[n])
            vis[n]++;
          else
          {
            flag = 1;
            break;
          }
        }
        dfs(d, t);
      }
    }
  }
  if (flag)
  {
    cout << "-1\n";
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += val[i];
  }
  if (sum > 1000000000)
  {
    cout << "-1\n";
    return 0;
  }
  cout << sum;
  return 0;
}