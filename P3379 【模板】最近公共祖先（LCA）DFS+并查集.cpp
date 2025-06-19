#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int t;
  int xh;
};

vector<int> shu[500010];
vector<Node> que[500010];
int ans[500010];
int vis[500010];
int fa[500010];

void init()
{
  for (int i = 1; i <= 500000; i++)
  {
    fa[i] = i;
  }
}

int find(int x)
{
  if (fa[x] == x)
    return x;
  else
    return fa[x] = find(fa[x]);
}

void merge(int a, int b)
{
  fa[find(a)] = find(b);
}

void dfs(int x, int fa)
{

  for (int i = 0; i < shu[x].size(); i++)
  {
    int j = shu[x][i];
    if (j == fa)
    {
      continue;
    }

    dfs(j, x);

    merge(j, x);
  }
  vis[x] = 1;

  for (int i = 0; i < que[x].size(); i++)
  {
    Node j = que[x][i];
    if (vis[j.t] != 1)
      continue;

    ans[j.xh] = find(j.t);
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, s;
  init();
  cin >> n >> m >> s;

  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    shu[x].push_back(y);
    shu[y].push_back(x);
  }

  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;

    que[a].push_back({b, i});
    que[b].push_back({a, i});
  }

  dfs(s, 0);

  for (int i = 1; i <= m; i++)
  {
    cout << ans[i] << endl;
  }
}