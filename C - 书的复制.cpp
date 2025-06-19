#include <bits/stdc++.h>
using namespace std;
int a[600];
int sum = 0;
int m, k;

struct Node
{
  int l, r;
};

vector<Node> ans;
bool pd(int mid)
{
  int idx = m;
  for (int i = 1; i <= k; i++)
  {
    int tp = 0;
    while (idx)
    {
      tp += a[idx];
      if (tp > mid)
        break;
      else
        idx--;
    }
  }

  if (idx == 0)
    return true;
  else
    return false;
}
void makeans(int mid)
{
  int idx = m;
  for (int i = 1; i <= k; i++)
  {
    int tp = 0;
    int l = idx, r = -1;
    while (idx)
    {
      tp += a[idx];
      if (tp > mid)
        break;
      else
        idx--;
    }
    r = idx + 1;
    ans.push_back({l, r});
  }
}
int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> m >> k;

  for (int i = 1; i <= m; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  int l = 0, r = sum;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (pd(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  int mintime = r + 1;
  makeans(mintime);

  for (int i = ans.size() - 1; i >= 0; i--)
  {
    cout << ans[i].r << " " << ans[i].l << endl;
  }
}