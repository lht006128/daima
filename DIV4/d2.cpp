#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100010];
int n;
bool check(int mid, int m)
{

  for (int i = 2; i <= n; i++)
  {
    int cha = arr[i] - arr[i - 1];
    if (cha > mid)
    {
      int need = static_cast<int>(ceil(cha / mid));
      m -= need;
      if (m < 0)
        return false;
      else
        return true;
    }
    else
    {
      continue;
    }
  }
  return true;
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  int l = 0;
  int r = arr[n] + 1;

  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (check(mid, m + 1))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r + 1;
  return 0;
}