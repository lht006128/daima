#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[3010];
int vis[3000][3000];
int n, m;

bool dfs(int x, int y)
{
  vis[x][y] = 1;

  if (x == 1 && y == 1)
    return true;

  if (x - 1 >= 1 && s[x - 1][y - 1] == '.' && vis[x - 1][y] == 0)
  {
    if (dfs(x - 1, y))
    {
      cout << "S";
      return true;
    }
  }
  if (y - 1 >= 1 && s[x][y - 2] == '.' && vis[x][y - 1] == 0)
  {
    if (dfs(x, y - 1))
    {
      cout << "D";
      return true;
    }
  }
  return false;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
  }

  dfs(n, m);
}