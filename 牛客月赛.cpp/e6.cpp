#include <bits/stdc++.h>
using namespace std;
int g[600][600];

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans1 = 0;
  int ans2 = 0;

  for (int i = 1; i <= m - 1; i++)
  {
    g[1][i] = i;
    ans1 ^= i;
  }

  for (int i = 2; i <= n; i++)
  {
    g[i][m] = m + i - 1;
    ans2 ^= (m + i - 1);
  }

  if ((ans1 ^ ans2 ^ m ^ (n + m)) != 0)
  {
    cout << -1;
  }
  else
  {
    g[1][m] = ans1 ^ m;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        cout << g[i][j] << " ";
      }
      cout << endl;
    }
  }
}