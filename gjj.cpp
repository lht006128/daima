#include <bits/stdc++.h>
using namespace std;
// 女生从 1~ n 男生 从 n ~ 2n
// int a[5000];
int fa[5000];
int gir[510][510];
int man[510][510];
int n, m, k, f;
void init()
{
  for (int i = 1; i <= 2 * n; i++)
  {
    fa[i] = i;
  }
}

int ans = 1e6;

int find(int a)
{
  if (fa[a] == a)
    return a;
  else
    return fa[a] = find(fa[a]);
}

void join(int a, int b)
{
  gir[a][b] = 1;
}
void join2(int a, int b)
{
  for (int i = n + 1; i <= 2 * n; i++)
  {
    gir[a][i] |= gir[b][i];
    gir[b][i] |= gir[a][i];
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m >> k >> f;
  init();

  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    join(a, n + b);
  }

  for (int i = 1; i <= f; i++)
  {
    int a, b;
    cin >> a >> b;
    join2(a, b);
  }

  for (int i = 1; i <= n; i++)
  {
    int cnt = k;

    for (int j = n + 1; j <= 2 * n; j++)
    {
      if (gir[i][j] == 1)
      {
        cnt++;
      }
    }
    // cout << cnt << endl;
    ans = min(ans, cnt);
  }
  if (ans > n)
    ans = n;
  cout << ans;
}