#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  if (n <= 2)
  {
    cout << -1;
    return 0;
  }

  cout << 1 << " ";

  for (int i = n; i > 1; i--)
  {
    cout << i << " ";
  }
}