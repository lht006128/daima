#include <bits/stdc++.h>
#define int long long
using namespace std;

double calc(int x1, int y1, int x2, int y2)
{
  return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void slove()
{
  int x, y, k;
  cin >> x >> y >> k;

  int ax, ay, bx, by, cx, cy, dx, dy;
  ax = ay = 0;
  by = min(x, y);

  cx = min(x, y);
  cy = 0;

  dx = 0;

  // 移动 dy 和bx
  for (int i = 0; i <= min(x, y); i++)
  {
    bx = i;
    dy = i;

    if (calc(ax, ay, bx, by) >= k && calc(cx, cy, dx, dy) >= k)
    {
      cout << ax << " " << ay << " " << bx << " " << by << endl;
      cout << cx << " " << cy << " " << dx << " " << dy << endl;
      break;
    }
  }
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