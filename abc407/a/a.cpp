#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a, b;
  cin >> a >> b;
  double ans = a * 1.0 / b;
  int ans1 = ceil(ans);
  int ans2 = floor(ans);

  if (ans1 - ans > ans - ans2)
  {
    cout << ans2 << endl;
  }
  else
  {
    cout << ans1 << endl;
  }
}