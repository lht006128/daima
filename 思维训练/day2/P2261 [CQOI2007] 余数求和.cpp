#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = n * k;

  for (int l = 1, r; l <= n; l = r + 1)
  {
    if (k / l == 0)
      break;
    r = min(k / (k / l), n); // 这里是怕超过最右边的情况。 得看我们要求的范围。
    ans -= k / l * (r - l + 1) * (l + r) / 2;
  }
  cout << ans << endl;
}