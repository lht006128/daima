#include <bits/stdc++.h>
using namespace std;

vector<int> mp[320];
int cor[320];
int h[320];
int vis[320];
int pos = 1;

void dfs(int id, int fa)
{
  cor[id] = 1;
  vis[id] = 1;
  for (int i = 0; i < mp[id].size(); i++)
  {
    int j = mp[id][i];
    if (vis[j])
      continue;
    if (h[id] <= h[j])
      continue;

    dfs(j, id);
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> h[i];
    if (h[i] > h[pos])
    {
      pos = i;
    }
  }

  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    mp[v].push_back(u);
    mp[u].push_back(v);
  }

  dfs(pos, 360);

  for (int i = 1; i <= n; i++)
  {
    if (cor[i] != 1)
    {
      cout << "Non";
      return 0;
    }
  }
  cout << "Oui, j'ai trouve la solution." << endl;
  cout << pos;

  return 0;
}