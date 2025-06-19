#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
int b[100010];
map<int, map<int, int>> mp;
int cnt = 0;
void slove()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++)
  {
    cin >> b[i];
  }

  int maxx = -1;
  int curx = 0;
  int lastx = -1;

  for (int i = 1; i <= m; i++)
  {
    if (b[i] != lastx)
    {
      lastx = b[i];
      curx = 1;
    }
    else
    {
      curx++;
    }

    maxx = max(curx, maxx);
  }

  int cntx = 0;
  lastx = -1;
  for (int i = 1; i <= m; i++)
  {
    if (b[i] != lastx)
    {
      lastx = b[i];
      curx = 1;
    }
    else
    {
      curx++;
    }
    if (curx == maxx)
    {
      cntx++;
    }
  }

  int maxy = -1;
  int cury = 0;
  int lasty = -1;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] != lasty)
    {
      lasty = a[i];
      cury = 1;
    }
    else
    {
      cury++;
    }

    maxy = max(cury, maxy);
  }
  int cnty = 0;
  lasty = -1;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] != lasty)
    {
      lasty = a[i];
      cury = 1;
    }
    else
    {
      cury++;
    }
    if (cury == maxy)
    {
      cnty++;
    }
  }

  cout << maxx * maxy << " " << cntx * cnty << endl;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    slove();
  }
}