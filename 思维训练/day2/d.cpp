#include <bits/stdc++.h>
#define int long long

using namespace std;

void slove()
{
  int n;
  cin >> n;

  int t[n + 10][2];

  for (int i = 1; i <= n; i++)
  {
    cin >> t[i][0] >> t[i][1];
  }
  if (n == 1)
  {
    cout << 1 << endl;
    return;
  }

  multiset<int> sx, sy;

  for (int i = 1; i <= n; i++)
  {
    sx.insert(t[i][0]);
    sy.insert(t[i][1]);
  }

  int res = 1e18;

  res = min(res, (*sx.rbegin() - *sx.begin() + 1) * (*sy.rbegin() - *sy.begin() + 1));

  for (int i = 1; i <= n; i++)
  {
    sx.erase(sx.find(t[i][0]));
    sy.erase(sy.find(t[i][1]));
    int tp = (*sx.rbegin() - *sx.begin() + 1) * (*sy.rbegin() - *sy.begin() + 1);
    if (tp == n - 1)
    {
      tp += min((*sx.rbegin() - *sx.begin() + 1), (*sy.rbegin() - *sy.begin() + 1));
    }
    res = min(res, tp);
    sx.insert(t[i][0]);
    sy.insert(t[i][1]);
  }

  cout << res << endl;
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