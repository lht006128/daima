#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
  int n, l, r;
  int ans = 0;
  cin >> n;
  for (l = 1; l <= n; l = r + 1)
  {
    r = n / (n / l);
    ans += (r - l + 1) * (n / l);
    cout << "L" << "-" << r << ":" << n / r << endl;
  }
  cout << ans << endl;
  return 0;
}