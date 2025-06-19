#include <bits/stdc++.h>
#define int long long
using namespace std;
int b[300010];
int a[300011];
int sum[300100];
int s[300100];
signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= m; i++)
  {
    int tp;
    cin >> tp;
    b[tp]++;
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = (sum[i - 1] + a[i]) % k;
    if (b[i])
      s[sum[i]]++;
  }
  int ans = 0;
  int tp = 0;
  for (int i = 1; i <= n + 1; i++)
  {
    if (b[i])
      s[sum[i]]--;
    ans = max(ans, tp + s[a[i] % k]);
    if (!sum[i] && b[i])
      tp++;
  }
  cout << ans;
  return 0;
}